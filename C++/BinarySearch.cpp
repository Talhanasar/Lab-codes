#include <bits/stdc++.h>

using namespace std;

int BinarySearch(int arr[], int low, int high, int value)
{

    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
            return BinarySearch(arr, low, high, value);
        }
        else
        {
            high = mid - 1;
            return BinarySearch(arr, low, high, value);
        }
    }
    return -1;
}
int main()
{
    int n, find, low = 0;
        cout<<"Enter the number of elements: ";
        cin>> n;
        int arr[n];
        cout<<"Enter the elements: ";
        
        for(int i =0 ; i<n; i++){
            cin >> arr[i];
        }
       cout<<"Enter the value you want to Search: ";
        cin>>find;
        int ans = BinarySearch(arr,low,n-1,find);
        if(ans ==-1){
            cout<<"Value not found in the array.";
        }else cout<<"value found at index: "<<ans<<endl;
    return 0;
}