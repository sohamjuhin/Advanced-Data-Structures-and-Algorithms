#include <stdio.h>

#define SIZE 100

void swap (int* x, int* y) {

	int z;

	z = *x;
	*x = *y;
	*y = z;

}

void bubble (int sort[], int n) {

	int i, j, flag, k;

	for (i = 0; i < n; i ++) { 

		for (flag = 0, j = 0; j < n - i - 1; j ++) 
			if (sort[j + 1] < sort[j]) {
				swap (&sort[j + 1], &sort[j]);
				flag = 1;
			}

		if (flag == 0)
			break;

	}

}

main () {

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

	bubble (sort, n);

	printf ("The sorted elements of the unsorted elements are:\n");
	for (i = 0; i < n; i ++)
		printf ("%d ", sort[i]);
	printf ("\n");
		
}
