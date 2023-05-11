#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100
typedef int element;
int M = 0;
typedef struct {
	element array[MAX_LIST_SIZE]; 
	int size; 
} ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("Position Error");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n\n");
}
void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE) {
		error("List Overflow");
	}
	L->array[L->size++] = item;
}
void insert(ArrayListType* L, int pos, element item)
{
	M = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			M++;
		}
		L->array[pos] = item;
		L->size++;
	}
}
element delete(ArrayListType* L, int pos)
{
	M = 0;
	element item;
	if (pos < 0 || pos >= L->size)
		error("Position Error");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
		M++;
	}
	L->size--;
	return item;
}
int main(void)
{
	ArrayListType list;
	init(&list);
	for (;;) {
		int select, n, p, i = 1;
		printf("Menu\n(1) Insert\n(2) Delete\n(3) Print\n(0) Exit\nEnter the menu: ");
		scanf_s("%d", &select);
		if (select == 1) {
			printf("Enter the number and position: ");
			scanf_s("%d %d", &n, &p);
			while (i == 1) {
				if (is_empty(&list)) {
					if (p != 0) {
						printf("List size is zero. Please enter again(number position): ");
						scanf_s("%d %d", &n, &p);
					}
					else
						i = 0;
				}
				else if (list.size < p) {
					printf("List position error. Please enter again(number position): ");
					scanf_s("%d %d", &n, &p);
				}
				else
					i = 0;
			}
			insert(&list, p, n);
			printf("\nMove: %d\n\n", M);
		}
		else if (select == 2) {
			if (is_empty(&list))
				printf("List is empty\n\n");
			else {
				int tmp;
				printf("Enter the position: ");
				scanf_s("%d", &p);
				while (i == 1) {
					if (list.size < p) {
						printf("List position Error. Please enter again(position): ");
						scanf_s("%d", &p);
					}
					else
						i = 0;
				}
				tmp = delete(&list, p);
				printf("\nMove: %d\nDelete: %d\n\n", M, tmp);
			}
		}
		else if (select == 3) {
			if (is_empty(&list))
				printf("List is empty\n\n");
			else 
				print_list(&list);
		}
		else if (select == 0) {
			printf("Exit the program\n\n");
			system("pause");
			exit(1);
		}
		else
			printf("Invalid Menu. Please select again..\n\n");
	}
	return 0;
}