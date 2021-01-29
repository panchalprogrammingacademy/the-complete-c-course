#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int m, n;
	scanf ("%d %d", &m, &n);
	printf ("%d %d\n", m, n);
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
			printf ("%d ", rand() % 10); 
		printf ("\n");
	}
	printf ("\n");
	return 0;
}