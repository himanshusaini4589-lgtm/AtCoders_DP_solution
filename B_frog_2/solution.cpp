#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Approach 1 --- Recursion
int f(int ind, vector<int>& height, int k){
    if(ind == (int)height.size()-1) return 0;
    int ans = 1e9;
    for(int i = 1; i <= k; i++){
        if(ind+i >= (int)height.size()) break;
        ans = min(ans, abs(height[ind]-height[ind+i]) + f(ind+i, height, k));
    }
    return ans;
}

// Approach 2 --- Memoization
int f_memo(int ind, vector<int>& height, int k, vector<int>& dp){
    if(ind == (int)height.size()-1) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ans = 1e9;
    for(int i = 1; i <= k; i++){
        if(ind+i >= (int)height.size()) break;
        ans = min(ans, abs(height[ind]-height[ind+i]) + f_memo(ind+i, height, k, dp));
    }
    return dp[ind] = ans;
}

// Approach 3 --- Tabulation
int f_dp(vector<int>& height, int k, vector<int>& dp){
    dp[height.size()-1] = 0;
    for(int ind = height.size()-2; ind >= 0; ind--){
        int ans = 1e9;
        for(int i = 1; i <= k; i++){
            if(ind+i >= (int)height.size()) break;
            ans = min(ans, abs(height[ind]-height[ind+i]) + dp[ind+i]);
        }
        dp[ind] = ans;
    }
    return dp[0];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];
    vector<int> dp(n, -1);
    cout << f_dp(height, k, dp);
}