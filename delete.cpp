#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int solve(vector<int>& cost,int n)
{
    if(n==0||n==1)
        return cost[n];
    else 
        return min(solve(cost,n-1),solve(cost,n-2))+cost[n];

}
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // int ans=min(solve(cost,n-1),solve(cost,n));
        // return ans;
        return solve(cost,n-2);

    }
int main()
{
    vector<int> cost={10,15,20};
    int ans=minCostClimbingStairs(cost);
    cout<<ans;
 return 0;
}