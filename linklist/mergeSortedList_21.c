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
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2){
	if (!l1) return l2;
    if (!l2) return l1;
    struct ListNode *head = NULL;

    struct ListNode **pp = &head;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            (*pp) = l1;
            l1 = l1->next;
        } else {
            (*pp) = l2;
            l2 = l2->next;
        }
        pp = &((*pp)->next);
    }
    *pp = l1 ? l1 : l2;
    return head;
}

int main( int argc, char **argv )
{
	struct ListNode *l1 = init("1357");
	struct ListNode *l2 = init("2468");
    struct ListNode *new = merge(l1, l2);
	travel(new);
	return 0;
}

