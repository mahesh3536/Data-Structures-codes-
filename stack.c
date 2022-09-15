#include<stdio.h>
#include<stdlib.h>
 
/*struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int stackBottom(struct stack* sp){
    return sp->arr[0];
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6);  
    push(sp, 5);  
    push(sp, 75);  
    
    //  Printing values from the stack
     for (int j = 1; j <= sp->top + 1; j++)
     {
         printf("The value at position %d is %d\n", j, peek(sp, j));
     }
     
    return 0;
}*/
struct node{
    int data;
    struct node * next;
};
void linkListTraversal(struct node* ptr){
    while (ptr != NULL)
    {
       printf("Element:%d\n",ptr->data);
       ptr=ptr->next;
    }
    
}
int isFull(struct node* top){
    struct node* p=(struct node*)malloc(sizeof(struct node*));
    if (p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int isEmpty(struct node* top){
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
struct node* push(struct node* top,int x){
     if (isFull(top))
     {
        printf("stack is overflow");
     }
    else
    {
        struct node* n=(struct node*)malloc(sizeof(struct node*));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
    
}
int peek(int pos,struct node* top){
    struct node* ptr=top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr=ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
    
    
}
int pop(struct node** top){
    if (isEmpty(*top))
    {
        printf("stack is underflow\n");
    }
    else
    {
        struct node* n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
    
    
}
int stackbottom(struct node* top){
    struct node* ptr=top;
    while (ptr->next!=NULL)
    {
       ptr = ptr->next; 
    }
    return ptr->data;
    
}
int main(int argc, char const *argv[])
{ 
    struct node* top=NULL;
    top=push(top,45);
    top=push(top,34);
    top=push(top,23);
    //int element=pop(&top);
    int element =peek(2,top);
    printf("%d\n",element);
    int ele = stackbottom(top);
    printf("%d\n",ele);
    linkListTraversal(top);
    return 0;
}
