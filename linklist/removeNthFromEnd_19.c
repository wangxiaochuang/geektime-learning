#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *init(const char *str) {
	struct ListNode *head = NULL;
	struct ListNode **p = &head;
	struct ListNode *node = NULL;
	int i = 0;
	for (; i < strlen(str); i++) {
		node = (struct ListNode *) malloc(sizeof(struct ListNode));
		node->val = *(str + i);
		node->next = NULL;
		(*p) = node;
		p = &(node->next);
	}
	return head;
}
void travel(struct ListNode *head) {
	struct ListNode *p = head;
	while (p) {
		printf("%c", p->val);
		p = p->next;
	}
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode **left = &head;
    struct ListNode **right = &head;
    for (int i = 0; i < n; i++) {
        right = &((*right)->next);
    }
    if ((*right) == NULL) {
        *left = (*left)->next;
        return head;
    }
    while (*right) {
        left = &((*left)->next);
        right = &((*right)->next);
    }
    *left = (*left)->next;
    return head;
}

int main( int argc, char **argv )
{
	struct ListNode *head = init("1234567");
	head = removeNthFromEnd(head, 1);
	travel(head);
	return 0;
}

