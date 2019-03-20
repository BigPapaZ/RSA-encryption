#include <iostream>
#include <string>

using namespace std;

template <class T>
T modPower(const T& base,const T& exponent,const T& modulus)
{
    if (exponent==0){return 1;}
    if (exponent==1){return base%modulus;}

    T answer=modPower(base,exponent/2,modulus)%modulus;

    if(exponent%2==0)   {return (answer*answer)%modulus;}
    else{return ((((base%modulus)*answer)%modulus)*answer)%modulus;}
}


template <class T>
bool isPrime(const T& num)
{
    if(num==0||num==1) return 0;
    if(num==2) return 1;
    T sq_rt=num/2;//what about the type??????
    for(unsigned int i=2; i<=sq_rt; i++)
    {
        if(num%i==0) return 0;
    }
    return 1;
}

template <class T>
T extendedEuclid(const T& a,const T& b,T* x,T* y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        
        return a;
    }

    T d=extendedEuclid(b,a%b, x, y);

    T x_dash=*y;
    T y_dash=*x - *y * (a/b);

    *x=x_dash;
    *y=y_dash;


    return d;
}