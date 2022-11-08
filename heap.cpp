#include<bits/stdc++.h>
using namespace std;
class Heap{
  public:
  vector<int> v = {0};
  int size = 0;
  //max -heap 
  void insert(int val){
    size = size + 1;
    int index = size;
    v[index] = val;
    while(index>1){
        int parent = index/2;
        if(v[index]>v[parent]){
            swap(v[index],v[parent]);
            index = parent;
        }
        else return;
    }
  }
  //deletion of root node 
  void deleteRoot(){
    if(size==0){cout << "Nothing To Delete" << endl;return;}
    v[1] = v[size];
    size = size-1;
    int index = 1;
    while(index<size){
        int largest = index;
        int child1=2*index;
        int child2 = 2*index + 1;
        if(child1<=size && v[index]<v[child1]){
            largest = child1;
        }
        if(child2<=size && v[index]<v[child2]){
            largest = child2;
        }
        if(index!=largest){
            swap(v[index],v[largest]);
            index = largest;
        }
        else return;
    }
  }
  void print(){
    for(int i =1 ;i<=size;i++){
        cout << v[i] << " ";
    }
    cout << endl;
  }
};
int main(){
   Heap h ;
   h.insert(89);
   h.insert(90);
   h.insert(91);
   h.insert(78);
   h.insert(67);
   h.insert(1);
   h.deleteRoot();
   h.insert(56);
   cout << "hello" << endl;
   h.print();
   cout << "hello there" << endl;
}