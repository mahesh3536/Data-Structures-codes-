#include<bits/stdc++.h>
using namespace std;
int mod=(int)1e9+7;
int power(int a,int b){
    if(b==0) return 1;
    int result=power(a,b/2);
    if(b%2==1) return ((result*result)%mod * a)%mod;
    else    return (result*result)%mod;
}
int range(int Arr[],int n){
    int maxi = 0;
    for(int i = 0;i<n;i++){
        maxi = max(maxi,Arr[i]);
    }
    return maxi+1;
}
void countingSort(int Arr[],int output[],int n){
    int r = range(Arr,n);
    int count[r];
    for(int i = 0;i<r;i++){
       count[i] = 0;
    }
    for(int i = 0;i<n;i++){
        count[Arr[i]]++;
    }
    for(int i = 1;i<r;i++){
        count[i] += count[i-1];
    }
    for(int i = 0;i<n;i++){
        output[--count[Arr[i]]] = Arr[i];
    }
    
}
int main(){
   int arr[7] = {78,6,5,4,3,2,1};
   int output[7];
   countingSort(arr,output,7);
   for(int i = 0;i<7;i++){
    cout << output[i] << " ";
   }
}