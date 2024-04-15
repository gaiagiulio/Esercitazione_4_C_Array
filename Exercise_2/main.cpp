#include "Utils.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("data.csv"); // file in lettura
    if (input.fail())
    {
        cerr << "Error while opening 'data.csv' " << endl;
        return 1;
    }

    string line;
    char c;

    double S;
    reading(input, line) >> c >> c >> S ;

    unsigned int n;
    reading(input, line) >> c >> c >> n ;

    getline(input,line); // ignora riga w;r

    double *ptrW= new double[n];
    double *ptrR= new double[n];

    for (unsigned int k=0; k<n; k++ )
    {
        reading(input, line) >> ptrW[k] >> c >> ptrR[k] ;
    }

    input.close(); // fine lettura

    double V = final_value(n, S, ptrR, ptrW);
    double r = V/S -1;

    ofstream output("result.txt"); // file in scrittura

    output.precision(2);
    output << "S = "<< fixed << S << ", n = " << n << endl;
    output << "w = ";
    print_vec(output, n, ptrW) << endl;
    output << "r = ";
    print_vec(output, n, ptrR) << endl;
    output.precision(4);
    output << "Rate of return of the portfolio: " << r << endl;
    output.precision(2);
    output << "V: " << V << endl;

    output.close(); // fine scrittura

    // stampa a video
    ifstream print("result.txt");
    if (print.fail())
    {
        cerr << "Error while opening 'result.txt' " << endl;
        return 1;
    }

    while (!print.eof())
    {
        getline(print,line);
        cout << line << endl;
    }

    print.close();

    delete [] ptrW;
    delete [] ptrR;

    return 0;
}

