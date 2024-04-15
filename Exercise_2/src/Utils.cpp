#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

istringstream reading(ifstream& input, string& line)
{
    getline(input,line);
    istringstream conversion(line);
    return conversion;
}

ofstream& print_vec(ofstream& output, unsigned int n, double*& ptr)
{
    output << "[ ";
    for (unsigned int k=0; k<n; k++ )
    {
        output << ptr[k] << " ";
    }
    output << "]";
    return output;
}

double final_value(unsigned int n, double S, double*& ptrR, double*& ptrW )
{
    double V = 0;
    for (unsigned int k=0; k<n; k++ )
    {
        V += (1 + ptrR[k])*ptrW[k]*S;
    }
    return V;
}
