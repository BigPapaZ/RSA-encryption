#include "numberTheory.hpp"
#include <fstream>
#include <iostream>
#include "ReallyLongInt.hpp"


using namespace std;

int main(int argc, char** argv)
{
    ReallyLongInt p=ReallyLongInt(argv[1]);

    ReallyLongInt q=ReallyLongInt(argv[2]);

    string pblc=argv[3];
    string prv=argv[4];

    fstream pub(pblc,ios_base::out), prvi(prv,ios_base::out);

    if(p<=100000 && q<=100000)
    {
        if (!isPrime(p)||!isPrime(q))
        {
            cout<<"Atleast one of the inputs isnt a prime"<<endl;
            return 1;
        }
    }
    
    else{cout<<"Primality is not being verified...."<<endl;}

    ReallyLongInt n=p*q;

    ReallyLongInt t=(p-1)*(q-1);

    ReallyLongInt px;
    ReallyLongInt py;

    int tracker=0;
    ReallyLongInt e=ReallyLongInt(2);

    while(e<t && tracker==int(0))
    {
        ReallyLongInt gcd=extendedEuclid(e,t, &px, &py);//relatively prime
        if(gcd==1)
        {
            //relatively prime
            if(px<0){px+=t;}
            pub<<e<<" "<<n<<endl;
            prvi<<px<<" "<<n<<endl;
            tracker=1;
        }
        e++;
    }
    
}