#include "imaginary.h"
#include <iostream>

using std::ostream;
using std::istream;
using std::endl;

Imagine::Imagine ()
{
	real = 0.0;
	im = 0.0;
}

Imagine::Imagine (double a)
{
	real = a;
	im = 0;
}

Imagine::Imagine (double a, double b)
{
	real = a;
	im = b;
}

Imagine::Imagine (const Imagine& original)
{
	real = original.real;
	im = original.im;
}

Real::Real (): Imagine ()
{
}

Real::Real (double a): Imagine (a)
{
}

Integer::Integer (): Real ()
{
}

Integer::Integer (double a)
{
	real = (int) a;
	im = 0;
}

double Imagine::getRe () const
{
	return real;
}

double Imagine::getIm () const
{
	return im;
}

void Imagine::setRe (double nu)
{
	real = nu;
}

void Imagine::setIm (double nu)
{
	im = nu;
}

Imagine Imagine::operator + (const Imagine& right)
{
	return Imagine (this->real + right.real, this->im + right.im);
}

void Imagine::operator += (const Imagine& right)
{
	this->real += right.real;
	this->im += right.im;
}

Imagine Imagine::operator ++ (int foo)
{
	this->real++;
	return Imagine (this->real - 1, this->im);
}

Imagine Imagine::operator ++ ()
{
	this->real++;
	return *this;
}

Imagine Imagine::operator - (const Imagine& right)
{
	return Imagine (this->real - right.real, this->im - right.im);
}

Imagine Imagine::operator - ()
{
	this->real = - this->real;
	this->im = - this->im;
}

Imagine Imagine::operator -- (int foo)
{
	this->real--;
	return Imagine (this->real + 1, this->im);
}

Imagine Imagine::operator -- ()
{
	this->real--;
	return *this;
}

void Imagine::operator -= (const Imagine& right)
{
	this->real -= right.real;
	this->im -= right.im;		
} 

double Imagine::operator ! () const
{
	return this->real * this->real + this->im * this->im;	
}

Imagine Imagine::operator ~ () const
{
	return Imagine (this->real, -(this->im));
}

Imagine Imagine::operator * (const Imagine& right) const
{
	return Imagine (this->real * right.real - this->im * right.im,
			this->real * right.im   + this->im * right.real);
}

Imagine Imagine::operator / (const Imagine& right) const
{
	Imagine tmp = *this * (~right);
	return Imagine (tmp.real/!right, tmp.im/!right);
}

ostream& operator << (ostream& stream, const Imagine& message)
{
	return stream<<message.getRe()<<" + "<<message.getIm()<<" * i"<<endl;
}

ostream& operator << (ostream& stream, const Real& message)
{
	return stream<<message.getRe()<<endl;
}

ostream& operator << (ostream& stream, const Integer& message)
{
	return stream<<message.getRe()<<endl;
}

istream& operator >> (istream& stream, Imagine& data)
{
	double r, i;
	stream>>r>>i;
	data.setRe(r);
	data.setIm(i);
	return stream;
}

istream& operator >> (istream& stream, Real& data)
{
	double r;
	stream>>r;
	data.setRe(r);
	return stream;
}

istream& operator >> (istream& stream, Integer& data)
{
	int i;
	stream>>i;
	data.setRe(i);
	return stream;
}

Real Real::operator = (Imagine a)
{
	this->real = a.getRe();
	this->im = 0.0;
	return *this;
}

Integer Integer::operator = (Imagine a)
{
	this->real = (int) a.getRe();
	this->im = 0;
	return *this;
}
