#include "ReallyLongInt.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;


ReallyLongInt::ReallyLongInt()
{
    this->isNeg=0;
    this->numDigits=1;
    unsigned int* stuff=new unsigned int[this->numDigits];
    stuff[0]=0;
    this->digits=stuff;
}

ReallyLongInt::ReallyLongInt(const string& numStr)
{
    this->numDigits=numStr.size();
    if(numStr[0]==45)
    {
        this->isNeg=1;    
        this->numDigits--;
    }
    else
    {
        this->isNeg=0;    
    }

    unsigned int* stuff=new unsigned int[this->numDigits];

    unsigned long long i=0;

    if(this->isNeg)
    {
        i++;
    }

    for(unsigned long long j=0; j<this->numDigits; j++)
    {
        stuff[j]=numStr[i]-48;
        i++;
    }
    
    removeLeadingZeros(stuff,this->numDigits);

    if(stuff[0]==0){this->isNeg=0;}

    this->digits=stuff;
}


ReallyLongInt::ReallyLongInt(long long num)
{
    if(num<0){this->isNeg=1;}
    else{this->isNeg=0;}

    num=abs(num);

    if(num!=0){this->numDigits=floor(log10(num)+1);}
    else
    {
        this->numDigits=1;
    }

    unsigned int* stuff=new unsigned int[this->numDigits];
    
    if(num!=0)
    {

        unsigned long long divisor=1;

        for(unsigned int l=0; l<this->numDigits-1; l++)
        {
            divisor*=10;
        }

        unsigned long long modulo_divisor=10*divisor;

        for(unsigned int j=0; j<this->numDigits; j++)
        {
            stuff[j]=(num%modulo_divisor)/divisor;
            divisor/=10;
            modulo_divisor/=10;
        }
    }
    else{stuff[0]=0;}

    this->digits=stuff;
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)
{
    this->isNeg=other.isNeg;
    
    this->numDigits=other.numDigits;

    unsigned int* stuff=new unsigned int[this->numDigits];

    for(unsigned int i=0; i<this->numDigits;i++)
    {
        stuff[i]=other.digits[i];
    }

    this->digits=stuff;
}

ReallyLongInt::ReallyLongInt(unsigned* digitsArr, unsigned arrSize, bool isNeg)
{
    removeLeadingZeros(digitsArr,arrSize);

    if(!isNeg)
    {
            if(digitsArr[0]==0){this->isNeg=0;}
            else{this->isNeg=isNeg;}
    }
    else
    {
        this->isNeg=isNeg;
    }

    this->numDigits=arrSize;
    this->digits=digitsArr;
}


void ReallyLongInt::removeLeadingZeros(unsigned* x, unsigned& xSize) const
{
    unsigned long long no_of_zeros=0;
    while(no_of_zeros<xSize && x[no_of_zeros]==0)
    {
        no_of_zeros++;
    }

    if(no_of_zeros!=xSize)
    {
        xSize=xSize-no_of_zeros;
        unsigned long long k=no_of_zeros;
        for(unsigned long long j=0; j<xSize; j++)
        {
            x[j]=x[j+k];
        }
    }
    else
    {
        if(xSize>0){xSize=1;}
        else{xSize=0;}
    }
}


string ReallyLongInt::toString() const
{
    if(this->digits[0]==0){return "0";}

    string output;

    if(this->isNeg){output+="-";}

    for(unsigned long long i=0; i<this->numDigits; i++)
    {
        output+=to_string(this->digits[i]);
    }
    return output;
}

