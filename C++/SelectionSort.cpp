#include<bits/stdc++.h>

using namespace std;

void print(int arr[], int n){
 for (int i = 0; i < n; i++)
 {
    cout<<arr[i]<< ", ";
 }
    cout<<endl;
}

void Sort(int arr[], int n){
    int minindex , temp;
    for (int i = 0; i < n-1; i++)
    {
        minindex = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[minindex]){
                minindex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
        
    }
    
}

int main(){
    int arr[] = {2,6,3,9,1,12};
    int n = 6;
    cout<<"Array before sorting: ";
    print(arr,n);
    Sort(arr, n);
    cout<<"Array after sorting: ";
    print(arr,n);
    return 0;
}