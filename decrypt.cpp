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

    fstream prv(key,ios_base::in), encry(infile,ios_base::in),decry(outfile,ios_base::out);

    string d;
    string n;

    prv>>d;

    prv>>n;

    ReallyLongInt d1=ReallyLongInt(d);
    ReallyLongInt n1=ReallyLongInt(n);

    string x;

    while(!encry.eof())
    {
        encry>>x;
        ReallyLongInt x1=ReallyLongInt(x);
        ReallyLongInt thing=modPower(x1,d1,n1);
        decry<<(char) thing.toLongLong();
    }
}