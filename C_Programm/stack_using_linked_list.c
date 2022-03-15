#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Linked {
	int data;
	struct Stack_Linked *next;
} Stack;

void push (Stack **top, int item) {
	
	Stack *p;
	
	p = (Stack *) malloc (sizeof (Stack));
	p->data = item;
	p->next = NULL;
	
	if (*top != NULL)
		p->next = *top;
	
	*top = p;
	
	printf ("Pushed!\n");
	
}

void pop (Stack **top) {
	
	Stack *p;
	
	if (*top == NULL) {
		printf ("Underflow\n");
		return;
	}
	
	p = *top;
	*top = p->next;
	
	printf ("Poped; The data is %d\n", p->data);
	
	free (p);
	
}

void display (Stack **top) {
	
	Stack *p;
	
	if (*top == NULL) {
		printf ("Underflow\n");
		return;
	}
	
	printf ("Elements:\n");
	for (p = *top; p != NULL; p = p->next) 
		printf ("%d ", p->data);
	
	printf ("\n");
	
}

int main () {
	
	Stack *top = NULL;
	int item, ch;
	
	do {
		
		printf ("1.PUSH\n2.POP\n3.Display\n0.Exit\n");
		printf ("Enter your choice: ");
		scanf ("%d", &ch);
		
		switch (ch) {
			
			case 1:
			printf ("Enter the item: ");
			scanf ("%d", &item);
			push (&top, item);
			break;
			
			case 2:
			pop (&top);
			break;
			
			case 3:
			display (&top);
			break;
			
			case 0:
			break;
			
		}
		
	} while (ch != 0);
	
	return 0;
	
}			
