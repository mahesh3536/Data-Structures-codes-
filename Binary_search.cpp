#include<iostream>
using namespace std;

int binarysearch(int arr[], int size, int key){
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    while (start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }
       if (key>arr[mid])
       {
           start=mid+1;
       }
       else
       {
           end=mid-1;
       }
       
       mid=start + (end-start)/2;
        
    }
  return -1;  
}
int main()
{
    //cout<<"hello world";
    int even[6]={2,4,6,8,10,12};
    
    int index=binarysearch(even, 6, 12);
    cout<<"The index of 12 is "<<index<<endl;
}
/*
int firstocr(int arr[], int size, int key){
    int start=0;
    int end=size-1;
    int mid=start + (end-start)/2;
    int ans=-1;
    while (start<=end)
    {
        if (arr[mid]==key)
        {   
           ans=mid;
           end=mid-1; 
        }
       if (key>arr[mid])
       {
           start=mid+1;
       }
       else
       {
           end=mid-1;
       }
       
       mid=start + (end-start)/2;
        
    }
  return ans;  
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,
}
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int s=0;
       int e=arr.size()-1;
       int mid = s + (e-s)/2;
       while (s<e)
       {
           if (arr[mid]<arr[mid+1])
           {
               s=mid+1;
           }
           else
           {
               e=mid;
           }
           mid = s + (e-s)/2;
           
       }
      return s; 
    }
};*/
/*int getPivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    while (s<e)
    {
        if (arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        
       mid = s + (e-s)/2; 
    }
    return s;
    
}
int main(int argc, char const *argv[])
{
    int arr[5]={8,10,17,1,3};
    cout<<"Pivot is "<<getPivot(arr,5)<<endl;
    return 0;
}
int getPivot(vector<int>& arr,int n){
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    while (s<e)
    {
        if (arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        
       mid = s + (e-s)/2; 
    }
    return s;
    
}
int binarysearch(int arr[], int s, int e, int key){
    int start=s;
    int end=e;
    int mid=start + (end-start)/2;
    while (start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }
       if (key>arr[mid])
       {
           start=mid+1;
       }
       else
       {
           end=mid-1;
       }
       
       mid=start + (end-start)/2;
        
    }
  return -1;  
}
int findPosition(vector<int>& arr, int n, int k)
{
   int pivot = getPivot(arr,n);
   if (k>=arr[pivot] && k<=arr[n-1])
   {
      return binarysearch(arr,pivot,n-1,k);
   }
   else
   {
       return binarysearch(arr,0,pivot-1,k);
   }
   
   
}*/
// long long int sqrtInteger(int n){
//     int s=0;
//     int e=n;
//     long long int mid = s + (e-s)/2;
//     int ans=-1;
//     while (s<=e)
//     {
//         long long int square = mid*mid;
//         if (square==n)
//         {
//             return mid;
//         }
//         if (square<n)
//         {
//            ans=mid;
//            s=mid+1;
//         }
//         else
//         {
//             e=mid-1;
//         }
        
//        mid = s + (e-s)/2; 
//     }
//     return ans;
// }
// double moreprecise(int n,int precision,int tempsol){
//     double factor = 1;
//     double ans = tempsol;
//     for (int i = 0; i < precision; i++)
//     {
//         factor = factor/10;
//         for (double j = ans ; j*j < n ; j=j+factor)
//         {
//            ans = j; 
//         }
        
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cout<<"enter the number "<<"\n";
//     cin>>n;
//     int tempsol = sqrtInteger(n);
//     cout<<tempsol<<endl;
//     cout<<moreprecise(n,4,tempsol);
//     return 0;
// }





