#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int test_push() {
    int flag = 1;
    struct node initial = {21, NULL};
    struct node* stack = init(&initial);

    struct node* new_node = push(stack);
    if (new_node || new_node->data != 21 || new_node->next != stack) {
        destroy(new_node);
        flag = 0;
    }
    destroy(stack);
    return flag;
}

int test_pop() {
    int flag = 1;
    struct node initial = {52, NULL};
    struct node* stack = init(&initial);

    stack = push(stack);
    struct node* popped_node = pop(stack);

    if (popped_node || popped_node->data != 52 && popped_node->next != NULL) {
        destroy(popped_node);
        flag = 0;
    }

    destroy(stack);
    return flag;
}

int main() {
    if (test_push() == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    if (test_pop() == 1) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}