#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int N, allsame, temp = rand() % 100;
	scanf ("%d %d", &N, &allsame);
	printf ("%d\n", N);
	for (int i = 0; i < N; ++i) 
		printf ("%d ", allsame ? temp : rand() % 100);		
	printf ("\n");
	return 0;
}