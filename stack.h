#ifndef STACK_H
#define STACK_H

struct node {
    int data;
    struct node* next;
};

struct node* init(struct node* node);
struct node* push(struct node* sn);
void destroy(struct node* root);
struct node* pop(struct node* sn);

#endif