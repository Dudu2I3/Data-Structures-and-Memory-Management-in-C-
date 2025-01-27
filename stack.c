#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct node* node) {
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node) {
        new_node->data = node->data;
        new_node->next = node->next;
    }
    return new_node;
}

struct node* push(struct node* sn) {
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node) {
        new_node->data = sn->data;
        new_node->next = sn;
    }
    return new_node;
}

struct node* pop(struct node* sn) {
    if (!sn) return NULL;
    struct node* tmp = sn->next;
    free(sn);
    return tmp;
}

void destroy(struct node* sn) {
    while (sn) {
        sn = pop(sn);
    }
}