bool ReallyLongInt::equal(const ReallyLongInt& other) const
{
    if(this->isNeg!=other.isNeg){return false;}
    if(this->numDigits!=other.numDigits){return false;}

    for(unsigned long long i=0;i<this->numDigits;i++)
    {
        if(this->digits[i]!=other.digits[i]){return false;}
    }
    return true;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
    if(this->numDigits>other.numDigits){return true;}
    else if(this->numDigits<other.numDigits){return false;}
    else
    {
        for(unsigned long long i=0; i<this->numDigits;i++)
        {
            if(this->digits[i]<other.digits[i]){return false;}//it should break it asap...maybe we need to check for all of the cases...greater than,equal to, less than 
            else if(this->digits[i]>other.digits[i]){return true;}
        }
        return false;
    }
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const
{
    if(this->isNeg<other.isNeg){ return 1;}
    else if(this->isNeg>other.isNeg){ return 0;}
    bool x=absGreater(other);
    if(this->isNeg==1 && other.isNeg ==1)
    {
        if(x){x=0;}
        else{x=1;}
    }
    return x;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const
{
    bool size_comparer=this->absGreater(other);

    unsigned long long smaller_size;
    unsigned long long bigger_size;

    if(size_comparer)
    {
        smaller_size=other.numDigits;
        bigger_size=this->numDigits;
    }
    else
    {
        smaller_size=this->numDigits;
        bigger_size=other.numDigits;
    }

    unsigned int* stuff=new unsigned int[bigger_size+1];

    unsigned int sum;
    unsigned int temp;
    unsigned int carry_over=0;

    for(unsigned long long i=0;i<smaller_size;i++)
    {
        sum=this->digits[this->numDigits-i-1]+other.digits[other.numDigits-i-1]+carry_over;
        temp=sum%10;
        carry_over=(sum-temp)/10;
        stuff[bigger_size-i]=temp;
    }

    unsigned long long diff=bigger_size-smaller_size;

    for(unsigned long long i=0;i<diff;i++)
    {/*
        I understand that I could have put in 2 for loops inside the if and else statements unlike what I have done below
        where I have the if and else inside the for loop. The former approach would have reduced the number of steps, but 
        would kind of have been a code duplication. Since speed is not the biggest of our concerns here, I reckoned that
        having a fewer lines was better. 
    */
        if(size_comparer){stuff[diff-i]=this->digits[diff-i-1];}
        else{stuff[diff-i]=other.digits[diff-i-1];}
    }

    if(carry_over>0)
    {
        unsigned long long i=0;
        while(i<diff && carry_over!=0)
        {
            sum=stuff[diff-i]+carry_over;
            temp=sum%10;
            carry_over=(sum-temp)/10;
            stuff[diff-i]=temp;
            i++;
        }
    }
    stuff[0]=carry_over;
    return ReallyLongInt(stuff,bigger_size+1,0);
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const
{
    if(this->isNeg&&other.isNeg)
    {
        ReallyLongInt x=this->absAdd(other);
        x.flipSign();
        return x;
    }

    else if(!(this->isNeg)&&!(other.isNeg))
    {
        return absAdd(other);
    }

    else if(this->isNeg&&!other.isNeg)
    {
        ReallyLongInt x=other.absSub(*this);
        
        if(this->greater(other)){x.flipSign();}

        return x;
//        return other.absSub(*this);
    }

    else if(!this->isNeg&&other.isNeg)
    {
//        return absSub(other);
        ReallyLongInt x=other.absSub(*this);
        
        if(this->greater(other)){x.flipSign();}

        return x;   
    }

    return 0;
}


ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
    if(!(this->isNeg)&&!(other.isNeg))
    {
        return absSub(other);
    }

    else if(!(this->isNeg)&&other.isNeg)
    {
        return absAdd(other);
    }

    else if(this->isNeg && other.isNeg)
    {
        return other.absSub(*this);
    }

    else if(this->isNeg && !other.isNeg)
    {
        return -absAdd(other);//this is wrong............why?
    }

    return 0;
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const
{
    //first determine which is greater in terms of size and mathmatical standing both...to help with the signs later
    //the int* array should be initialised at the same size as that of the bigger one
    //then calculate the abs value

    bool abs_size_comparer=this->absGreater(other);
//    bool pure_size_comparer=this->greater(other);


    unsigned long long smaller_size;//sizes could be long long as well?
    unsigned long long bigger_size;

    if(abs_size_comparer)
    {
        smaller_size=other.numDigits;
        bigger_size=this->numDigits;
    }
    else
    {
        smaller_size=this->numDigits;
        bigger_size=other.numDigits;
    }

    unsigned int* stuff=new unsigned int[bigger_size];

    unsigned long long difference;
    bool previous_case_keeper=0;

    for(unsigned long long i=0;i<smaller_size;i++)
    {
        if(abs_size_comparer)
        {
            if(this->digits[this->numDigits-i-1]>=other.digits[other.numDigits-i-1])
            {
                if(previous_case_keeper)
                {
                    if(this->digits[this->numDigits-i-1]==other.digits[other.numDigits-i-1])
                    {
                        difference=9+this->digits[this->numDigits-i-1]-other.digits[other.numDigits-i-1];
                        previous_case_keeper=1;
                    }

                    else
                    {
                        difference=this->digits[this->numDigits-i-1]-other.digits[other.numDigits-i-1]-1;
                        previous_case_keeper=0;
                    }            
                }

                else
                {
                   difference=this->digits[this->numDigits-i-1]-other.digits[other.numDigits-i-1];
                    previous_case_keeper=0;
                }
            }
            else
            {
                if(previous_case_keeper)
                {
                   difference=9-other.digits[other.numDigits-i-1]+this->digits[this->numDigits-i-1];
                }
                else
                {
                   difference=10-other.digits[other.numDigits-i-1]+this->digits[this->numDigits-i-1];
                }
                previous_case_keeper=1;
            }
        }

        else
        {
            if(other.digits[other.numDigits-i-1]>=this->digits[this->numDigits-i-1])
            {
                if(previous_case_keeper)
                {
                    if(this->digits[this->numDigits-i-1]==other.digits[other.numDigits-i-1])
                    {
                        difference=9-this->digits[this->numDigits-i-1]+other.digits[other.numDigits-i-1];
                        previous_case_keeper=1;
                    }

                    else
                    {
                        difference=-this->digits[this->numDigits-i-1]+other.digits[other.numDigits-i-1]-1;
                        previous_case_keeper=0;
                    }              
    
//                    difference=other.digits[other.numDigits-i-1]-this->digits[this->numDigits-i-1]-1;
                }

                else
                {
                    difference=other.digits[other.numDigits-i-1]-this->digits[this->numDigits-i-1];
                }
                previous_case_keeper=0;
            }
            else
            {
                if(previous_case_keeper)
                {
                    difference=9-this->digits[this->numDigits-i-1]+other.digits[other.numDigits-i-1];
                }
                else
                {
                    difference=10-this->digits[this->numDigits-i-1]+other.digits[other.numDigits-i-1];
                }
                previous_case_keeper=1;
            }
        }
        // if(difference<0)
        // {
        //     difference+=10;
        //     previous_case_keeper=1;
        // }

        stuff[bigger_size-i-1]=difference;
    }

    unsigned long long diff=bigger_size-smaller_size;

    if(diff>0)
    {
        for(unsigned int i=0;i<diff;i++)
        {
            if(abs_size_comparer){stuff[diff-i-1]=this->digits[diff-i-1];}
            else{stuff[diff-i-1]=other.digits[diff-1-i];}

            if(previous_case_keeper)
            {
                if(stuff[diff-i-1]==0){stuff[diff-i-1]=9;}
                else{stuff[diff-i-1]-=1;previous_case_keeper=0;}
            }
        }
    }

    //is it supposed to be absolute size comparer?
    if(abs_size_comparer) {return ReallyLongInt(stuff,bigger_size,0);}
    return ReallyLongInt(stuff,bigger_size,1);
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
    unsigned int* stuff=new unsigned int[this->numDigits+other.numDigits];

    int temp=0;
    int temp2=0;
    int carry_over=0;

  //  cout<<"Atleast inside the absMult "<<endl;

    for(unsigned int i=0;i<this->numDigits+other.numDigits;i++)
    {
        stuff[i]=0;
    }


    for(unsigned int i=0;i<this->numDigits;i++)
    {
        for(unsigned int j=0;j<other.numDigits;j++)
        {
            temp=this->digits[this->numDigits-i-1]*other.digits[other.numDigits-j-1];

            temp2=stuff[this->numDigits+other.numDigits-1-j-i]+temp%10+carry_over;

            carry_over=temp/10+temp2/10;////should it be (temp+temp2)/10
            
            stuff[this->numDigits+other.numDigits-1-j-i]=temp2%10;

            if(carry_over!=0&& j==other.numDigits-1)
            {
                stuff[this->numDigits-1-i]=carry_over;
                carry_over=0;
            }
        }
    }

 //   cout<<"end of muls"<<endl;

    return ReallyLongInt(stuff,this->numDigits+other.numDigits,0);
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
    quotient.numDigits=this->numDigits;

    unsigned int* stuff_quotient=new unsigned int[this->numDigits];

    for(unsigned int i=0; i<this->numDigits;i++)
    {
        stuff_quotient[i]=0;
    }

    ReallyLongInt r(0);

    ReallyLongInt other2=other;
    other2.isNeg=0;


    for(unsigned int i=0; i<this->numDigits;i++)
    {
        r*=10;
        ReallyLongInt this_digit=ReallyLongInt(this->digits[i]);

        r+=this_digit;

        int d=0;

        while(r>=other2)
        {
            r=r-other2;
            d+=1;
        }

        stuff_quotient[i]=d;
    }

    removeLeadingZeros(stuff_quotient,quotient.numDigits);

    delete quotient.digits;

    quotient.digits=stuff_quotient;

    remainder=r;
}

void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
    absDiv(other, quotient,remainder);

    if(!(this->isNeg)&&!(other.isNeg))
    {
        quotient.isNeg=0;
        remainder.isNeg=0;
    }

    else if(!(this->isNeg)&&other.isNeg)
    {
        quotient.isNeg=1;
        remainder.isNeg=0;
    }

    else if(this->isNeg && other.isNeg)
    {
        quotient.isNeg=0;
        remainder.isNeg=1;
    }

    else if(this->isNeg && !other.isNeg)
    {
        quotient.isNeg=1;
        remainder.isNeg=1;
    }
}


ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const
{
    if(!(this->isNeg)&&!(other.isNeg))
    {
        return absMult(other);
    }

    else if(!(this->isNeg)&&other.isNeg)
    {
        ReallyLongInt x=this->absMult(other);
        x.flipSign();
        return x;
    }

    else if(this->isNeg && other.isNeg)
    {
        return absMult(other);    
    }

    else if(this->isNeg && !other.isNeg)
    {
        ReallyLongInt x=this->absMult(other);
        x.flipSign();
        return x;
    }
    return 0;
}

void ReallyLongInt::swap(ReallyLongInt other)
{
    bool Temp_neg=other.isNeg;
    other.isNeg=this->isNeg;
    this->isNeg=Temp_neg;

    unsigned long long numdigits=other.numDigits;
    other.numDigits=this->numDigits;
    this->numDigits=numdigits;

    const unsigned int* otherDigits= other.digits;
    other.digits=this->digits;
    this->digits=otherDigits;

    // unsigned int* stuff=new unsigned int[other.numDigits];
    // for(unsigned int i=0; i<this->numDigits;i++)
    // {
    //     stuff[i]=other.digits[i];
    // }
    // other.digits=this->digits;    
    // this->digits=stuff;
    // cout<<"end of swap"<<endl;
}


void ReallyLongInt::flipSign()
{
    if(this->digits[0]==0){this->isNeg=0;}
    
    else if (this->isNeg==1){this->isNeg=0;}

    else{this->isNeg=1;}
}


ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{

    // cout<<endl<<"this "<<this->toString()<<endl;
    // cout<<"other "<<other.toString()<<endl;
    swap(other);
    // cout<<"this "<<this->toString()<<endl;
    // cout<<"other "<<other.toString()<<endl;
    return *this;

}


ReallyLongInt ReallyLongInt::operator-() const
{
    ReallyLongInt x=*this;
    x.flipSign();
    return x;
}

ReallyLongInt& ReallyLongInt::operator+=(const ReallyLongInt& other)
{
    ReallyLongInt x=*this;
    x=x+other;
    *this=x;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator-=(const ReallyLongInt& other)
{
    ReallyLongInt x=*this;
    x=x-other;
    *this=x;
    return *this;   
}

ReallyLongInt& ReallyLongInt::operator*=(const ReallyLongInt& other)
{
    ReallyLongInt x=*this;
    x=x*other;
    *this=x;  //should I do a *this=x??? instead may I just return x?
    return *this;   
}

ReallyLongInt& ReallyLongInt::operator/=(const ReallyLongInt& other)
{
    ReallyLongInt x=*this;
    x=x/other;//should I do a *this=x??? instead may I just return x?
    *this=x;
    return *this;   
}

ReallyLongInt& ReallyLongInt::operator%=(const ReallyLongInt& other)
{
    ReallyLongInt x=*this;
    x=*this%other;//should I do a *this=x??? instead may I just return x?
    *this=x;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator++()
{
    ReallyLongInt x=ReallyLongInt(1);
    *this+=x;
    return *this;
}

ReallyLongInt& ReallyLongInt::operator--()
{
    ReallyLongInt x=ReallyLongInt(1);
    *this-=x;
    return *this;
}

ReallyLongInt ReallyLongInt::operator++(int dummy)
{
    ReallyLongInt x=*this;

    ReallyLongInt y=ReallyLongInt(1);
    *this+=y;

    return x;
}

ReallyLongInt ReallyLongInt::operator--(int dummy)
{
    ReallyLongInt x=*this;

    ReallyLongInt y=ReallyLongInt(1);
    *this-=y;

    return x;
}

long long ReallyLongInt::toLongLong() const
{
    ReallyLongInt x(LLONG_MAX);

    ReallyLongInt y("1");

    ReallyLongInt z=x+y;

    ReallyLongInt a=*this%z;

    long long num=0;

    unsigned long long iterator=1;

    for(unsigned long long i=0; i<a.numDigits;i++)
    {
        num+=a.digits[a.numDigits-i-1]*iterator;
        iterator*=10;
    }

    if(this->isNeg){num*=-1;}

    return num;
}


ReallyLongInt::~ReallyLongInt()
{
    delete  []this->digits;
}



ostream& operator<<(ostream& out, const ReallyLongInt& x)
{
    return out<<x.toString();
}


bool operator==(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.equal(y);
}

bool operator!=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return !x.equal(y);
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.greater(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return y.greater(x);
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return (x.greater(y)||x.equal(y));
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return (y.greater(x)||x.equal(y));
}


ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.sub(y);
}

ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y)
{
    return x.mult(y);
}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y)
{
    ReallyLongInt q=ReallyLongInt();

    ReallyLongInt r=ReallyLongInt();

    x.div(y,q,r);

    return q;
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y)
{
    ReallyLongInt q=ReallyLongInt();

    ReallyLongInt r=ReallyLongInt();

    x.div(y,q,r);

    return r;
}