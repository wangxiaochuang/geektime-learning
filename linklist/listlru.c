#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define CACHESIZE 10

typedef struct CNode{
    char *key;
    unsigned long val;
    struct CNode *next;
    struct CNode *pre;
} Node;

typedef struct {
    Node *head;
    Node *last;
    int count;
} Lrucache;

Lrucache *init() {
    Lrucache *lru = malloc(sizeof(Lrucache));
    Node *head = malloc(sizeof(Node));
    head->key = NULL;
    head->val = 0;
    head->next = NULL;
    head->pre = NULL;

    lru->head = head;
    lru->last = NULL;
    lru->count = 0;

    return lru;
}

int getCache(Lrucache *lru, char *key) {
    Node *p = lru->head->next;
    while (p) {
        if (strcmp(p->key, key) == 0) {
            break; 
        }
        p = p->next;
    }
    Node *move = NULL;
    if (p) {
        move = p; 
        move->pre->next = move->next;
        if (move->next) {
            move->next->pre = move->pre;
        }
    } else {
        move = malloc(sizeof(Node));
        move->key = malloc(sizeof(key));
        memcpy(move->key, key, sizeof(key));
        // just for test
        move->val = (unsigned long) (move);
    }
    move->next = lru->head->next;
    move->pre = lru->head;
    if (lru->head->next) {
        lru->head->next->pre = move; 
    }
    lru->head->next = move;

    lru->count++;
    if (lru->count > CACHESIZE) {
        Node *last = lru->last;
        last->pre->next = NULL;
        free(last->key);
        free(last);
        lru->count--;
    }
    return move->val;
}
int main(int argc, char **argv) {
    Lrucache *lru = init();
    char *keys[100] = {"key_a", "key_b", "key_c", "key_d", "key_e", "key_a", "key_c"};
    for (int i = 0; i < 100; i++) {
        char *key = keys[i];
        if (key != 0) {
            int val = getCache(lru, key);
            printf("%d\n", val);
        }
    }
}
