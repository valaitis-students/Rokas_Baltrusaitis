#include "prioqueue.h"

Node* Create(void)
{
    Node* list = (Node*)malloc(sizeof(Node));
    if(list == NULL)
        return NULL;
    list->head = NULL;
    return list;
}
int IsFull()
{
    prioqueue* kazkas = (prioqueue*)malloc(sizeof(prioqueue));
    if(kazkas == NULL)
        return 1;
    else
        return 0;
}
int IsEmpty(Node* list)
{
    if(list->head == NULL)
        return 1;
    else
        return 0;
}
void* Insert(Node* list, priotype prio, valtype val)
{
    prioqueue* start = list->head;
    prioqueue* previous = start;
    prioqueue* newprioqueue = (prioqueue*)malloc(sizeof(prioqueue));
    if(newprioqueue == NULL)
        return NULL;
    newprioqueue->priority = prio;
    newprioqueue->value = val;
    if(start == NULL || start->priority < prio)
    {
        newprioqueue->next = list->head;
        list->head = newprioqueue;
    }
    else
    {
        while(start != NULL && start->priority >= prio)
        {
            previous = start;
            start = start->next;
        }
        newprioqueue->next = start;
        previous->next = newprioqueue;
    }
    return (void*)list;
}

valtype Remove(Node* list)
{
    prioqueue* head= list->head;
    valtype value = head->value;
    prioqueue* current = head;
    list->head = head->next;
    free(current);
    return value;
}

void Join(Node* list1, Node** list2)
{
    prioqueue* start = (*list2)->head;
    prioqueue* previous;
    while(start != NULL)
    {
        previous = start;
        Insert(list1, start->priority, start->value);
        start = start->next;
        free(previous);
    }
    free(*list2);
    *list2 = NULL;
}

void Destroy(Node** list)
{
    prioqueue* start = (*list)->head;
    prioqueue* previous;
    while(start != NULL)
    {
        previous = start;
        start = start->next;
        free(previous);
    }
    free(*list);
    *list = NULL;
}

prioqueue GetData(Node* list)
{
    return *(list->head);
}
void print(Node* list)
{
    if(list == NULL)
        return;
    prioqueue* start = list->head;
    int i = 0;
    while(start != NULL)
    {
        i++;
        printf("%d. %d   %d\n", i, start->value, start->priority);
        start = start->next;
    }
}

