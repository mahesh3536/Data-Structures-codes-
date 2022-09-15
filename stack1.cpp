#include<iostream>
using namespace std;
class stack{
     public:
      int *arr;
      int top;
      int size;
      stack(int d){
        this->size=d;
        arr = new int[d];
        top=-1;
      }
      void push(int data ){
            if(size-top>1){
                top++;
                arr[top]=data;
            }
            else{
                cout<<"stack overflow";
            }
      }
      void pop(){
           if(top>=0){
               top--;
           }
           else{
             cout<<"stack is empty";
           }
      }
      int peek(){
           if(top>=0 && top<size) return arr[top];
           else{
             cout<<"stack is empty"<<endl;
             return -1;
           }
      }
      bool empty(){
          if(top==-1) return true;
          else return false;
      }
};
int main(){
   stack st(5);
   st.push(44);
   cout<<st.peek();
   st.push(56);
   st.push(34);
   st.pop();
   cout<<endl<<st.peek();
}