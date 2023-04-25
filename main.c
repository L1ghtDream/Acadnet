#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linkedlist.h"

int main(int argc, char const *argv[])
{
    srand(1337);

    NODE *head;
    DATA genesis_element;
    init(&head);

    genesis_element.info = 1337;

    head = add(head, genesis_element);

    for(int i=0;i<20;i++)
    {
        DATA *el = (DATA*)malloc(sizeof(DATA));

        el->info = i;
        head = add(head, *el);

    }

    print_list(head);

    free_list(head);

    return 0;
}