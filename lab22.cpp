#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double x = 0,double y = 0);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x,double y){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

//Write your code here

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double denominator = c.real*c.real+c.imag*c.imag;
	return ComplexNumber((real*c.real+imag*c.imag)/denominator,(imag*c.real-real*c.imag)/denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    return (real == c.real && imag == c.imag);
}

double ComplexNumber::abs(){
	return  sqrt((real*real)+(imag*imag));
}

double ComplexNumber::angle(){
	return atan2(imag,real) *180 / M_PI;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
	if (c.real == 0 && c.imag == 0) return os << 0;
    if (c.real == 0) return os << c.imag << "i";
    if (c.imag == 0) return os << c.real;
    os << c.real;
    if (c.imag > 0) os << "+";
    return os << c.imag << "i";
}

ComplexNumber operator+(double x,const ComplexNumber &c){
	return ComplexNumber(x+c.real,c.imag);
}

ComplexNumber operator-(double x,const ComplexNumber &c){
	return ComplexNumber(x-c.real,-c.imag);
}

ComplexNumber operator*(double x,const ComplexNumber &c){
	return ComplexNumber(x*c.real,x*c.imag);
}

ComplexNumber operator/(double x , const ComplexNumber &c){
	double deno = c.real*c.real+c.imag*c.imag;
	return ComplexNumber((x*c.real)/deno,(-x*c.imag)/deno);
}

bool operator==(double x, const ComplexNumber &c){
    return (x == c.real && c.imag == 0);
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}