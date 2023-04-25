#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

NODE * reverse(NODE * node) {
    NODE* nodes[10000];
    NODE* nodes_r[10000];

    int index=0;
    while(node->next!=NULL){
        nodes[index++]=node;
        node=node->next;
    }
    nodes[index++]=node;

    for(int i=index-1;i>=0;i--){
        nodes_r[index-i-1] = nodes[i];
    }

    NODE* head = (NODE*) malloc(sizeof (NODE));
    NODE* processNode = head;

    for(int i=0;i<index;i++){
        processNode->next=nodes_r[i];
        processNode= processNode->next;
        processNode->next=NULL;
    }

    return head;
}


void init(NODE** head) {
    *head = NULL;
}

NODE* add(NODE* node, DATA data) {
    NODE* temp = (NODE*) malloc(sizeof (NODE));
    if (temp == NULL) {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}

void print_list(NODE* head) {
    head = reverse(head);
    NODE * temp;
    int indent = 0;
    printf("Print chain\n");
    printf("=========== \n");
    for (temp = head; temp, temp = temp->next; indent = indent+2)
    {
        printf("%*sBlock data %d\n", indent,"", temp->data.info);
        printf("%*s\n", indent, "");
    }

    printf("\r\n");
}

NODE *free_list(NODE *head) {
    NODE *tmpPtr = head;
    NODE *followPtr;
    while (tmpPtr != NULL) {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}