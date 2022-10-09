#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i = 0;i<n;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex]) minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
}
int main(){
   int arr[7]={7,6,5,4,3,2,1};
   selectionSort(arr,7);
   for(int i = 0;i<7;i++){
    cout << arr[i] << " ";
   }
   cout << endl;
}