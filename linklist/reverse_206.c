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
struct ListNode* reverseList(struct ListNode* head){
   struct ListNode *p = head;
   struct ListNode *tmp = NULL;
   struct ListNode *current = NULL;
   while (p) {
       tmp = p;
       p = p->next;
       tmp->next = current;
       current = tmp;
   }
   return current;
}

int main( int argc, char **argv )
{
	struct ListNode *head = init("1234567");
	struct ListNode *new = reverseList(head);
	travel(new);
	return 0;
}

