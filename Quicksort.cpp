#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int swap;
    do{

        while (pivot >= arr[i]){
            i++;
        }
        while (pivot < arr[j]){
            j--;
        }
        if (i < j){
            swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    } while (i < j);
    swap = arr[low];
    arr[low] = arr[j];
    arr[j] = swap;
    return j;
}
void Sort(int arr[],int low, int high){
    if(low<high){
        int n  = partition(arr,low,high);
        Sort(arr,low,n-1);
        Sort(arr,n+1,high);
    }
}
int main(){
    int arr [] = { 4, 6, 3, 8, 2, 5, 1};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Array before sorting: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    Sort(arr, 0, n-1);
    cout<<"Array after sorting: ";
    for (int j = 0; j < n; j++){
        cout<<arr[j]<<" ";
    }
    
    return 0;
}