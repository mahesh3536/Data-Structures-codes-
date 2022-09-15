/*#include<bits/stdc++.h>
//#include<stack>
#include<new>
using namespace std;*/
//1.reverse a string using stack
/*int main(int argc, char const *argv[])
{
    string str="mahesh";
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while (!s.empty())
    {
       char ch=s.top();
       ans.push_back(ch);
       s.pop();
    }
    cout<<ans;

    return 0;
}*/
//2.find middle elment in stack and delte it
/*void solve(stack<char>&s,int count,int size)
{
    if (count==size/2)
    {
        s.pop();
        
        

        return;
    }
    int num=s.top();
    s.pop();
    solve(s,count+1,size);
    s.push(num);
}
int main()
{
    string str;
    cin>>str;
    stack<char> s;
    for (int i = 0; i < str.length();i++)
    {
        char ch = str[i];
        s.push(ch);

    }
    solve(s,0,str.size());
    return 0;
}*/
/*bool isValidParenthesis(string expression)
{
    stack<char>s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch=expression[i];
        if (ch=='(' || ch=='{' || ch=='[')
        {
           s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
               char top=s.top();
               if ((ch==')'&& top=='(') || (top=='{' && ch=='}') || (ch==']' && top=='['))
               {
                   s.pop();
               }
               else{
                   return false;
               }
               
            }
            else{
                return false;
            }
            
        }
       
        
        
    }
if (s.empty())
        {
            return true;
        }
        else {return false;}
    
}
void solve(stack<int>&s,int x){
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
    
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
void solve(stack<int>&s,int x){
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
    
}
void reverse(stack<int>&s){
    if (s.empty())
    {
        //s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    reverse(s);
    //s.push(num);
    solve(s,num);

    
}
void reverseStack(stack<int> &stack) {
    solve(stack);
    return stack;
}
void sorted(stack<int> &stack,int num){
    if (stack.empty() || (!stack.empty() && stack.top()<num))
    {
        stack.push(num);
    }
    int n=stack.top();
    stack.pop();
    sorted(stack,num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if (stack.empty())
    {
        //s.push(x);
        return;
    }
    int num=stack.top();
    s.pop();
    sortStack(stack);
    //s.push(num);
    sorted(stack,num);

}
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
       char ch=s[i]
       if (ch=='(' || ch=='*' || ch=='-' || ch=='+' || ch=='/')
       {
           st.push(ch);
       }
       else
       {
           if (ch==')')
           { bool isRedundunt true;
               while (st.top() !='(')
               {
                   char top=st.top();
                   if ( top=='*' || top=='-' || top=='+' || top=='/')
                   {
                      isRedundunt=false;
                   }
                   st.pop();
               }
              if (isRedundunt==true)
              {
                  return true;
              }
              st.pop();
               
           }
           
       }
       
       
    }
    return false;
    
}
int findMinimumCost(string str) {
    if (str.length()%2!=0)
    {
        return -1;
    }
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch=str[i];
        if (ch=='{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty() && s.top=='{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
            
            
        }
       int a=0, b=0;
       while (!s.empty())
       {
           if(s.top=='{'){
               b++;
           }
           else
           {
               a++;
           }
           s.pop();
           
       }
       
       int ans =(a+1)/2 + (b+1)/2 ;
   return ans; 
        
    }
    
   //int ans =(a+1)/2 + (b+1)/2 ;
   //return ans;
}
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   stack<int> s;
   s.push(-1);
   vector<int> ans;
   for (int i = n-1; i>=0; i++)
   {
       int curr=arr[i];
       while (s.top()>=curr)
       {
          s.pop();
       }
       ans[i]=s.top();
       s.push(curr);
   }
   return ans;
}
int largestRectangle(vector < int > & heights) {
    int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights,n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights,n);
    int area=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l=heights[i];
        int b=next[i]-prev[i]-1;
        if (next[i]==-1)
        {
            next[i]=n;
        }
        
        int newarea=l*b;
        area=max(area,newarea);
    }
    
 }*/
/*void reverseArray(vector<int> &arr , int m)
{
	int n=v.size();
    for (int i = m+1; i < (n-m)/2; i++)
    {
        swap(v[i],v[n-i]);
    }
    
}
int sumOfMaxMin(int arr[], int n){
	int maxi=INT_MIN;
    int mini=INT_MAX;
	for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,arr[i]);
        mini=min(mini,arr[i]);
    }
    cout<<maxi+mini;
}
vector<int> separateNegativeAndPositive(vector<int> &nums){
    vector<int> ds;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i]<0)
        {
           ds.push_back(nums[i]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i]>0)
        {
           ds.push_back(nums[i]);
        }
        
    }
   return ds;
    
}*/
/*pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	  int maxi=max(n,m);
      for (int i = 0; i < maxi; i++)
      {
          
      }
         
}
#include<bits/stdc++.h>
using namespace std;


/*int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    
    
    return 0;
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{   int n=arr.size();
	sort(arr.begin(),arr.end());
    vector<int> v(2);
    v[0]=arr[k+1];
    v[1]=arr[n-k+1];
    return (vector<int> v(2));
}
int minimizeIt(vector<int> A, int K)
{  int n=A.size();
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i]<=K)
        {
           A[i]=A[i]+K;
        }
        else
        {
            A[i]=A[i]-K;
        }
        
    }
   sort(A.begin(),A.end());
   return (A[n]-A[0]);
}
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int l=0;
   int mid=0;
   int hi=n-1;
   while (mid<=hi)
   {
      switch(arr[mid]){
            
        case 0:
           swap(arr[l++],arr[mid++]);
           break;
        case 1:
           mid++;
           break;
        case 2:
           swap(arr[mid],arr[hi--]);
           break;
      }
   }
   
   
}
void bubbleSort(vector<int>& arr, int n)
{   
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; i++)
        {
            swap(arr[j],arr[j+1]);
        }
        
    }
    
}
void insertionSort(int n, vector<int> &arr){
   sort(arr.begin(),arr.end());

}*/
/*int main()
{
    long long n,t;
    cin>>n;
    while (n--)
    {
        cin>>t;
        int* ptr;
        for (int i = 0; i < t; i++)
        {
            cin>>ptr[i];

        }
        
        
    }
    
    return 0;
}*/
/*int main()
{
    long long n,a,b,c,x,y;
    cin>>n;
    while (n--)
    {
        cin>>a>>b>>c>>x>>y;
        if (a>=x && b>=y)
        {
            cout<<"YES";
        }
        else if (a>=x && b<y && c>=y-b)
        {
            cout<<"YES";
        }
        else if (a<x && b>=y && c>=x-a)
        {
            cout<<"YES";
        }
        else if (a<x && b<y && c>=x+y-a-b)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        
    }
    
    return 0;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
   if (head->next==NULL || head==NULL)
   {
       return head;
   }
   Node* prev=NULL;
   Node* curr=head;
   Node* forward=NULL;
   while (curr!=NULL)
   {
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward;
   }
   return head;
   
}
#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int n,x,y;
    cin>>n;
    while (n--)
    {
       cin>>x>>y;
       if (x>y)
       {
           /* code */
           /*cout<<"YES";
       }
       else
       {
           cout<<"NO";
       }
       
    }
    
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    

    return 0;
}


