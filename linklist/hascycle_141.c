#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *init(int vals[], int len, int pos) {
	struct ListNode *head = NULL;
	struct ListNode **pp = &head;
	struct ListNode *tmp = NULL;
	struct ListNode *node = NULL;
	for (int i = 0; i < len; i++) {
		node = (struct ListNode *) malloc(sizeof(struct ListNode));
		node->val = *(vals + i);
		node->next = NULL;
	
		(*pp) = node;	
		pp = &((*pp)->next);
		if (i + 1 == pos) {
			tmp = node;
		}
	}
	*pp = tmp;
	return head;
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *quick = head;
    if (head == NULL || head->next == NULL) {
        return false;
    }
    while (1) {
        if (quick == NULL || quick->next == NULL) {
            break;
        }
        slow = slow->next;
        quick = quick->next->next;
        if (slow == quick) {
            return true;
        }
    }
    return false;
}

int main( int argc, char **argv )
{
	int vals[] = {3,4,5,6,2,1};
	struct ListNode *head = init(vals, sizeof(vals) / sizeof(int), -1);
	bool has = hasCycle(head);
	if (has) {
		printf("yes");
	} else {
		printf("no");
	}
	return 0;
}

