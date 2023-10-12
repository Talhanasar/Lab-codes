#include <bits/stdc++.h>
using namespace std;

int countAndListSubsetsWithSum(vector<int>& arr, int sum, vector<int>& subset, int index) {
    int n = arr.size();
    if (index == n) {
        if (sum == 0) {
            cout << "Subset: ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
            return 1; // Found a valid subset
        }
        return 0; // Not a valid subset
    }

    int count = 0;

    // Include the current element in the subset
    subset.push_back(arr[index]);
    count += countAndListSubsetsWithSum(arr, sum - arr[index], subset, index + 1);

    // Exclude the current element from the subset
    subset.pop_back();
    count += countAndListSubsetsWithSum(arr, sum, subset, index + 1);

    return count;
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    vector<int> subset;

    int totalCount = countAndListSubsetsWithSum(arr, sum, subset, 0);
    cout << "Total number of subsets with sum " << sum << ": " << totalCount << endl;

    return 0;
}
