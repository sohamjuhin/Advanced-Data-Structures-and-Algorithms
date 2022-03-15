#include <stdio.h>
#include <stdlib.h>


typedef struct integer {
	int datae, dataq;
}integer;

typedef struct nodep {
	integer data;
	struct nodep *next;
}nodep;


void sort_insert (nodep **head, int c, int e) {

	nodep *p, *q, *t;

	for (p = *head, t = NULL; p != NULL && e < (p->data).datae; t = p, p = p->next);

	q = (nodep *) malloc (sizeof (nodep));
	(q->data).dataq = c;
	(q->data).datae = e;

	if (p == *head) {
		q->next = *head;
		*head = q;
	}
	else { 
		q->next = p;
		t->next = q;
	}
	
}

void display (nodep *head) {

	nodep *p;
	int flag = 0;

	for (p = head; p != NULL; p = p->next) {
		if ((p->data).dataq != 0) {
			if ((p->data).dataq > 0) 
				if (flag != 0)
					printf ("+");
			if ((p->data).dataq != 1) {
				if ((p->data).dataq == -1)
					printf("-");
				else
					printf ("%d", (p->data).dataq);
			}
			else if (p->next == NULL)
				printf ("1");
			if ((p->data).datae != 0) {
				printf ("x");
				if ((p->data).datae != 1)
					printf ("^%d", (p->data).datae);
			}
		}
		flag ++;
	}

	printf ("\n");

}


nodep* input_poly (void) {

	nodep *head = NULL;
	int q, e;
	char s = 'y';

	while (s != 'n') {
		printf ("Enter the co-eficient and exponent(c, e)\n");
		scanf ("%d%d", &q, &e);
		sort_insert (&head, q, e);
		display (head);
		printf ("Insert again = anykey\nExit = n\n");
		scanf ("%c%c", &s, &s);
	}
	
	return head;
	
}

 
nodep* sum (nodep **head1, nodep **head2) {

	nodep *p, *q, *heads = NULL;

	for (p = *head1, q = *head2; p != NULL && q != NULL;) {

		if ((p->data).datae == (q->data).datae) {
			sort_insert (&heads, (p->data).dataq + (q->data).dataq, (p->data).datae);
			p = p->next;
			q = q->next;
		}
		else if ((p->data).datae > (q->data).datae) {
			sort_insert (&heads, (p->data).dataq, (p->data).datae);
			p = p->next;
		}
		else {
			sort_insert (&heads, (q->data).dataq, (q->data).datae);
			q = q->next;
		}

	}

	for (;p != NULL; p = p->next)
		sort_insert (&heads, (p->data).dataq, (p->data).datae);
	for (;q != NULL; q = q->next)
		sort_insert (&heads, (q->data).dataq, (q->data).datae);

	return heads;

}


nodep* search (nodep **head, int e) {

	nodep *p;

	for (p = *head; p != NULL; p->next)
		if ((p->data).datae == e)
			return p;

}

void insert_add_dope (nodep **head, int c, int e) {
	
	nodep *p = NULL;
	
	p = search (head, e);
	printf ("ok\n");
	
	if (p == NULL)
		sort_insert (head, c, e);
	else
		(p->data).dataq = (p->data).dataq + c;
		
}
			 
nodep* multip (nodep **head1, nodep **head2) {

	nodep *p, *q, *headm = NULL;

	for (p = *head1; p != NULL; p = p->next) 
		for (q = *head2; q != NULL; q = q->next) 
			insert_add_dope (&headm, ((p->data).dataq * (q->data).dataq), ((p->data).datae + (q->data).datae));
		
	return headm;

}



int main (void) {

	int order1, order2, i, data;
	nodep *head1, *head2, *heads, *headm;
	
	printf ("1st polynomial:\n");
	head1 = input_poly ();
	printf ("2nd polynomial:\n");
	head2 = input_poly ();
	
	printf ("1st polynomial-\n");
	display (head1);
	printf ("2nd polynomial-\n");
	display (head2);
	heads = sum (&head1, &head2);
	printf ("Sum is-\n");
	display (heads);
	headm = multip (&head1, &head2);
	printf ("Multiplication is-\n");
	display (headm);

}
