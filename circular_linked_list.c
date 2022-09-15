#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node * next;
};
void linkedlistraversal(struct node * head){
    struct node * ptr=head;
   
    do
    {
         printf("%d\n",ptr->data);
        ptr=ptr->next;
        
    } while (ptr!=head);
    
    
}
struct node * insertfirst(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p=head->next;
    while (p->next !=head)
    {
        p=p->next;
    }
    //at this point p point last node of the circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
int main(int argc, char const *argv[])
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    //allocation of memory in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=fourth;
    fourth->data=77;
    fourth->next=head;
    linkedlistraversal(head);
    printf("after insertion at first\n");
    head=insertfirst(head,80);
    linkedlistraversal(head);
    return 0;
}
