#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}
int main(){
    int arr[7] = {7,2,3,1,5,6,4};
    bubbleSort(arr,7);
    for(int i = 0;i<7;i++){
        cout << arr[i] << " ";
    }
}