#include <fstream>
#include <iostream>
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


using namespace std;

int main(int argc, char** argv)
{
    //argv[0] doesnt contain a relevant file name
    string key=argv[1];
    string infile=argv[2];
    string outfile=argv[3];

    fstream pub(key,ios_base::in), plain(infile,ios_base::in),encry(outfile,ios_base::out);

    string e;
    string n;

    pub>>e;
    pub>>n;

    ReallyLongInt e1=ReallyLongInt(e);
    ReallyLongInt n1=ReallyLongInt(n);

    char x;

    while(plain.get(x))
    {
        ReallyLongInt x1=ReallyLongInt(int(x));

        ReallyLongInt whateves=modPower(x1,e1,n1);

        encry<<endl<<whateves;
    }
}