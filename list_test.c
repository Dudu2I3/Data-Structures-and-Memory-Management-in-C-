#include "list.h"

#include <stdio.h>

int test_add_door() {
    int flag = 1;
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};

    struct node* root = init(&d1);
    if (root == NULL) flag = 0;

    struct node* new_node = add_door(root, &d2);
    if (new_node == NULL) flag = 0;
    if (root->next != new_node) flag = 0;
    if (new_node->door->id != 2) flag = 0;
    if (new_node->door->status != 1) flag = 0;

    destroy(root);
    return flag;
}

int test_remove_door() {
    int flag = 1;
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct door d3 = {3, 0};

    struct node* root = init(&d1);
    if (root == NULL) flag = 0;

    struct node* node2 = add_door(root, &d2);
    if (node2 == NULL) flag = 0;

    struct node* node3 = add_door(node2, &d3);
    if (node3 == NULL) flag = 0;

    root = remove_door(node2, root);
    if (find_door(2, root) != NULL) flag = 0;
    if (find_door(1, root) == NULL) flag = 0;
    if (find_door(3, root) == NULL) flag = 0;

    destroy(root);
    return flag;
}

int main() {
    if (test_add_door() == 1) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    if (test_remove_door() == 1) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}