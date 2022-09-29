//circular queue implementation 
#include<iostream>
using namespace std;
class Queue{
    public:
    int* arr;
    int f;
    int r;
    int size;
    Queue(int d){
       this->size=d;
       arr = new int[d];
       this->f=-1;
       this->r=-1;
    }
    bool isEmpty(){
        if(f==-1 && r==-1) return true;
        else return false;
    }
    bool isFull(){
        if((r+1)%size == f) return true;
        else return false;
    }
    int front(){
        if(f==-1 && r == -1){
            cout << "Queue is empty" << endl;
            return 0;
        }
        else{
            return arr[f];
        }
    }
    int rear(){
        if(f==-1 && r==-1){
            cout << "Queue is empty" << endl;
            return 0;
        }
        else return arr[r];
    }
    void enQueue(int val){
        if((r+1)%size == f){
            cout << "Queue is Full" << endl;
            return;
        }
        else if(f==-1 && r==-1){
            f++;
            r++;
            arr[r]=val;
        }
        else{
            r = (r+1)%size;
            arr[r]=val;
        }
    }
    int deQueue(){
        if(f==-1 && r==-1){
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if(f==r){
            int x = arr[f];
            f=-1;
            r=-1;
            return x;
        }
        else{
            int x = arr[f];
            f = (f+1)%size;
            return x;
        }
    }
};
int main(){
   int size;
   cout << "Enter size of Queue : " ;
   cin >> size;
   Queue Q(size);
   int val;
   do{
      cout << "1.Enter 1 for isEmpty" << endl;
      cout << "2.Enter 2 for isFull" << endl;
      cout << "3.Enter 3 for enQueue"<< endl;
      cout << "4.Enter 4 for deQueue"<<endl;
      cout<< "5.Enter 5 for front element"<<endl;
      cout<< "6.Enter 6 for rear element"<<endl;
      cout<< "7.Enter 7 for exit"<< endl;
      cin >> val;
      switch(val){
        case 1:
        {
            if(Q.isEmpty()) cout << "Queue is empty" << endl;
            else cout << "Queue is not empty" << endl;
        }
        break;
        case 2:
        {
            if(Q.isFull()) cout << "Queue is Full" << endl;
            else cout << "Queue is not Full" << endl;

        }
        break;
        case 3:
        {   if(Q.isFull()){
               cout << "Queue is Full" << endl;
            }
            else{
            int data;
            cout << "Enter data for enQueue : " ;
            cin >> data;
            Q.enQueue(data);
            cout << "enQueue done" << endl;
            }
        }
        break;
        case 4:
        {
            if(Q.isEmpty()) cout << "Queue is Empty" << endl;
            else {
                cout << "DeQueue element of Queue is : ";
                cout << Q.deQueue() << endl;
                
            }
        }
        break;
        case 5:
        {
            if(Q.isEmpty()) cout << "Queue is Empty" << endl;
            else {
                cout << "Front element of Queue is : " << Q.front() << endl;
            }
        }
        break;
        case 6:
        {
           if(Q.isEmpty()) cout << "Queue is Empty" << endl;
           else {
               cout << "Rear element of Queue is : " << Q.rear() << endl;
           }
        }
      }
   }while(val!=7);
}