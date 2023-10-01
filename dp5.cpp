#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum, int dp[][1001]) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            if(arr[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int n = 4;
    int arr[n] = {1,2,3,3,};
    // int arr[n] = {1,1,1,1};
    int sum = 6;

    int dp[n+1][1001];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= n; i++) {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
        }

    }

    int ans = solve(arr, n, sum, dp);
    cout << ans << endl;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}