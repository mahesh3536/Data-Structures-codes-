#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
public:
  int *harr;
  int capacity;
  int heap_size;
  MinHeap(int cap)
  {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
  }
  void printArray()
  {
    for (int i = 0; i < heap_size; i++)
    {
      cout << harr[i] << " ";
    }
    cout << endl;
  }
  int height()
  {
    return ceil(log2(heap_size + 1)) - 1;
  }
  void insertKey(int val){
    if(heap_size == capacity){
      cout << "Overflow : heap full" << endl;
    }
    heap_size++;
    int i = heap_size-1;
    int parent = (i-1)/2;
    harr[i] = val;
    while(i!=0 && harr[parent]>harr[i]){
      swap(harr[parent],harr[i]);
      i = parent;
    }
  }
  void MinHeapify(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < heap_size && harr[left]<harr[smallest]){
      smallest = left ;
    }
    if(right < heap_size && harr[right]<harr[smallest]){
      smallest = right;
    }
    if(smallest != i){
      swap(harr[i],harr[smallest]);
      MinHeapify(smallest);
    }
  }
  int extractMin(){
    if(heap_size <= 0) return INT_MAX;
    if(heap_size==1){
      heap_size--;
      return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
  }
  void decreaseKey(int i,int new_val){
    harr[i] = new_val;
    int parent = (i-1)/2;
    while(i!=0 && harr[parent]>harr[i]){
      swap(harr[parent],harr[i]);
      i = parent;
    }
  }
  void deleteKey(int i){
    if(i>=heap_size) cout << "Enter valid Index" << endl;
    {
    decreaseKey(i,INT_MIN);
    extractMin();}
  }
  int getMin(){
    return harr[0];
  }
  void LinearSearch(int val){
    for(int i = 0;i<heap_size;i++){
      if(harr[i]==val){
        cout << "Key Found at index : " << i << endl;
        return; 
      }
    }
    cout << "Key not Found" << endl;
  }
};
int main()
{
  int s;
  cout << "Enter size of Min Heap" << endl;
  cin >> s;
  MinHeap obj(s);
  cout << "MinHeap Created" << endl;
  int option, val;
  do
  {
    cout << "What operation do you want to perform? "
         << "Select Option number. Enter 0 to exit." << endl;
    cout << "1.Insert Key" << endl;
    cout << "2.Search Key" << endl;
    cout << "3.Delete Key" << endl;
    cout << "4.Get Min" << endl;
    cout << "5.Extract Min" << endl;
    cout << "6.Height of Heap" << endl;
    cout << "7.Print Heap values " << endl;
    cout << "8.Clear Screen" << endl;
    cout << "0.Exit Program" << endl;
    cin >> option;
    switch (option)
    {
    case 0:
      break;
    case 1:
    {
      cout << "INSERT Operation - " << endl;
      cout << "Enter VALUE to insert in HEAP : ";
      cin >> val;
      obj.insertKey(val);
    }
    break;
    case 2:
    {
      cout << "SEARCH operation -" << endl;
      cout << "Enter VALUE to search in heap : " << endl;
      cin >> val;
      obj.LinearSearch(val);
    }
    break;
    case 3:
    {
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> val;
      obj.deleteKey(val);
    }
    break;
    case 4:
    {
      cout << "GET Min value : " << obj.getMin();
      cout << endl;
    }
    break;
    case 5:
    {
      // if(obj.extractMin()==INT_MAX) cout << "Heap is Empty"<< endl;
      cout << "EXTRACT Min value : " << obj.extractMin();
      cout << endl;
    }
    break;
    case 6:
    {
      cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
    }
    break;

    case 7:
    {
      cout << "PRINT Heap Array : " << endl;
      obj.printArray();

      cout << endl;
    }
    break;

    case 8:
    {
      system("cls");
    }
    break;

    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
}
