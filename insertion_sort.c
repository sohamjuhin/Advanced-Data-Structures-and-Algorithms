#include <stdio.h>

#define SIZE 100

void insertion (int sort[], int n) {

	int i, j, key;

	for (i = 1; i < n; i ++) {

		for (key = sort[i], j = i - 1; 0 <= j && key < sort[j]; j --)
			sort[j + 1] = sort[j];

		sort[j + 1] = key;

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

	insertion (sort, n);

	printf ("The sorted elements of the unsorted elements are:\n");
	for (i = 0; i < n; i ++)
		printf ("%d ", sort[i]);
	printf ("\n");

	return 0;
		
}
