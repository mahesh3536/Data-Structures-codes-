#include <stdio.h>
#include <stdlib.h>
/*LINEAR QUEUE
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct queue *q){
    if (q->r==q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
int isEmpty(struct queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;

}
void enqueue(struct queue *q,int val){
    if (isFull(q))
    {
       printf("This queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
    }

}
int dequeue(struct queue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("this queue is empty");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
   return a;

}
int main()
{
    struct queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int*) malloc(q.size*sizeof(int));
    //enqueue few elements
    printf("%d\n",isEmpty(&q));
   enqueue(&q,12);
   printf("Dequeuing elment is %d\n",dequeue(&q));
   printf("%d",isEmpty(&q));
    return 0;
}
*/
// CIRCULAR QUEUE
/*
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct queue *q){
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
int isEmpty(struct queue *q){
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;

}
void enqueue(struct queue *q,int val){
    if (isFull(q))
    {
       printf("This queue is full\n");
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r]=val;
    }

}
int dequeue(struct queue *q){
    int a=-1;
    if (isEmpty(q))
    {
        printf("this queue is empty");
    }
    else
    {
        q->f = (q->f+1)%q->size;
        a=q->arr[q->f];
    }
   return a;

}
int main()
{
    struct queue q;
    q.size=4;
    q.f=0;
    q.r=0;
    q.arr=(int*) malloc(q.size*sizeof(int));
    //enqueue few elements
    printf("%d\n",isEmpty(&q));
   enqueue(&q,12);
   enqueue(&q,15);
   enqueue(&q,11);
  // enqueue(&q,10);
   printf("Dequeuing elment is %d\n",dequeue(&q));
   printf("Dequeuing elment is %d\n",dequeue(&q));
   printf("Dequeuing elment is %d\n",dequeue(&q));
   printf("Dequeuing elment is %d\n",dequeue(&q));
   enqueue(&q,10);
   enqueue(&q,10);
   enqueue(&q,10);
   printf("%d\n",isEmpty(&q));
   printf("%d",isFull(&q));
    return 0;
}*/
// QUEUE USING LINKEDLIST
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queuue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
void linkedlistraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(int argc, char const *argv[])
{

    enqueue(3);
    enqueue(4);
    enqueue(5);
    linkedlistraversal(f);
    printf("Dequeuing elment %d\n", dequeue());

    return 0;
}
