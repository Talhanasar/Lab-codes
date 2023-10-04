#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1;
    int b[high + 1];
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        }
        else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high) {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++) {
        arr[x] = b[x];
    }
}

void Sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        Sort(arr, low, mid);
        Sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Sort(arr, 0, n - 1);
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}