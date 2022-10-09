#include<iostream>
using namespace std;
class Node{
   public:
   int data;
   Node* next;
   Node(int d){
    this->data = d;
    this->next = NULL;
   }
};
void insert(Node* dummy){
    Node* head = new Node(2);
    dummy->next = head;
    Node* head1 = new Node(5);
    head->next = head1;
}
int main(){
    Node* dummy ;
    dummy=NULL;
    insert(dummy);
    cout << dummy->next->next->data;
}