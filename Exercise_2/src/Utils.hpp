#ifndef __Utils__H
#define __Utils__H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Funzione per leggere da file in input una riga e convertila a stringa di stream da cui prelevare i dati
istringstream reading(ifstream &input, string &line);

// Funzione per stampare un array su file
ofstream& print_vec(ofstream &output, unsigned int n, double* &ptr);

//Funzione per calcolare il valore finale del portfolio
double final_value(unsigned int n, double S, double* &ptrR, double* &ptrW );

#endif
