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
   void print(queue* q){
       queue* temp=q;
       while(!temp->empty()){
         cout<<temp->peek()<<" ";
         temp->pop();
       }
   }
};
int main(){
    queue* s = new queue();
    int val;
    do
    {

        cout << "1.Enter 1 for push" << endl;
        cout << "2.Enter 2 for pop" << endl;
        cout << "3.Enter 3 for checking that queue is empty or not " << endl;
        cout << "4.Enter 4 for getting the data of peek element" << endl;
        cout << "5.Enter 5 for getting the data of rear element"<< endl;
        cout << "6.Enter 6 for exit" << endl;
        cin >> val;
        switch (val)
        {
        case 1:
            {
            int d;
            cout << "Enter data for push:";
            cin >> d;
            s->push(d);
            }
            break;
        case 2:
            {
            cout << "Poping.." << endl;
            s->pop();
            }
            break;
        case 3:
            {
            bool t1 = s->empty();
            if (t1)
            {
                cout << "queue is empty" << endl;
            }
            else
                cout << "queue is not empty" << endl;
            }
            break;
        case 4:
            {
            int p = s->peek();
            if (p == -1)
                cout << "queue is empty" << endl;
            else
                cout << "The top element is : " << p << endl;
            }
            break;
        case 5:
         {
            bool flag = s->empty();
            if(flag) cout << "queue is empty" << endl;
            else {
               cout << "The rear element is : "<< s->back() << endl;
            }
         }
        
        }
    } while (val != 6);
   
}