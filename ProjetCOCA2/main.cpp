#include <iostream>
#include "C10.c"
#include <fstream>



using namespace std;
const string filename = "graphToSat.txt";

void addToFile(string data)
{
    ofstream myfile;
    myfile.open(filename, ios::app);
    myfile << data+ '\n';
    myfile.close();
}

void clearFile()
{
    ofstream myfile;
    myfile.open(filename, ios::trunc);
    myfile.close();
}

int main(int argc, char *argv[])
{
    addToFile("test2");
    clearFile();
}
