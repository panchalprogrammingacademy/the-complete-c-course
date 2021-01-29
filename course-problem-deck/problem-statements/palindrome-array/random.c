#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int N, ispalindrome;
	scanf ("%d %d", &N, &ispalindrome);
	printf ("%d\n", N);
	int array[N];
	if (ispalindrome) {
		int i = 0, j = N - 1;
		while (i <= j){
			array[i] = array[j] = rand() % 100;
			i++; j--;
		}
	} else {
		for (int i = 0; i < N; ++i)
			array[i] = rand() % 100;
	}

	for (int i = 0; i < N; ++i) printf ("%d ", array[i]);		
	printf ("\n");
	return 0;
}