#include "io.h"

Node* deleteList(Node* ptr)
{
	Node* tmp = NULL;
	while (ptr != NULL) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	return ptr;
}

int getList(Node** pptr)
{
	char buf[81], * str;
	Node head = { '*', NULL };
	Node* last = &head;
	int n, rc = 1;
	do {
		n = scanf("%20[^\n]", buf);
		if (n < 0) {
			deleteList(head.next);
			head.next = NULL;
			rc = 0;
			continue;
		}
		if (n > 0) {
			for (str = buf; *str != '\0'; ++str) {
				last->next = (Node*)malloc(sizeof(Node));
				last = last->next;
				last->c = *str;
			}
			last->next = NULL;
		}
		else
			scanf("%*c");
	} while (n > 0);
	*pptr = head.next;
	return rc;
}

void putList(const char* msg, Node* ptr)
{
	printf("%s: \"", msg);
	for (; ptr != NULL; ptr = ptr->next)
		printf("%c", ptr->c);
	printf("\"\n");
}