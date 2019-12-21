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

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *quick = head;
    struct ListNode *slow = head;
    while (quick && quick->next) {
        slow = slow->next;
        quick = quick->next->next;
    }
    return slow;
}

int main( int argc, char **argv )
{
	struct ListNode *head = init("12345678");
	struct ListNode *new = middleNode(head);
	printf("%c\n", new->val);
	return 0;
}

