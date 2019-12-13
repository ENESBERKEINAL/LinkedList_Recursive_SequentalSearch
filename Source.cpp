#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int item;
	struct Node *next;
}LIST;

LIST *first = NULL;
LIST *last = NULL;

void InsertElement(int m) {
	LIST *p = (LIST*)malloc(sizeof(LIST));
	if (first == NULL) {
		first = last = p;
		p->item = m;
		p->next = NULL;
	}
	else {
		last->next = p;
		p->item = m;
		last = p;
		p->next = NULL;
	}
}

void PositiveDivisor() {
	LIST *p = first;
	while (p) {
		int div = 1;
		printf("\nPositive integer divisors for number %d --> ", p->item);
		while (p->item >= div) {
			if (p->item % div == 0) {
				printf(" %d ", div);
			}
			div++;
		}
		p = p->next;
	}
}

int RecLinearSearch(int y, LIST *p) {
	if (p == NULL) {
		printf("Your number hasn't been found in the list..!");
		return -1;
	}
	else if (y == p->item) {
		PositiveDivisor();
	}
	else {
		return RecLinearSearch(y, p->next);
	}
}



int main() {
	int n, m, y;
	LIST *p;
	printf("How many elements in your list:  ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		printf("\n%d. element: ", i + 1);
		scanf("%d", &m);
		InsertElement(m);
	}
	
	printf("Enter the element you want to find: ");
	scanf("%d", &y);
	p = first;
	
	RecLinearSearch(y, p);
	getchar();
	getchar();
	return 0;
}