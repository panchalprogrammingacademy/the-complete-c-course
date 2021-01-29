#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int m, n, o;
	scanf ("%d %d %d", &m, &n, &o);
	printf ("%d %d %d %d\n", m, n, n, o);
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			printf ("%d ", rand() % 10); 
		printf ("\n");
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < o; ++j)
			printf ("%d ", rand() % 10); 
		printf ("\n");
	}
	return 0;
}