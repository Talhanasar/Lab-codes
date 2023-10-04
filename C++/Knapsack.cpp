#include<bits/stdc++.h>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int m = 1; m <= W; m++) {
            if (weights[i - 1] <= m) {
                dp[i][m] = max(values[i - 1] + dp[i - 1][m - weights[i - 1]], dp[i - 1][m]);
            } else {
                dp[i][m] = dp[i - 1][m];
            }
        }
    }
    int l = n , j = W;
    cout<<"Weights taken: ";
    while(l>0 && j>0){
        if(dp[l][j] != dp[l-1][j]){
            cout<< weights[l-1]<<", ";
            j = j - weights[l-1];
        }
        l--;
    }
    cout<<endl;
    return dp[n][W];
}
int main() {
    int n = 3, W = 50;
    vector<int> weights = {10, 20, 30 };
    vector<int> values = {60, 100, 120};
    int max_value = knapsack(W, weights, values, n);

    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
