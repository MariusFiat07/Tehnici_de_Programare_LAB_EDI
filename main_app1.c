#include <stdio.h>
#include <stdlib.h>

// Sa se scrie o functie care primeste doua liste si returneaza 1 daca ele sunt identice, altfel 0.

struct list{
    int value;
    struct list* next;
};

typedef struct list* List_t;

List_t makeNode(const int value){
    List_t new_node = malloc(sizeof(struct list));
    if(!new_node)
    {
        fprintf(stderr, "Error at new_node memory allocation!\n");
        exit(-1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

List_t insertFront(List_t myList, const int new_value){
    List_t new_node = makeNode(new_value);
    new_node->next = myList;
    return new_node;
}

void print_list(List_t myList){
    for(List_t current_node = myList; current_node != NULL; current_node = current_node->next)
    {
        printf("%d ", current_node->value);
    }
    printf("\n");
}

int verify_equality(List_t list_1, List_t list_2){
    List_t node_2 = NULL;
    node_2 = list_2;
    for(List_t node_1 = list_1; node_1 != NULL && node_2 != NULL; node_1 = node_1->next)
    {
        if(node_1->value != node_2->value)
        {
            return 0;
        }
        node_2 = node_2->next;
    }
    return 1;
}

int main(void){
    List_t list_1 = NULL, list_2 = NULL;

    list_1 = insertFront(list_1, 1);
    list_1 = insertFront(list_1, 2);
    list_2 = insertFront(list_2, 1);
    list_2 = insertFront(list_2, 2);

    printf("List_1 is -> ");
    print_list(list_1);
    printf("List_2 is -> ");
    print_list(list_2);

    int equal = verify_equality(list_1, list_2);
    equal == 1? printf("Yes, the lists are equal!\n") : printf("No, the lists are not equal!\n");
    return 0;
}