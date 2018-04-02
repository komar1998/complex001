#include <iostream>
#include <sstream>

using namespace std;

struct complex_t
{
    float real;
    float imag;

    complex_t()
    {
        real = 0.0f;
        imag = 0.0f;
    }

    complex_t add( complex_t other ) const
    {
        complex_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    complex_t sub( complex_t other ) const
    {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }

    complex_t mult( complex_t other ) const
    {
        complex_t result;
        result.real = real * other.real - imag * other.imag;
        result.imag = real * other.imag - imag * other.real;
        return result;
    }

    complex_t div( complex_t other ) const
    {
        complex_t result;
        result.real = (real * other.real + imag * other.imag)/(other.real * other.real - other.imag * other.imag);
        result.imag = (imag * other.real - real * other.imag)/(other.real * other.real - other.imag * other.imag);
        return result;
    }

    istream & read(istream & stream)
       {
           char op;
           return stream >> op >> real >> op >> imag >> op;
       }

       ostream & write(ostream & stream ) const
       {
           return stream << "(" << real << "," << imag << ")";
   }
};
int main()
{
	char op;
complex_t a;
complex_t b;
cout<<"Enter the complex number:\n";
if (a.read(std::cin) && b.read(std::cin))
{
	complex_t result;
	cout<<"Enter operation:\n";
	cin >> op;
	switch (op)
	{
		case ('+'):
		result = a.add(b);
		result.write(cout);
		break;
		case ('-'):
		result = a.sub(b);
		result.write(cout);
		break;
		case ('*'):
		 result = a.mult(b);
		result.write(cout);
		break;
		case ('/'):
		result = a.div(b);
		result.write(cout);
		break;
	}
}
else
	{
		cout << "error";
}
return 0;
}

