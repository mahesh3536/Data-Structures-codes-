#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid = (s+e)/2;
    int* first=new int[mid-s+1];
    int* second = new int[e-mid];
    int k = s;
    for(int i = 0 ; i<mid-s+1;i++){
        first[i]=arr[k++];
    }
     k = mid+1;
    for(int i = 0;i<=e-mid;i++){
       second[i]=arr[k++];
    }
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    int i=0, j=0;
    k = s;
    while(i < len1 && j < len2){
        if (first[i] < second[j]) {
            arr[k++] = first[i];
            i++;
        } else {
            arr[k++] = second[j];
            j++;
        }
    }

    while(i<len1) {
        arr[k++] = first[i++];
    }
    while(j<len2) {
        arr[k++]=second[j++];
    }
}
void mergesort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int mid = (s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int Arr[7]={4,1,2,6,7,2,9};
    mergesort(Arr,0,6);

    for (int i=0; i<7; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}