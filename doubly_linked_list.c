#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node * next;
};
void linkedlistraversal(struct node * ptr){
    while(ptr != NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
    }
}
int main(int argc, char const *argv[])
{
    struct node * head;
    struct node * second;
    struct node * third;
    //allocation of memory in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=NULL;
    linkedlistraversal(head);
    return 0;
}
