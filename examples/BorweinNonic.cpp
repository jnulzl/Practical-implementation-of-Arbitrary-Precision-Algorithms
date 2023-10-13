#include <iostream>
#include <cmath>
#include "fprecision.h"

// Borwein nonic order algorithm
float_precision pi_borwein_nonic(unsigned int digits)
{
	const size_t precision = digits + 2 + (size_t)(log10(digits) + 0.5);
	bool first_time = true;
	const float_precision c1(1), c2(2), c3(3), c05(0.5), c9(9), c27(27);
	float_precision a(3, precision), an(0, precision), s(5, precision);
	float_precision u(0, precision), t(0, precision), r(3, precision);
	float_precision pow3(0, precision), v(0, precision), w(0, precision);
	float_precision pi(0,precision);
	const eptype limit = -(eptype)ceil((digits + 2)*log2(10));
	size_t loopcnt = 1;
	a = a.inverse(); // 1/3
	r = c05 * ( sqrt(r) - c1); // (sqrt(3)-1)/2
	s = nroot(c1-r*r*r,3); // (1-r)^(1/3)
	for (; ;++loopcnt)
	{
		// Build t
		t = c1 + c2*r; // 1+2r
		// Build u
		u = c1 + r + r * r; // 1+r+r^2
		u *= c9 * r; // 9r(1+r+r^2)
		u = nroot(u, 3); // (9r(1+r+r^2))^(1/3)
		// Build v
		v = t*t + t*u + u*u; // t^2+tu+u^2
		// Build w
		w = c27*(c1 + s + s*s); // 27(1+s+s^2)
		w /= v; // 27(1+s+s^2)/v
		// Build an
		if (first_time == true)
		{
			pow3 = a; // 3^(-1)=1/3 same as the initial a
			first_time = false;
		}
		else
		{
			pow3 *= c9; // 3^(2n-1)
		}
		an = w*a+pow3*(c1 - w); // w*a+3^(2n-1)(1-w)
		// Build s
		s = (c1 - r); // (1-r)
		s *= s.square(); // (1-r)^3
		s /= (t + 2 * u)*v; // (1-r)^3/((t+2u)*v)
		// Build r
		r = c1 - s.square() * s; // 1-s^3
		r = nroot(r, 3); // (1-s^3)^(1/3)
		pi = an - a;
		if (loopcnt>1 && (r==c1||an == a||(pi).exponent()<limit))
		{
			break;
		}
		a = an;
	}
	pi = an.inverse(); // pi = 1/a
	pi.precision(digits); 
	return pi;
}

int main(int argc, char* argv[])
{
	if(2 != argc)
	{
		std::printf("Usage:\n\t %s digits_of_pi\n", argv[0]);
		return -1;
	}
	std::cout << "pi = " << pi_borwein_nonic(std::atoi(argv[1])) << std::endl;
	return 0;
}