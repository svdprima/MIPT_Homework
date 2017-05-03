#ifndef IMAGINARY_H_
#define IMAGINARY_H_
#include <iostream>

using std::ostream;
using std::istream;

class Imagine 
{
protected:
	double real;
	double im;
public:
	Imagine ();
	Imagine (double a);
	Imagine (double a, double b);
	Imagine (const Imagine& orginal);
	double getRe () const;
	double getIm () const;
	void setRe(double nu);
	void setIm (double nu);	
	Imagine operator + (const Imagine& left);
	void operator += (const Imagine& left);
	Imagine operator ++ (int foo);
	Imagine operator ++ ();
	Imagine operator - (const Imagine& right);
	Imagine operator - ();
	void operator -= (const Imagine& right);
	Imagine operator -- (int foo);
	Imagine operator -- ();
	double operator ! () const;
	Imagine operator ~ () const;
	Imagine operator * (const Imagine& right) const;
	Imagine operator / (const Imagine& right) const;
	friend ostream& operator << (ostream& stream, const Imagine& message);
	friend istream& operator >> (istream& stream, Imagine& message);
	virtual ~Imagine ()
	{
	}
};

class Real:public Imagine  
{
public:
	Real ();
	Real (double a);
	Real operator = (Imagine a);
	friend ostream& operator << (ostream& stream, const Real& message);
	friend istream& operator >> (istream& stream, Real& message);
	~Real ()
	{
	}
};

class Integer final:public Real
{
public: 
	Integer ();
	Integer (double a);
	Integer operator = (Imagine a);
	friend ostream& operator << (ostream& stream, const Integer& message);
	friend istream& operator >> (istream& stream, Integer& message);
	~Integer ()
	{
	}
};
#endif
