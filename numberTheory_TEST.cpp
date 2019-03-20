#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


TEST_CASE("Tests")
{
    SECTION("modPower")
    {
        REQUIRE(modPower(2ull,2ull,3ull)==1);

        REQUIRE(modPower(2ull,3ull,3ull)==2);

        REQUIRE(modPower(12ull,12ull,123ull)==66);
        
        REQUIRE(modPower(10ull,19ull,1019ull)==776);
        
        REQUIRE(modPower(12345ull,1234567ull,123ull)==66);
        
       
        REQUIRE(modPower(12345ull,123456789ull,12345ull)==0);
        
        REQUIRE(modPower(1ull,2ull,3ull)==1);//for base case 1
        
        REQUIRE(modPower(10ull,0ull,3ull)==1);//for power 0

        REQUIRE(modPower(3ull,1ull,5ull)==3);//for power 1=
        
        REQUIRE(modPower(3ull,1ull,1ull)==0);//for base 1=

        ReallyLongInt x=ReallyLongInt(12345);
        ReallyLongInt y=ReallyLongInt("123456789");
        ReallyLongInt z=ReallyLongInt("1234567891011");
        ReallyLongInt b=modPower(x,y,z);

        REQUIRE(b.toString()=="519170861217");

        REQUIRE(modPower(12345ull,1234567ull,123456789ull)==100842075ull);
    }

    SECTION("isPrime")
    {
        REQUIRE(isPrime(0ull)==0);

        REQUIRE(isPrime(1ull)==0);

        REQUIRE(isPrime(2ull)==1);
        REQUIRE(isPrime(73ull)==1);
        REQUIRE(isPrime(100ull)==0);
        REQUIRE(isPrime(99ull)==0);
        REQUIRE(isPrime(10ull)==0);
    }

    SECTION("extendedEuclid")
    {//need to figure out the right input type here.
        long long a;
        long long b;
        long long c;
        long long d;

        SECTION(" 65 , 40")
        {   
            c=65;
            d=40;

            REQUIRE(extendedEuclid(c,d,&a,&b)==5);

            REQUIRE(a==-3);
            REQUIRE(b==5);
        }

        SECTION(" 40 , 65")
        {   
            c=40;
            d=65;
        
            REQUIRE(extendedEuclid(c,d,&a,&b)==5);
            REQUIRE(a==5);
            REQUIRE(b==-3);
        }
        
        SECTION(" 1 , 1")
        {   
            c=1;
            d=1;

            REQUIRE(extendedEuclid(c,d,&a,&b)==1);
            REQUIRE(a==0);
            REQUIRE(b==1);
        }

        SECTION(" 1 , 65")
        {   
            c=1;
            d=65;
  
            REQUIRE(extendedEuclid(c,d,&a,&b)==1);
            REQUIRE(a==1);
            REQUIRE(b==0);
        }

        SECTION(" 65 , 1")
        {   
            c=65;
            d=1;

            REQUIRE(extendedEuclid(c,d,&a,&b)==1);
            REQUIRE(a==0);
            REQUIRE(b==1);
        }

        SECTION(" 100 , 10")
        {   
            c=100;
            d=10;
    
            REQUIRE(extendedEuclid(c,d,&a,&b)==10);
            REQUIRE(a==0);
            REQUIRE(b==1);
        }

        SECTION(" 10 , 100")
        {
            c=10;
            d=100;

            REQUIRE(extendedEuclid(c,d,&a,&b)==10);
            REQUIRE(a==1);
            REQUIRE(b==0);
        }

        SECTION(" 10 , 10")
        { 
            c=10;
            d=10;

            REQUIRE(extendedEuclid(c,d,&a,&b)==10);
            REQUIRE(a==0);
            REQUIRE(b==1);
        }
    }
}