#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int N;
	scanf ("%d", &N);
	printf ("%d\n", N);
	for (int i = 0; i < N; ++i)
		printf ("%d ", rand() % 100);
	printf ("\n");
	return 0;
}