#include <iostream>
#include "imaginary.h"

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	Imagine a = Imagine();
	cin>>a;
	cout<<a;
	Imagine b = Imagine (a);
	cout<<b;
	Imagine c = a + b;
	cout<<c;
	
	Real d = Real ();
	cin>>d;
	Real f = Real (d);
	cout<<f;
	d += f;
	cout<<d;
	d -= f;
	cout<<d;
	d = ++f;
	cout<<d;
	f--;
	d = f++;
	cout<<d;
	
	Integer n = Integer ();
	cin>>n;
	Integer m = Integer (n);
	cout<<m;
	m = n--;
	cout<<m;
	n++;
	m = n++;
	cout<<m;
	Integer l = Integer (3);
	cout<<l;
	l += n;
	cout<<l;
	l = n - m;
	cout<<l;
	return 0;
}
