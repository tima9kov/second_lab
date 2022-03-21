#include "new.h"

Node* newList(Node* ptr, Node* new_ptr) {
	Node head1 = { '*', ptr };
	Node* fst = &head1;

	Node head2 = { '*', NULL };
	Node* scd = &head2;

	for (; fst; fst = fst->next) {
		fst->next = delSpace(fst->next);
	}
	fst = &head1;

	char tmp = fst->c;
	fst = fst->next;
	int counter = 0, spaces = 0;

	for (; fst; fst = fst->next) {
		if (fst->c == tmp) {
			spaces = 0;
			scd->next = (Node*)malloc(sizeof(Node));
			scd = scd->next;
			scd->c = fst->c;
			tmp = fst->c;
			if (counter == 0) {
				counter++;
				scd->next = (Node*)malloc(sizeof(Node));
				scd = scd->next;
				scd->c = fst->c;
				tmp = fst->c;
			}
		}
		else {
			if (spaces == 0 && counter != 0 && fst->next != NULL) {
				scd->next = (Node*)malloc(sizeof(Node));
				scd = scd->next;
				scd->c = 32;
				spaces++;
			}
			tmp = fst->c;
			counter = 0;

		}
	}
	scd->next = NULL;

	return head2.next;
}

Node* delSpace(Node* ptr)
{
	Node* tmp;
	while (ptr && (ptr->c == ' ' || ptr->c == '\t')) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	return ptr;
}
