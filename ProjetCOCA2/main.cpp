#include <fstream>
#include "graphtriangle.c"

using namespace std;

// Nom du fichier généré par la réduction SAT
const string filename = "graphToSat.txt";
const char * graphFile = "graph.dot";

string buffer;
int nbClauses;
int edgeToColor[numbSommet][2];

// Vide le fichier et le rempli avec 'data'
void addToFile(string data)
{
    ofstream myfile;
    myfile.open(filename, ios::trunc);
    myfile << data;
    myfile.close();
}

// Génère un graph au format .dot avec une coloration
// rouge pour les arrêtes étant partition d'un triangle
void generateColoredGraph()
{
    ofstream myfile;
    myfile.open(graphFile, ios::trunc);
    string data ="graph {\n";
    string colorRed = "red";
    string colorString = "[color=" + colorRed + "]";

    for(int i = 0; i < orderG(); i++)
    {
        for(int j = i; j < orderG(); j++)
        {
            if(are_adjacent(i, j) && (edgeToColor[i][0] == j || edgeToColor[i][1] == j)){
                data += to_string(i) + " -- " + to_string(j) + " " + colorString + ";\n";
            }
            else if(are_adjacent(i, j))
            {
                data += to_string(i) + " -- " + to_string(j) + ";\n";
            }
        }
    }

    data += "}";
    myfile << data;
    myfile.close();
}

// Codage de forumule SAT
// Chaque sommet a un premier voisin et un deuxième voisin et ils sont différent
void cnf_neighboursOneAndTwo()
{
    buffer +="c Start cnf_neighboursOneAndTwo\n";
    for(int i = 0; i < orderG(); i++)
    {
        buffer += to_string(i+1) + " 0\n";
        nbClauses++;
        for(int j = 0; j < orderG(); j++)
        {
            if(i!=j && are_adjacent(i,j))
            {
                buffer += to_string(j+1) + " ";
            }
        }
        buffer += "0\n";
        nbClauses++;

        for(int j = 0; j < orderG(); j++)
        {
            if(i != j)
            {
                buffer += "-" + to_string(j+1) + " ";
                for(int k = 0; k < orderG(); k++)
                {
                    if(k != j && k != i && are_adjacent(i,k))
                        buffer += to_string(k+1) + " ";
                }
                buffer += "0\n";
                nbClauses++;
            }
        }
    }
}

// Codage formule SAT
// Tous les sommets du graph sont dans un triangle
// et chaque triangle est distinct
void cnf_allInTriangle()
{
    if(orderG() % 3 != 0)
    {
        buffer += to_string(orderG() +1) + " 0\n";
        buffer += "-" +to_string(orderG() +1) + " 0\n";
    }

    buffer += "c AllInTriangle \n";
    for(int i = 0; i < orderG(); i++)
    {
        for(int j = 0; j < orderG(); j++)
        {
            if(i != j && are_adjacent(i,j))
            {
                for(int k = 0; k < orderG(); k++)
                {
                    if(k != j && k != i && are_adjacent(i, k) && are_adjacent(j,k))
                    {
                        buffer += to_string(orderG() + i+1) + " " + to_string(orderG() + j+1) + " " + to_string(orderG() + k+1) + " 0\n";
                        nbClauses++;

                        edgeToColor[i][0] = j;
                        edgeToColor[i][1] = k;
                        edgeToColor[j][0] = i;
                        edgeToColor[j][1] = k;

                        k = orderG();
                        j = orderG();
                    }
                    else if (k != j && k != i)
                    {
                        buffer += to_string(orderG() + i+1) + " " + to_string(orderG() + j+1) + " 0\n";
                        buffer += "-" + to_string(orderG() + i+1) + " -" + to_string(orderG() + j+1) + " -" + to_string(orderG() + k+1) + " 0\n";
                        nbClauses += 2;
                    }
                }
            }

        }
    }
}


int main()
{
    // On lance la transformation SAT
    cnf_neighboursOneAndTwo();
    cnf_allInTriangle();

    // On généère le fichier en lui passant en paramètre
    // l'entête DIMACS avec :
    // orderG() * 2 sommets car on a OrderG() variables par formule
    addToFile("p cnf " + to_string(orderG()*2) + " " + to_string(nbClauses) + "\n" + buffer);

    // Enfin on génère le graph associé
    generateColoredGraph();
}
