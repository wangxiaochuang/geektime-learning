#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct CNode {
    char val;
    struct CNode *next;
} Node;

int isPalindrome(Node *head) {
    Node *quick = head;
    Node *slow = head;
    Node *p = NULL;
    Node *p1, *p2 = NULL;
    while (quick && quick->next) {
        Node *tmp = slow;
        slow = slow->next;
        quick = quick->next->next;
        tmp->next = p;
        p = tmp;
    }
    p1 = p;
    p2 = quick ? slow->next : slow;
    while (p1 && p2 && p1->val == p2->val) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return !(p1 || p2);
}
int main(int argc, char **argv) {
    char *str = "asdfasdfasdf";
    int i = 0;
    Node *head = (Node *) malloc(sizeof(Node));
    Node *p = head;
    for (; i < strlen(str); i++) {
        Node *n = malloc(sizeof(Node));
        n->val = *(str + i);
        n->next = NULL;
        p->next = n;
        p = n;
    }
    int ok = isPalindrome(head->next);
    if (ok) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
