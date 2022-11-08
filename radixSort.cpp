#include<iostream>
using namespace std;
int getMax(int Arr[],int n){
    int maxi = Arr[0];
    for(int i = 0;i<n;i++){
        maxi = max(maxi,Arr[i]);
    }
    return maxi;
}
void countingSort(int Arr[],int n,int div){
    int range = 10;
    int count[range];
    int output[n];
    for(int i = 0;i<range;i++){
        count[i] = 0;
    }
    for(int i = 0;i<n;i++){
        count[(Arr[i]/div)%10]++;
    }
    for(int i = 1;i<range;i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i =n-1;i>=0;i--){
        output[--count[(Arr[i]/div)%10]] = Arr[i];
    }
    for(int i = 0;i<n;i++){
        Arr[i] = output[i];
    }
}
void radixSort(int Arr[],int n){
   int m = getMax(Arr,n);
   for(int div = 1; m/div > 0;div*=10){
    countingSort(Arr,n,div);
   }
}
int main(){
   int Arr[7] = {890,56,7890,3,2,1,5};
   radixSort(Arr,7);
   for(int i = 0;i<7;i++){
    cout << Arr[i] << " ";
   }

}