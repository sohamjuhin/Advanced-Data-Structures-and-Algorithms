#include <stdio.h>
#include <stdlib.h>


#define DISPLAY 9

#define INSERT_BEGIN 1
#define INSERT_END 2
#define INSERT_POS 3
#define DELETE_BEGIN 4
#define DELETE_END 5
#define DELETE_POS 6

#define EXIT 20

#define OK 9990

     
typedef struct node {
	int data;
	struct node *next, *prev;
}node;


void insert_begin (node **head, node **tail, int d) {

	node *p = (node *) malloc (sizeof (node));
	p->data = d;
	
	if (*head == NULL) { 
		*head = *tail = p;
		p->next = p->prev = p;
	}
	p->next = *head;
	p->prev = *tail;
	*head = (*head)->prev = (*tail)->next = p;

}

void insert_end (node **head, node **tail, int d) {

	node *q, *p = (node *) malloc (sizeof (node));
	p->data = d;

	if (*tail == NULL) {
		*head = *tail = p;
		p->prev = p->next = p;
	}
	p->next = *head;
	p->prev = *tail;
	*tail = (*head)->prev = (*tail)->next = p;
	

}

int insert_pos (node **head, node **tail, int d, int pos) {

	node *p, *q, *t;
	int c;

	if (*head == NULL || pos == 0)
		return -32423;

	if (pos == 1)
		insert_begin (head, tail, d);
	else {
		//try to implement using only one single pointer instead of two pointers, p and q.
		for (p = *head, q = NULL, c = 1; c < pos && p != NULL; q = p, p = p->next, c ++);
		if (p == NULL && c != pos)
			return -123;

		t = (node *) malloc (sizeof (node));
		t->data = d;
		t->prev = q;

		if (q == *tail) 
			*tail = t;
		else 
			p->prev = t;
		q->next = t;
		t->next = p;
		//previous part of 'p' is not updated

	}

}

int delete_pos (node **head, node **tail, int pos) {

	node *p, *q;
	int c, d;

	if (*head == NULL || pos == 0)
		return -23234;

	if (pos == 1)
		delete_begin (head, tail);
	else {

		for (p = *head, q = NULL, c = 1; c < pos && p != NULL; q = p, p = p->next, c ++);
		if (p == NULL)
			return -34324;

		d = p->data;
		if (p == *tail) 
			*tail = q;
		else
			(p->next)->prev = q;
		q->next = p->next;
		
		free (p);

		return d;

	}

}

int delete_begin (node **head, node **tail) {

	node *p;
	
	if (*head == NULL)
		return -2132;

	printf ("Deleted item is %d\n", (*head)->data);
	p = *head;
	if (*head == *tail)
		*head = *tail = NULL;
	else {
		(p->next)->prev = *tail;
		*head = p->next;
		(*tail)->next = *head;	
	}

	free (p);

	return OK;

}

int delete_end (node **head, node **tail) {

	node *p;

	if (*tail == NULL)
		return -23432;

	printf ("Deleted item is %d\n",(*tail)->data);
	p = *tail;
	if (*head == *tail)
		*head = *tail = NULL;
	else {
		*tail = (*tail)->prev;
		(*tail)->next = *head;
		(*head)->prev = *tail;
	}

	free (p);

	return OK;

}


int display_head (node *head, node *tail) {

	node *p;

	if (head == NULL)
		return -133;

	p = head;
	
	do {
		printf ("%d ", p->data);
		p = p->next;
	}while (p != head); 

	return OK;

}

int display_tail (node *head, node *tail) {

	node *p;

	if (tail == NULL)
		return -133;

	p = tail;
	
	do {
		printf ("%d ", p->data);
		p = p->prev;
	}while (p != tail); 

	return OK;

}


void print_menu (void) {

	printf ("1. Insert at begin\n");
	printf ("2. Insert at end\n");
	printf ("3. Insert any position\n");
	printf ("4. Delete at begin\n");
	printf ("5. Delete at end\n");
	printf ("6. Delete any position\n");
	printf ("9. Display\n");
	printf ("20. Exit \n");

}

int main (void) {

	int data, pos, ch;
	node *head, *tail;

	head = tail = NULL; 
	
	while (ch != EXIT) {

		printf ("\n\n");
		print_menu ();		
		printf ("Enter your choice ");
		scanf ("%d", &ch);

		switch (ch) {

			case DISPLAY:
			printf ("1. By head\n2. By tail\n");
			scanf ("%d", &data);

			printf ("Linked List ");

			switch (data) {
				case 1:
				pos = display_head (head, tail);
				break;
				case 2:
				pos = display_tail (head, tail);
				break;
			}

			if (pos != OK)
				printf ("has no data");
			break;	
			

			case INSERT_BEGIN:
			printf ("Enter a data ");
			scanf ("%d", &data);
			insert_begin (&head, &tail, data);
			printf ("Data is entered\n");
			break;

			case INSERT_END:
			printf ("Enter a data ");
			scanf ("%d", &data);
			insert_end (&head, &tail, data);
			printf ("Data is entered\n");
			break;

			case INSERT_POS:
			printf ("Enter the position: ");
			scanf ("%d", &pos);
			printf ("Enter a data: ");
			scanf ("%d", &data);
			if (insert_pos (&head, &tail, data, pos) != OK)
				printf ("Can not enter %d position\n", pos);
			else 
				printf ("Data is entered\n");
			break;  

			case DELETE_BEGIN:
			data = delete_begin (&head, &tail);
			if (data != OK)
				printf ("Error\n");
			break;

			case DELETE_END:
			data = delete_end (&head, &tail);
			if (data != OK)
				printf ("Error\n");
			break;

			case DELETE_POS:
			printf ("Enter the position: ");
			scanf ("%d", &pos);
			data = delete_pos (&head, &tail, pos);
			if (data != OK)
				printf ("Can not delete %d position\n", pos);
			break;

			case EXIT:
			printf ("Good Bye!!\n");
			break;

			default: 
			printf ("Wrong Input!!!\n");
			break;
			
		}

	}

}
