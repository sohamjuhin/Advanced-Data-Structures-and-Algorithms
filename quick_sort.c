#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void swap (int* x, int* y) {

	int z;

	z = *x;
	*x = *y;
	*y = z;

}

int partition (int sort[], int lb, int ub) {

	int  pivort, le, se, i;

	le = se = lb;

	pivort = sort[lb];//Here we always choose pivort element as lb-th element

	while (le < ub) {

		if (sort[le + 1] <= pivort) {
			swap (&sort[se + 1], &sort[le + 1]);
			se ++;
		}

		le ++;

	}

	swap (&sort[lb], &sort[se]);

	return se;

}

void quick (int sort[], int lb, int ub) {

	int piv;

	if (lb < ub) {
		piv = partition (sort, lb, ub);
		quick (sort, lb, piv - 1);
		quick (sort, piv + 1, ub);
	}

}

int main () {

	int sort[SIZE], n, i;

	printf ("Enter the size of the input: ");
	scanf ("%d", &n);

	printf ("Enter the unsorted elements:\n");
	for (i = 0; i < n; i ++)
		scanf ("%d", &sort[i]);

	printf ("You have entered\n");
	for (i = 0; i < n; i ++)
		printf ("%d ", sort[i]);
	printf ("\n");

	quick (sort, 0, n - 1);

	printf ("The sorted elements of the unsorted elements are:\n");
	for (i = 0; i < n; i ++)
		printf ("%d ", sort[i]);
	printf ("\n");

	return 0;
		
}
