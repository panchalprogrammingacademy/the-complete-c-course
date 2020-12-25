#include <stdio.h>
#include <math.h>
int main() {
	// store user's input
	int N;
	// accept user's input
	scanf ("%d", &N);
	// stores the actual and predicted value
	int actual, predicted;
	// stores the mean-squared-error
	double mse = 0.0;
	// compute values
	for (int i = 0; i < N; ++i) {
		// accept values
		scanf ("%d %d", &actual, &predicted);
		// add to mse
		mse += pow(actual - predicted, 2);
	}
	// take the mean
	mse = mse / N;
	// compute the root-mean-squared-error
	double rmse = sqrt(mse);
	// print the results
	printf ("%lf\n", rmse);
	// successful exit
	return 0;
}