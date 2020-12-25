#include <stdio.h>
#include <math.h>
int main() {
	// store user's input
	int a, b, c;
	// accept user's input
	scanf ("%d %d %d", &a, &b, &c);
	// compute the disriminant 
	double D = b*b - 4*a*c;
	// take decision based on D
	if (D < 0){
		// imaginary roots
		// get the real  part
		double real = -b/(2*a);
		// get the imaginary parts
		double im = sqrt(-1*D)/(2*a);
		// print the roots
		printf ("%g+%gi %g-%gi\n", real, im, real, im);
	} else {
		// real roots
		double r1 = (-b + sqrt(D))/(2*a);
		double r2 = (-b - sqrt(D))/(2*a);
		printf ("%g %g\n", r1, r2);
	}
	// successful exit
	return 0;
}