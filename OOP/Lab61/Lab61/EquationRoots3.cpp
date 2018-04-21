#include "EquationRoots3.h"
#include <math.h>

//Вычисляем корни кубического уравнения ax^3 + bx^2 + cx + d = 0
EquationRoots3 Solve3(double a, double b, double c, double d)
{
	EquationRoots3 roots;
	roots.numRoots = 3;

	auto temp = b / a;
	b = c / a;
	c = d / a;
	a = temp;

	double p = -(a*a / 3) + b;
	double q = 2 * pow(a / 3, 3) - (a*b) / 3 + c;
	double Q = pow(p / 3, 3) + pow(q / 2, 2);

	double yToX;
	if (Q > 0)	//Кардано
	{
		double squareQ = sqrt(Q);
		double numA = pow(-q / 2 + squareQ, 1.0 / 3);
		double numB = pow(-q / 2 - squareQ, 1.0 / 3);
		roots.roots[0] = numA + numB;
		roots.roots[1] = { -(numA + numB) / 2 , sqrt(3) * (numA - numB) / 2 };
		roots.roots[2] = { -(numA + numB) / 2 , -sqrt(3) * (numA - numB) / 2 };
		yToX = -2.0 / 3;
	}
	else
	{
		temp = 2 * sqrt(-p / 3);
		double phi = std::acos(-q / 2 * pow(-3 / p, 1.5)) / 3;
		roots.roots[0] = temp * cos(phi);
		roots.roots[1] = temp * cos(phi + 2 * M_PI / 3);
		roots.roots[2] = temp * cos(phi - 2 * M_PI / 3);
		yToX = 2.0 / 3;
	}

	for (int i = 0; i < 3; ++i)
		roots.roots[i] += yToX;
	return roots;
}