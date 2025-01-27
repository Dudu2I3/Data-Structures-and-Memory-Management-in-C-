#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* door) {
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node) {
        new_node->door = door;
        new_node->next = NULL;
    }
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    if (elem == NULL || door == NULL) return NULL;
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node) {
        new_node->door = door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    while (root != NULL) {
        if (root->door->id == door_id) {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) return root;
    if (root == elem) {
        struct node* temp = root->next;
        free(root);
        return temp;
    }
    struct node* prev = root;
    while (prev->next != NULL && prev->next != elem) {
        prev = prev->next;
    }
    if (prev->next == elem) {
        prev->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* temp = root;
        root = root->next;
        free(temp);
    }
}