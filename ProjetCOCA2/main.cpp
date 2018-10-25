#include <iostream>
#include "graphtriangle.c"
#include <fstream>
#include <string>

using namespace std;
const string filename = "graphToSat.txt";
string buffer;
int nbClauses;

void addToFile(string data)
{
    ofstream myfile;
    myfile.open(filename, ios::app);
    myfile << data;
    myfile.close();
}

void clearFile()
{
    ofstream myfile;
    myfile.open(filename, ios::trunc);
    myfile.close();
}
//void cnf_neighboursOneAndTwo()
//{
//    buffer +="c Start cnf_neighboursOneAndTwo\n";
//    for(int i = 0; i < orderG(); i++)
//    {
//        for(int j = 0; j < orderG(); j++)
//        {
//            if(i != j && are_adjacent(i,j))
//            {
//                buffer += "-" + to_string(i+1) + " " + to_string(j+1) + " 0\n";
//                buffer += to_string(i+1) + " -" + to_string(j+1) + " 0\n";
//                buffer += "-" + to_string(j+1) + " " + to_string(i+1) + " 0\n";
//                buffer += to_string(j+1) + " -" + to_string(i+1) + " 0\n";
//                nbClauses+=4;
//            }
//        }
//    }
//}

// Chaque sommet a un premier voisin et un deuxième voisin
void cnf_neighboursOneAndTwo()
{
    buffer +="c Start cnf_neighboursOneAndTwo\n";
    for(int i = 0; i < orderG(); i++)
    {
        buffer += to_string(i+1) + " 0\n";
        nbClauses++;
        for(int j = 0; j < orderG(); j++)
        {
           if(i!=j)
           {
               buffer += to_string(j+1) + " ";
           }
        }
        buffer += "0\n";
        nbClauses++;

        for(int j = 0; j < orderG(); j++)
        {
           if(i!=j)
           {
                buffer += "-" + to_string(j+1) + " ";
               for(int k = 0; k < orderG(); k++)
               {
                   if(k != j && k != i)
                        buffer +=to_string(k+1) + " ";
               }
               buffer += "0\n";
               nbClauses++;
           }
        }


    }
}
// Premier voisin different du deuxième voisin
void cnf_differentNeighbours()
{
    buffer +="c Start cnf_differentNeighbours\n";
    for(int i = 0; i < orderG(); i++)
    {
        for(int j = 0; j < orderG(); j++)
        {
            if(i != j && are_adjacent(i, j))
            {
                buffer += "-" + to_string(i+1) + " -" + to_string(j+1) + " 0\n";
                nbClauses++;
            }
        }
    }
}

// Tous les sommets sont dans un triangle
void cnf_allInTriangle()
{
    buffer +="c Start cnf_allInTriangle\n";
    for(int i = 0; i < orderG(); i++)
    {
        for(int j = 0; j < orderG(); j++)
        {
            if(i != j && are_adjacent(i, j))
            {
                buffer += to_string(i+1) + " " + to_string(j+1) + " ";
            }
        }
        buffer +="0\n";
        nbClauses++;
    }
}

int main(int argc, char *argv[])
{
    clearFile();
    cnf_neighboursOneAndTwo();
//    cnf_differentNeighbours();
//    cnf_allInTriangle();
    addToFile("p cnf " + to_string(orderG()) + " " + to_string(nbClauses) + "\n" + buffer);
}


// pensez a regarder les arrêtes parceque les sommets c'est cool mais les triangles c'est pas que des points :)
