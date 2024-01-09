//circular linked list Implementation .....
#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;
};
typedef struct node Node;
struct CircularLinkedList{
    Node *head;
};
typedef struct CircularLinkedList CLL;

void insert(CLL *, int);
void deleteElement(CLL *, int);
void DisplayListElements(CLL *);
void DeleteList(CLL *);
int main()
{
    CLL *list1;
    list1 = (CLL *) malloc(sizeof(CLL));
    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 8);
    insert(list1, 6);
    insert(list1, 4);
    insert(list1, 5);
    printf("Initial list:\n");
    DisplayListElements(list1);
    deleteElement(list1, 3);
    printf("After removing the element 3:\n");
    DisplayListElements(list1);
    DeleteList(list1);
    return 0;
}
void insert(CLL *list, int value)
{
    if(list->head == NULL)
    {
        list->head = (Node *) malloc(sizeof(Node));
        list->head->val = value;
        list->head->next = list->head;
        list->head->prev = list->head;
        return;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->val = value;
    temp->next = list->head;
    temp->prev = list->head->prev;
    list->head->prev->next = temp;
    list->head->prev = temp;
}
void deleteElement(CLL *list, int value)
{
    Node *temp = list->head;
    while(temp->next != list->head)
    {
        if(temp->val == value)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
    if(temp->val == value)
    {
        free(temp);
        list->head = NULL;
    }
    printf("Not found..\n");
}
void DisplayListElements(CLL *list)
{
    Node *temp = list->head->next;
    printf("List elements are =\n");
    printf("%d ",list->head->val);
    while(temp != list->head)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
void DeleteList(CLL *list)
{
    while(list->head != NULL)
    {

        Node *temp = list->head;
        if(temp->next == list->head)
        {
            free(temp);
            list->head = NULL;
        }
        else
        {
            list->head->prev->next = list->head->next;
            list->head->next->prev = list->head->prev;
            list->head = list->head->next;
            free(temp);
        }
    }
}

