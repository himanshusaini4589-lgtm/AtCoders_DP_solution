#include<iostream>
using namespace std;

// approach 1 --- recursion 
int f(int ind,vector<int>&height){
    if(ind<0) return 1e9;
    if(ind==0) return 0;
    int cost_for_1_step = 1e9;
    if(ind-1>=0){
        cost_for_1_step = abs(height[ind]-height[ind-1]) + f(ind-1,height);
    } 
    int cost_for_2_step = 1e9; 
    if(ind-2>=0){
        cost_for_2_step = abs(height[ind]-height[ind-2]) + f(ind-2,height);
    }

    return min(cost_for_1_step,cost_for_2_step);
}

// approach 2 --- Dp with memoization
int fdp(int ind,vector<int>&height,vector<int>&dp){
    if(ind<0) return 1e9;
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int cost_for_1_step = 1e9;
    if(ind-1>=0){
        cost_for_1_step = abs(height[ind]-height[ind-1]) + fdp(ind-1,height,dp);
    } 
    int cost_for_2_step = 1e9; 
    if(ind-2>=0){
        cost_for_2_step = abs(height[ind]-height[ind-2]) + fdp(ind-2,height,dp);
    }

    return dp[ind] = min(cost_for_1_step,cost_for_2_step);
}

// approach 3 -- Dp with 1D vector (stack optimization)
int fd(vector<int>&height,vector<int>&dp){
    
    dp[0] = 0;

    for(int ind = 1 ; ind<height.size() ; ind++){
        int cost_for_1_step = 1e9;
        if(ind-1>=0){
            cost_for_1_step = abs(height[ind]-height[ind-1]) + dp[ind-1];
        } 
        int cost_for_2_step = 1e9; 
        if(ind-2>=0){
            cost_for_2_step = abs(height[ind]-height[ind-2]) + dp[ind-2];
        }

        dp[ind] = min(cost_for_1_step,cost_for_2_step);
    }
    return dp[height.size()-1];
}

//approach 4 -- DP with pointer only (space optimization)
int f_pointer(vector<int>&height){
    int prev = 0;
    int prev2 = 0;

    for(int ind = 1 ; ind<height.size() ; ind++){
        int curr = 0;
        int cost_for_1_step = 1e9;
        if(ind-1>=0){
            cost_for_1_step = abs(height[ind]-height[ind-1]) + prev;
        } 
        int cost_for_2_step = 1e9; 
        if(ind-2>=0){
            cost_for_2_step = abs(height[ind]-height[ind-2]) + prev2;
        }

        curr = min(cost_for_1_step,cost_for_2_step);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int>height;
    for(int i = 0 ; i<n ; i++){
        int h;
        cin>>h;
        height.push_back(h);
    }
    vector<int>dp(100004,-1);
    dp.clear();

    int ans = f_pointer(height);
    cout<<ans;
}