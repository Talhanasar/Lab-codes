#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>> &subset, int set[], int n, int sum)
{
    int x = 0, find ;
    int size;
    cout << "Subsets: ";
    if (subset[n][sum])
    {
        while (x == 0)
        {
            x = 1;
            find = sum;
            size = n;
            while (n > 0 && find > 0)
            {
                if (subset[size][find] && !subset[size - 1][find])
                {
                    cout << set[size - 1] << ", ";
                    find = find - set[size - 1];
                    x=0;
                }
                size--;
            }
        }
    }
    cout << endl;
}

bool isSubsetSum(int set[], int n, vector<vector<bool>> &subset, int sum)
{
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            else
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }

    return subset[n][sum];
}

int main()
{
    int set[] = {1, 2, 2, 4};
    int sum = 5;
    int n = sizeof(set) / sizeof(set[0]);
    vector<vector<bool>> subset(n + 1, vector<bool>(sum + 1, false));
    if (isSubsetSum(set, n, subset, sum) == true)
        cout << "Found a subset with the given sum" << endl;
    else
        cout << "No subset with the given sum" << endl;

    print(subset, set, n, sum);
    return 0;
}
