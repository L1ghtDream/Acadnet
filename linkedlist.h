#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "block.h"

typedef struct {
    block_t info;
} DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

void init(NODE** head);
NODE* add(NODE* node, DATA data);
void print_list(NODE* head);
NODE * reverse(NODE * node);
NODE *free_list(NODE *head);

#endif //LINKEDLIST_H