#include <bits/stdc++.h>
using namespace std;
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    int arr[7] = {4, 2, 5, 1, 3, 8, 7};
    insertionsort(arr, 7);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}