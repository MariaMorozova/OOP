#include "Complex.h"

CComplex::CComplex(double re, double im)
{
	m_re = re;
	m_im = im;
}

CComplex::~CComplex()
{
}

double CComplex::Magnitude() const
{
	return sqrt(pow(m_re, 2) + pow(m_im, 2));
}

double CComplex::Argument() const
{
	double angle = acos(m_re / Magnitude());
	int sign = signbit(m_im) ? -1 : 1;
	return angle * sign;
}

CComplex operator+=(CComplex & a, const CComplex & b)
{
	a = a + b;
	return a;
}

CComplex operator-=(CComplex & a, const CComplex & b)
{
	a = a - b;
	return a;
}

CComplex operator*=(CComplex & a, const CComplex & b)
{
	a = a * b;
	return a;
}

CComplex operator/=(CComplex & a, const CComplex & b)
{
	a = a / b;
	return a;
}

CComplex operator+(const CComplex & a, const CComplex & b)
{
	return CComplex(a.Re() + b.Re(), a.Im() + b.Im());
}

CComplex operator-(const CComplex & a, const CComplex & b)
{
	return CComplex(a.Re() - b.Re(), a.Im() - b.Im());
}

CComplex operator*(const CComplex & a, const CComplex & b)
{
	return CComplex(a.Re() * b.Re() - a.Im() * b.Im(),
		a.Im() * b.Re() + a.Re() * b.Im());
}

CComplex operator*(int a, const CComplex & b)
{
	return CComplex(a * b.Re(), a * b.Im());
}

CComplex operator / (const CComplex & c1, const CComplex & c2)
{
	double a = c1.Re();
	double b = c1.Im();
	double c = c2.Re(), d = c2.Im();

	//СЛАУ с 2 неизвестными
	double dc = d / c;
	double y = (b - a * dc) / (c + d * dc);
	double x = (a / c) + y * dc;

	return CComplex(x, y);
}

CComplex operator+(const CComplex & a)
{
	return a;
}

CComplex operator-(const CComplex & a)
{
	return CComplex(-a.Re(), -a.Im());
}

bool operator==(const CComplex & a, const CComplex & b)
{
	bool re = fabs(a.Re() - b.Re()) < DBL_MIN;
	bool im = fabs(a.Im() - b.Im()) < DBL_MIN;
	return re && im;
}

bool operator==(int a, const CComplex & b)
{
	return (CComplex(a) == b);
}

bool operator!=(const CComplex & a, const CComplex & b)
{
	return !(a == b);
}

std::ostream & operator<<(std::ostream & os, const CComplex & cc)
{
	os << cc.Re() << (cc.Im() < 0 ? "" : "+") << cc.Im();
	return os;
}

std::istream & operator >> (std::istream & os, CComplex & cc)
{
	double re, im;
	os >> re >> im;
	cc = CComplex(re, im);
	return os;
}
