#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next, *prev;
} Node;

void createList (Node **head, Node **tail) {
	
	int ch = 1;
	Node *q;
	
	if (*head != NULL) {
		printf ("List already exists!\n");
		return;
	}
	
	while (ch != 0) {
		
		q = (Node*) malloc (sizeof (Node));
		q->next = NULL;
		q->prev = NULL;
		
		printf ("Enter the data: ");
		scanf ("%d", &(q->data));
		
		if (*head == NULL)
			*head = *tail = q;
		else { 
			(*tail)->next = q;
			q->prev = *tail;
			*tail = (*tail)->next;
		}
		
		printf ("Inserted successfully!\n");
		
		printf ("To insert enter any number; Otherwise enter 0: ");
		scanf ("%d", &ch);
		
	}
	
}

void display (Node **head, Node **tail) {
	
	Node *p;
	
	if (*head == NULL) {
		printf ("List is empty!\n");
		return;
	}
	
	printf ("Elements:\n");
	for (p = *head; p != NULL; p = p->next)
		printf ("%d ", p->data);
	
	printf ("\n");
	
}
	
int main () {
	
	Node *head = NULL, *tail = NULL;
	int ch, item, pos, after, before;
	
	do {
		
		printf ("1.Create list\n2.Display\n0.Exit\n");
		printf ("Enter your choice: ");
		scanf ("%d", &ch);
		
		switch (ch) {
			
			case 1:
			createList (&head, &tail);
			break;
			
			case 2:
			display (&head, &tail);
			break;
			
			case 0:
			break;
			
			default:
			printf ("Please enter write choice!\n");
			
		}
		
	} while (ch != 0);
	
	return 0;
	
}
