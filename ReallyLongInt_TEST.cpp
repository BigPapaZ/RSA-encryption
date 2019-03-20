#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ReallyLongInt.hpp"


TEST_CASE("Tests")
{
    string str;
    
    SECTION("Constructer")
    {
        SECTION("Empty Constructer")
        {
                ReallyLongInt x=ReallyLongInt();
                REQUIRE(x.toString()=="0");
        }
        
        SECTION("String Constructer")
        {            
            SECTION("0")
            {
                str="0";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }            

            SECTION("1")
            {
                str="1";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1");
            }       

            SECTION("-1")
            {
                str="-1";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1");
            }            

            SECTION("00")
            {
                str="00";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }            

            SECTION("-0")
            {
                str="-0";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }                 

            SECTION("-00")
            {
                str="-00";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }            

            SECTION("01")
            {
                str="01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1");
            }

            SECTION("-01")
            {
                str="-01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1");
            }

            SECTION("0000000000000100000000000000")
            {
                str="0000000000000100000000000000";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="100000000000000");
            }              

            SECTION("-0000000000000100000000000000")
            {
                str="-0000000000000100000000000000";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-100000000000000");
            }              

            SECTION("1234567890")
            {
                str="1234567890";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1234567890");
            }              

            SECTION("-1234567890")
            {
                str="-1234567890";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1234567890");
            }
        }

        SECTION("Copy Constructer")
        {

            SECTION("0")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt(x);
                REQUIRE(y.toString()=="0");
            }

            SECTION("1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt(x);
                REQUIRE(y.toString()=="1");
            }

            SECTION("-1")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt(x);
                REQUIRE(y.toString()=="-1");
            }

            SECTION("325")
            {
                ReallyLongInt x=ReallyLongInt("325");
                ReallyLongInt y=ReallyLongInt(x);
                REQUIRE(y.toString()=="325");
            }
            SECTION("-325")
            {
                ReallyLongInt x=ReallyLongInt("-325");
                ReallyLongInt y=ReallyLongInt(x);
                REQUIRE(y.toString()=="-325");
            }
        }

        SECTION("Long Long Num")
        {   
            SECTION("1")
            {
                long long num=1;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="1");
            }

            SECTION("325")
            {
                long long num=325;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="325");
            } 
            SECTION("-1")
            {
                long long num=-1;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="-1");
            }

            SECTION("1234")
            {
                long long num=1234;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="1234");
            }

            SECTION("-1234")
            {
                long long num=-1234;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="-1234");
            }

            SECTION("10000000000000")
            {
                long long num=10000000000000;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="10000000000000");
            }
            
            SECTION("-10000000000000")
            {
                long long num=-10000000000000;
                ReallyLongInt x=ReallyLongInt(num);
                REQUIRE(x.toString()=="-10000000000000");
            }
        }
    }

    SECTION("Functions")
    {
        SECTION("removeLeadingZeros")
        {
            SECTION("00")
            {
                str="00";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }

            SECTION("-00")
            {
                str="-00";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }            

            SECTION("01")
            {
                str="01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1");
            }

            SECTION("-01")
            {
                str="-01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1");
            }

            SECTION("0000000000000100000000000000")
            {
                str="0000000000000100000000000000";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="100000000000000");
            }              

            SECTION("-0000000000000100000000000000")
            {
                str="-0000000000000100000000000000";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-100000000000000");
            }              
            
        }
        SECTION("toString")
        {
            SECTION("-0")
            {
                str="-0";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="0");
            }                 

            SECTION("-1")
            {
                str="-1";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1");
            }                 


            SECTION("01")
            {
                str="01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1");
            }

            SECTION("-01")
            {
                str="-01";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1");
            }
            SECTION("1234567890")
            {
                str="1234567890";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="1234567890");
            }              

            SECTION("-1234567890")
            {
                str="-1234567890";
                ReallyLongInt x=ReallyLongInt(str);
                REQUIRE(x.toString()=="-1234567890");
            }         
        }
        SECTION("equal")
        {
            SECTION("0 , 0")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("0");
                REQUIRE(x.equal(y));
            }


            SECTION("1,1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("1");
                REQUIRE(x.equal(y));
            }

            SECTION("100 , 100")
            {
                ReallyLongInt x=ReallyLongInt("100");
                ReallyLongInt y=ReallyLongInt("100");
                REQUIRE(x.equal(y));
            }

            SECTION("-100 , -100")
            {
                ReallyLongInt x=ReallyLongInt("-100");
                ReallyLongInt y=ReallyLongInt("-100");
                REQUIRE(x.equal(y));
            }

            SECTION("-1000000000 , -1000000000")
            {
                ReallyLongInt x=ReallyLongInt("-1000000000");
                ReallyLongInt y=ReallyLongInt("-1000000000");
                REQUIRE(x.equal(y));
            }

            SECTION("-100 , 100")
            {
                ReallyLongInt x=ReallyLongInt("-100");
                ReallyLongInt y=ReallyLongInt("100");
                REQUIRE(!x.equal(y));
            }

            SECTION("100 , -100")
            {
                ReallyLongInt x=ReallyLongInt("100");
                ReallyLongInt y=ReallyLongInt("-100");
                REQUIRE(!x.equal(y));
            }

            SECTION("1,-1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("-1");
                REQUIRE(!x.equal(y));
            }

            SECTION("-1,1")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("1");
                REQUIRE(!x.equal(y));
            }

        }

        SECTION("greater")
        {
            SECTION("-1 , 0")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("0");
                REQUIRE(x.toString()=="-1");
                REQUIRE(y.toString()=="0");
                REQUIRE(!x.greater(y));
            }

            SECTION("0 , -1")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("-1");
                REQUIRE(x.greater(y));
            }
            SECTION("-100 , 1000")
            {
                ReallyLongInt x=ReallyLongInt("-100");
                ReallyLongInt y=ReallyLongInt("1000");
                REQUIRE(!x.greater(y));
            }

            SECTION("1000 , -100")
            {
                ReallyLongInt x=ReallyLongInt("1000");
                ReallyLongInt y=ReallyLongInt("-100");
                REQUIRE(x.greater(y));
            }
        }

        SECTION("add")
        {
            SECTION("0 , 0")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="0");
            }

            SECTION("1 , 0")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="1");
            }

            SECTION("0 , 1")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="1");
            }

            SECTION("1 , 1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="2");
            }

            SECTION("1 , -1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="0");
            }

            SECTION("-1 , 1")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="0");
            }
            SECTION("-1 , -1")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="-2");
            }

            SECTION("5 , -1")
            {
                ReallyLongInt x=ReallyLongInt("5");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="4");
            }

            SECTION("1 , -5")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("-5");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="-4");
            }


            SECTION("-1 , 5")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("5");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="4");
            }

            SECTION("-5 , 1")
            {
                ReallyLongInt x=ReallyLongInt("-5");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="-4");
            }



            SECTION("9 , 9")
            {
                ReallyLongInt x=ReallyLongInt("9");
                ReallyLongInt y=ReallyLongInt("9");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="18");
            }

            SECTION("1 , 10")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("10");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="11");
            }

            SECTION("10 , 1")
            {
                ReallyLongInt x=ReallyLongInt("10");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="11");
            }
            SECTION("99 , 99")
            {
                ReallyLongInt x=ReallyLongInt("99");
                ReallyLongInt y=ReallyLongInt("99");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="198");
            }
            SECTION("9999 , 9")
            {
                ReallyLongInt x=ReallyLongInt("9999");
                ReallyLongInt y=ReallyLongInt("9");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="10008");
            }

            SECTION("9,9999")
            {
                ReallyLongInt x=ReallyLongInt("9");
                ReallyLongInt y=ReallyLongInt("9999");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="10008");
            }

            SECTION("5 , -10")
            {
                ReallyLongInt x=ReallyLongInt("5");
                ReallyLongInt y=ReallyLongInt("-10");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="-5");
            }

            SECTION("-10 , 1")
            {
                ReallyLongInt x=ReallyLongInt("-10");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.add(y);
                REQUIRE(z.toString()=="-9");
            }


        }
        SECTION("sub")
        {
            SECTION("0 , 0")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.sub(y);
                REQUIRE(y.toString()=="0");
            }
            SECTION("1 , 1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="0");
            }
            SECTION("1 , 0")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="1");
            }

            SECTION("0 , 1")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-1");
            }
            SECTION("1 , -1")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="2");
            }

            SECTION("-1 , -1")
            {
                ReallyLongInt x=ReallyLongInt("-1");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="0");
            }
            SECTION("10 , 0")
            {
                ReallyLongInt x=ReallyLongInt("10");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="10");
            }

            SECTION("100 , 0")
            {
                ReallyLongInt x=ReallyLongInt("100");
                ReallyLongInt y=ReallyLongInt("0");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="100");
            }
            SECTION("0 , 100")
            {
                ReallyLongInt x=ReallyLongInt("0");
                ReallyLongInt y=ReallyLongInt("100");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-100");
            }
            SECTION("100 , 1")
            {
                ReallyLongInt x=ReallyLongInt("100");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="99");
            }
            SECTION("1 , 100")
            {
                ReallyLongInt x=ReallyLongInt("1");
                ReallyLongInt y=ReallyLongInt("100");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-99");
            }

            SECTION("1000 , 9")
            {
                ReallyLongInt x=ReallyLongInt("1000");
                ReallyLongInt y=ReallyLongInt("9");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="991");
            }

            SECTION("9 , 1000")
            {
                ReallyLongInt x=ReallyLongInt("9");
                ReallyLongInt y=ReallyLongInt("1000");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-991");
            }

            SECTION("1000 , 99")
            {
                ReallyLongInt x=ReallyLongInt("1000");
                ReallyLongInt y=ReallyLongInt("99");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="901");
            }

            SECTION("99 , 1000")
            {
                ReallyLongInt x=ReallyLongInt("99");
                ReallyLongInt y=ReallyLongInt("1000");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-901");
            }

            SECTION("5 , 3")
            {
                ReallyLongInt x=ReallyLongInt("5");
                ReallyLongInt y=ReallyLongInt("3");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="2");
            }
            SECTION("3 , 5")
            {
                ReallyLongInt x=ReallyLongInt("3");
                ReallyLongInt y=ReallyLongInt("5");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-2");
            }

            SECTION("5 , -3")
            {
                ReallyLongInt x=ReallyLongInt("5");
                ReallyLongInt y=ReallyLongInt("-3");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="8");
            }

            SECTION("-3 , -1")
            {
                ReallyLongInt x=ReallyLongInt("-3");
                ReallyLongInt y=ReallyLongInt("-1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-2");
            }

            SECTION("-3, -4")
            {
                ReallyLongInt x=ReallyLongInt("-3");
                ReallyLongInt y=ReallyLongInt("-4");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="1");
            }

            SECTION("-4, -3")
            {
                ReallyLongInt x=ReallyLongInt("-4");
                ReallyLongInt y=ReallyLongInt("-3");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-1");
            }

            SECTION("-3 , 1")
            {   
                ReallyLongInt x=ReallyLongInt("-3");
                ReallyLongInt y=ReallyLongInt("1");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="-4");
            }

            SECTION("30102 , 4307")
            {   
                ReallyLongInt x=ReallyLongInt("30102");
                ReallyLongInt y=ReallyLongInt("4307");
                ReallyLongInt z=x.sub(y);
                REQUIRE(z.toString()=="25795");
            }
        }

        SECTION("Assignment")
        {
            SECTION("ReallyLongInt x(10)")
            {
                //doesnt work after the third iteration of the loop
//                for(int i=0;i<10000;i++)
//                {
                ReallyLongInt x(10);
                ReallyLongInt y;y = x;
                y = -58;
                ReallyLongInt z("10");
  //              }
            }
        }

        SECTION("Multiplication")
        {
            SECTION("99*99")
            {
                ReallyLongInt x(99);
                ReallyLongInt z = x*x;
                REQUIRE(z.toString()=="9801");
            }
            SECTION("9999*9")
            {
                ReallyLongInt x(9999);
                ReallyLongInt y(9);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="89991");
            }
            SECTION("9*9999")
            {
                ReallyLongInt x(9);
                ReallyLongInt y(9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="89991");
            }
            SECTION("99*9999")
            {
                ReallyLongInt x(99);
                ReallyLongInt y(9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="989901");
            }
            SECTION("9999*99")
            {
                ReallyLongInt x(9999);
                ReallyLongInt y(99);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="989901");
            }
            SECTION("9999*0")
            {
                ReallyLongInt x(9999);
                ReallyLongInt y(0);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="0");
            }
            SECTION("0*9999")
            {
                ReallyLongInt y(9999);
                ReallyLongInt x(0);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="0");
            }
            SECTION("1*9999")
            {
                ReallyLongInt y(9999);
                ReallyLongInt x(1);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="9999");
            }
            SECTION("9999*1")
            {
                ReallyLongInt x(9999);
                ReallyLongInt y(1);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="9999");
            }
            SECTION("9999*10")
            {
                ReallyLongInt x(9999);
                ReallyLongInt y(10);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="99990");
            }
            SECTION("10*9999")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="99990");
            }

            SECTION("-10*9999")
            {
                ReallyLongInt x(-10);
                ReallyLongInt y(9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="-99990");
            }

            SECTION("10*-9999")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(-9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="-99990");
            }

            SECTION("-10*-9999")
            {
                ReallyLongInt x(-10);
                ReallyLongInt y(-9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="99990");
            }

            SECTION("89*(89^2")
            {
                ReallyLongInt x(-10);
                ReallyLongInt y(-9999);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="99990");
            }

            SECTION("513231*314546")
            {
                ReallyLongInt x(513231);
                ReallyLongInt y(314546);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="161434758126");
            }


            SECTION("102717*10")
            {
                ReallyLongInt y(102717);
                ReallyLongInt x(10);
                ReallyLongInt z = x*y;
                REQUIRE(z.toString()=="1027170");
            }

        }

        SECTION("Division")
        {

            SECTION("10/2")
            {
                ReallyLongInt* divident=new ReallyLongInt(10);

                ReallyLongInt* divisor=new ReallyLongInt(2);
                
                ReallyLongInt* quotient=new ReallyLongInt();

                ReallyLongInt* remainder=new ReallyLongInt();

                divident->div(*divisor,*quotient,*remainder);
                
                REQUIRE(quotient->toString()=="5");      
                
                REQUIRE(remainder->toString()=="0");         
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }
            
            SECTION("123/2")
            {
                ReallyLongInt* divident=new ReallyLongInt(123);
                ReallyLongInt* divisor=new ReallyLongInt(2);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="61");      
        
                REQUIRE(remainder->toString()=="1");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("2/123")
            {
                ReallyLongInt* divident=new ReallyLongInt(2);
                ReallyLongInt* divisor=new ReallyLongInt(123);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="0");      
        
                REQUIRE(remainder->toString()=="2");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }


            SECTION("123/123")
            {
                ReallyLongInt* divident=new ReallyLongInt(123);
                ReallyLongInt* divisor=new ReallyLongInt(123);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="1");      
        
                REQUIRE(remainder->toString()=="0");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }


            SECTION("123/1")
            {
                ReallyLongInt* divident=new ReallyLongInt(123);
                ReallyLongInt* divisor=new ReallyLongInt(1);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="123");      
        
                REQUIRE(remainder->toString()=="0");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("500/55")
            {
                ReallyLongInt* divident=new ReallyLongInt(500);
                ReallyLongInt* divisor=new ReallyLongInt(55);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="9");      
        
                REQUIRE(remainder->toString()=="5");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("500/56")
            {
                ReallyLongInt* divident=new ReallyLongInt(500);
                ReallyLongInt* divisor=new ReallyLongInt(56);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="8");      
        
                REQUIRE(remainder->toString()=="52");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("500/7")
            {
                ReallyLongInt* divident=new ReallyLongInt(500);
                ReallyLongInt* divisor=new ReallyLongInt(7);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="71");      
        
                REQUIRE(remainder->toString()=="3");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("500/57")
            {
                ReallyLongInt* divident=new ReallyLongInt(500);
                ReallyLongInt* divisor=new ReallyLongInt(57);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="8");      
        
                REQUIRE(remainder->toString()=="44");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }


            SECTION("-57/7")
            {
                ReallyLongInt* divident=new ReallyLongInt(-57);
                ReallyLongInt* divisor=new ReallyLongInt(7);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="-8");      
        
                REQUIRE(remainder->toString()=="-1");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }



            SECTION("-57/-7")
            {
                ReallyLongInt* divident=new ReallyLongInt(-57);
                ReallyLongInt* divisor=new ReallyLongInt(-7);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  

                divident->div(*divisor,*quotient,*remainder);
//                cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

                REQUIRE(quotient->toString()=="8");      
        
                REQUIRE(remainder->toString()=="-1");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("57/-7")
            {
                ReallyLongInt* divident=new ReallyLongInt(57);
                ReallyLongInt* divisor=new ReallyLongInt(-7);
                ReallyLongInt* quotient=new ReallyLongInt();
                ReallyLongInt* remainder=new ReallyLongInt();  
        
                divident->div(*divisor,*quotient,*remainder);
        
                REQUIRE(quotient->toString()=="-8");      
        
                REQUIRE(remainder->toString()=="1");
                
                delete divident;delete divisor;delete quotient;delete remainder;
            }

            SECTION("3614^2, 4307")
             {
                 ReallyLongInt x(1162428644);
                 ReallyLongInt y(4307);
                 ReallyLongInt z=x/y;
                 REQUIRE(z.toString()=="269892");
             }
        }
        SECTION("to long long")
        {
            SECTION("0")
            {
                ReallyLongInt x(0);
                REQUIRE(x.toLongLong()==0);
            }
            SECTION("1")
            {
                ReallyLongInt x(1);
                REQUIRE(x.toLongLong()==1);
            }
            SECTION("100")
            {
                ReallyLongInt x(100);
                REQUIRE(x.toLongLong()==100);
            }
            SECTION("9999")
            {
                ReallyLongInt x(9999);
                REQUIRE(x.toLongLong()==9999);
            }              
            SECTION("-1")
            {
                ReallyLongInt x(-1);
                REQUIRE(x.toLongLong()==-1);
            }
            SECTION("-100")
            {
                ReallyLongInt x(-100);
                REQUIRE(x.toLongLong()==-100);
            }
            SECTION("-9999")
            {
                ReallyLongInt x(-9999);
                REQUIRE(x.toLongLong()==-9999);
            }            
        }

        SECTION("=")
        {
            SECTION("10000")
            {
                ReallyLongInt x(10000);
                ReallyLongInt y=x;
                REQUIRE(y.toString()=="10000");
            }
        }
        SECTION("+=")
        {
            SECTION("10000")
            {
                ReallyLongInt x(10000);
                x+=x;
                REQUIRE(x.toString()=="20000");
            }
        }
        SECTION("-=")
        {
            SECTION("10000")
            {
                ReallyLongInt x(10000);
                x-=x;
                REQUIRE(x.toString()=="0");
            }
        }
        SECTION("*=")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                x*=x;
                REQUIRE(x.toString()=="100");
            }
        }
        
        SECTION("/=")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                x/=x;
                REQUIRE(x.toString()=="1");
            }
        }
        SECTION("%=")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                x%=x;
                REQUIRE(x.toString()=="0");
            }
        }
        
        SECTION("x++")
        {
            SECTION("10")
            {
                ReallyLongInt x=ReallyLongInt(10);
                //x++;
                REQUIRE(x++==10);
                REQUIRE(x.toString()=="11");
            }
        }
        SECTION("++x")
        {
            SECTION("10")
            {
                ReallyLongInt x=ReallyLongInt(10);
                ++x;
                REQUIRE(x.toString()=="11");
            }
        }
        SECTION("x--")
        {
            SECTION("10")
            {
                ReallyLongInt x=ReallyLongInt(10);
                //x++;
                REQUIRE(x--==10);
                REQUIRE(x.toString()=="9");

            }
        }
        SECTION("--x")
        {
            SECTION("10")
            {
                ReallyLongInt x=ReallyLongInt(10);
                --x;
                REQUIRE(x.toString()=="9");
            }
        }
        SECTION("==")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(x==y);
            }
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(!(x==y));
            }
        }
        SECTION("!=")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(!(x!=y));
            }
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(x!=y);
            }
        }
        SECTION(">")
        {

            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(!(x>y));
            }

            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(!(x>y));
            }
            SECTION("11,10")
            {
                ReallyLongInt y(10);
                ReallyLongInt x(11);
                REQUIRE(x>y);
            }
        }
        SECTION("<")
        {

            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(!(x<y));
            }

            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(x<y);
            }
            SECTION("11,10")
            {
                ReallyLongInt y(10);
                ReallyLongInt x(11);
                REQUIRE(!(x<y));
            }
        }
        SECTION(">=")
        {

            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(x>=y);
            }

            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(!(x>=y));
            }
            SECTION("11,10")
            {
                ReallyLongInt y(10);
                ReallyLongInt x(11);
                REQUIRE(x>=y);
            }
        }
        SECTION("<=")
        {
            SECTION("10")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(10);
                REQUIRE(x>=y);
            }
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                REQUIRE(x<=y);
            }
            SECTION("11,10")
            {
                ReallyLongInt y(10);
                ReallyLongInt x(11);
                REQUIRE(!(x<=y));
            }
        }


        SECTION("+")
        {
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                ReallyLongInt z=x+y;
                REQUIRE(z.toString()=="21");
            }
        }

        SECTION("-")
        {
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                ReallyLongInt z=x-y;
                REQUIRE(z.toString()=="-1");
            }
        }

        SECTION("*")
        {
            SECTION("10,11")
            {
                ReallyLongInt x(10);
                ReallyLongInt y(11);
                ReallyLongInt z=x*y;
                REQUIRE(z.toString()=="110");
            }
            SECTION("3614^2, 89")
            {
                ReallyLongInt x(3614);
                ReallyLongInt y(89);
                ReallyLongInt z=x*x*y;
                REQUIRE(z.toString()=="1162428644");
            }
        }

        SECTION("/")
        {
            SECTION("10,11")
            {
                ReallyLongInt x(11);
                ReallyLongInt y(11);
                ReallyLongInt z=x/y;
                REQUIRE(z.toString()=="1");
            }


             SECTION("3614^2, 4307")
             {
                 ReallyLongInt x(1162428644);
                 ReallyLongInt y(4307);
                 ReallyLongInt z=x/y;
                 REQUIRE(z.toString()=="269892");
             }

             SECTION("5,-10")
             {
                 ReallyLongInt x(5);
                 ReallyLongInt y(-10);
                 ReallyLongInt z=x/y;
                 REQUIRE(z.toString()=="0");
             }

        }
        SECTION("%")
        {
            SECTION("12,11")
            {
                ReallyLongInt x(12);
                ReallyLongInt y(11);
                ReallyLongInt z=x%y;
                REQUIRE(z.toString()=="1");
            }

            SECTION("11,11")
            {
                ReallyLongInt x(11);
                ReallyLongInt y(11);
                ReallyLongInt z=x%y;
                REQUIRE(z.toString()=="0");
            }

            SECTION("11,12")
            {
                ReallyLongInt x(11);
                ReallyLongInt y(12);
                ReallyLongInt z=x%y;
                REQUIRE(z.toString()=="11");
            }

            SECTION("1149,11")
            {
                ReallyLongInt x(1149);
                ReallyLongInt y(11);
                ReallyLongInt z=x%y;
                REQUIRE(z.toString()=="5");
            }

            SECTION("89^2,4307")
            {
                ReallyLongInt x(89);
                ReallyLongInt y(4307);
                ReallyLongInt z=(x*x)%y;
                REQUIRE(z.toString()=="3614");
            }

            SECTION("4763680551,104927")
            {
                ReallyLongInt x(4763680551);
                ReallyLongInt y(104927);
                ReallyLongInt z=x%y;
                REQUIRE(z.toString()=="99678");
            }
        }
    }
}