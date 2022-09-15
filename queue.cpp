#include<iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }

};
class queue{
   public:
   Node* front;
   Node* rear;
   queue(){
     this->front=NULL;
     this->rear=NULL;
   }
   bool empty(){
     if(front==rear && front==NULL){
        return true;
     }
     else return false;
   }
   void push(int d){
     Node* temp=new Node(d);
     if(front==rear && front==NULL){
        front=temp;
        rear=temp;
     }
     else{
        rear->next=temp;
        temp->next=NULL;
        rear=temp;
     }
   }
   int peek(){
     if(front==rear && front==NULL){
        return -1;
     }
     else return front->data;
   }
   void pop(){
      if(front==rear && front==NULL) {
         cout<<"queue is empty"<<endl;
      }
      else{
         front=front->next;
      }
   }
   int back(){
     if(front==rear && front==NULL){
        return -1;
     }
     else return rear->data;
   }
   void print(queue q){
       queue temp=q;
       while(!temp.empty()){
         cout<<temp.peek()<<" ";
         temp.pop();
       }
   }
};
int main(){
    queue q;
    q.push(5);
    q.push(6);
   q.push(8);
    
   q.pop();
   
}