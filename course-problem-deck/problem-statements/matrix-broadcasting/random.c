#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int m1, n1, m2, n2;
	scanf ("%d %d %d %d", &m1, &n1, &m2, &n2);
	printf ("%d %d %d %d\n", m1, n1, m2, n2);
	for (int i = 0; i < m1; ++i){
		for (int j = 0; j < n1; ++j)
			printf ("%d ", rand() % 10); 
		printf ("\n");
	}
	for (int i = 0; i < m2; ++i){
		for (int j = 0; j < n2; ++j)
			printf ("%d ", rand() % 10); 
		printf ("\n");
	}
	return 0;
}