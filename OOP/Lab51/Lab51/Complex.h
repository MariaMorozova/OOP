#pragma once
#include <math.h>
#include <iostream>
#include <float.h>

class CComplex
{
public:
	// инициализация комплексного числа значениями действительной и мнимой частей
	CComplex(double re = 0.0, double im = 0.0);
	~CComplex();

	// возвращает действительную часть комплексного числа
	double Re() const { return m_re; }
	// возвращает мнимую часть комплексного числа
	double Im() const { return m_im; }

	// возвращает модуль комплексного числа
	double Magnitude() const;
	// возвращает аргумент комплексного числа
	double Argument() const;
	
private:
	double m_re;
	double m_im;
};

CComplex operator+(const CComplex & a, const CComplex & b);

CComplex operator-(const CComplex & a, const CComplex & b);
CComplex operator-(int a, const CComplex & b); //выпилить

CComplex operator*(const CComplex & a, const CComplex & b);
CComplex operator*(int a, const CComplex & b);  //выпилить

CComplex operator/(const CComplex & c1, const CComplex & c2);
CComplex operator/(int a, const CComplex & b);  //выпилить

CComplex operator+(const CComplex & a);
CComplex operator-(const CComplex & a); 

CComplex operator+=(CComplex & a, const CComplex & b);
CComplex operator-=(CComplex & a, const CComplex & b);
CComplex operator*=(CComplex & a, const CComplex & b);
CComplex operator/=(CComplex & a, const CComplex & b);

bool operator==(const CComplex & a, const CComplex & b);
bool operator==(int a, const CComplex & b); //TODO 
bool operator!=(const CComplex & a, const CComplex & b);

std::ostream& operator<<(std::ostream& os, const CComplex& cc);
std::istream& operator>>(std::istream& os, CComplex& cc);

