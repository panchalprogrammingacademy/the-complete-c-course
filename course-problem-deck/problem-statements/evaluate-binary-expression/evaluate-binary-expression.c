#include <stdio.h>
int main() {
	// store user's input
	int A, B;
	char op;
	// accept user's input
	scanf ("%d%c%d", &A, &op, &B);
	// take decision based on op
	if 		(op == '+')	printf ("%lf\n", (double)A + B);
	else if (op == '-')	printf ("%lf\n", (double)A - B);
	else if (op == '*') printf ("%lf\n", (double)A * B);
	else if (B == 0)	printf ("Division by zero error!\n");
	else if (op == '/')	printf ("%lf\n", (double)A / B);
	else if	(op == '%')	printf ("%lf\n", (double)(A % B));
	else 				printf ("Invalid operand!\n");
	// successful exit
	return 0;
}