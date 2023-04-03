#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
 
using namespace std;
 
class ComplexNumber
{
private:
    int real;
    int imag;
 
public:
    ComplexNumber(){}
 
    ComplexNumber(int r, int i) 
	{
        real = r;
        imag = i;
    }
 
    ComplexNumber operator + (ComplexNumber const &obj) //sum
	{
         ComplexNumber res;
 
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
 
         return res;
    }
 

    ComplexNumber operator - (ComplexNumber const &obj) //subtraction
	{
        ComplexNumber temp;
 
         temp.real = real - obj.real;
         temp.imag = imag - obj.imag;
 
        return temp;
    }
 
    bool operator > (ComplexNumber const &obj) //booloperator
	{
        ComplexNumber temp;
 
        if((real > obj.real) && (imag > obj.imag)) 
		{
            return true;
        } 
		else 
		{
            return false;
        }
    }
 
    ComplexNumber operator * (ComplexNumber const &obj) //Multiplication
    {
    	ComplexNumber m;
    	m.real = real*obj.real-imag*obj.imag;
    	m.imag = real*obj.imag+imag*obj.real;
    	return m;
	}
	
	ComplexNumber operator / (ComplexNumber const &obj) //Division
	{
		ComplexNumber d;
		d.real = (real*obj.real+imag*obj.imag) / (pow(obj.real,2) + pow(obj.imag,2));
		d.imag = (imag*obj.real-real*obj.imag) / (pow(obj.real,2) + pow(obj.imag,2));
		return d;
	}
	
    string returnNum() 
	{
        return to_string(real) + " " + to_string(imag) + "i";
    }
};
 
int main()
{
    ComplexNumber a(3,4), b(1,2);
    ComplexNumber sum,sub,mult,div;
 
    sum = a + b;
 
    cout << "Sum:" << sum.returnNum() << endl;
    
    sub = a - b;
    
    cout << "Sub:" << sub.returnNum() << endl;
 
    if(a > b) 
	{
        cout<<"First is bigger";
    } 
	else 
	{
        cout<<"Second is bigger";
    }
 
    cout << endl;
 
    mult = a * b; 
 
    cout<< "Multiplication:" << mult.returnNum() << endl;
    
    div = a / b;
    
    cout << "Division:" << div.returnNum() << endl;
    
    system("pause");
    return 0;
}
