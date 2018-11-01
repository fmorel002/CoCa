#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphtriangle.c"
#include <vector>


using namespace std;
const string filename = "graphToSat.txt";
const char * graphFile = "graph.dot";
const char * generateGraphFileName = "graph.png";
string buffer;
int nbClauses;
int edgeToColor[numbSommet][2];

void addToFile(string data)
{
    ofstream myfile;
    myfile.open(filename, ios::trunc);
    myfile << data;
    myfile.close();
}

void generateGraph()
{
    ofstream myfile;
    myfile.open(graphFile, ios::trunc);
    string data ="graph {\n";

    for(int i = 0; i < orderG(); i++)
    {
        for(int j = i; j < orderG(); j++)
        {
            if(are_adjacent(i, j))
                data += to_string(i) + " -- " + to_string(j) + ";\n";
        }
    }

    data += "}";
    myfile << data;
    myfile.close();
}

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

// Chaque sommet a un premier voisin et un deuxième voisin
// FONCTIONNELLE
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

// Premier voisin different du deuxième voisin
// VRAISEMBLABLEMENT INUTILE
// CAR VERIFIER PAR CNF PRECEDENTE (A VERIFIER)
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
// SEMI-FONCTIONNEL
//Répond juste sur Chvatal (12sommets), n'a pas de triangles.
//void cnf_allInTriangle()
//{
//    for(int i = 0; i < orderG(); i++)
//    {
//        for(int j = 0; j < orderG(); j++)
//        {
//            if(i!= j && are_adjacent(i,j))
//            {
//                for(int k = 0; k < orderG(); k++)
//                {
//                    if(k != j && k != i && are_adjacent(i, k) && are_adjacent(j,k))
//                    {
//                        buffer += to_string(i+1) + " " + to_string(j+1) + " " + to_string(k+1) + " 0\n";
//                        nbClauses++;
//                    }
//                    else
//                    {
//                        buffer += to_string(i+1) + to_string(j+1) + " -" + to_string(k+1) + " 0\n";
//                        nbClauses++;
//                    }
//                }
//            }

//        }
//    }
//}

//TEST
void cnf_allInTriangle()
{
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
    cnf_neighboursOneAndTwo();
    //    cnf_differentNeighbours();
    cnf_allInTriangle();
    addToFile("p cnf " + to_string(orderG()) + " " + to_string(nbClauses) + "\n" + buffer);
    generateColoredGraph();
}
