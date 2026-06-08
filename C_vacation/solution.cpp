#include<iostream>
using namespace std;

// approach 1 -- recursive way of doing this vacation problem
int f(vector<vector<int> >&v , int ind ,int taken,vector<vector<int> >&dp){
    if(ind>=v.size()) return 0;
    if(dp[ind][taken] != -1) return dp[ind][taken];
    int points = 0;
    if(taken == 0){
        points += max(v[ind][1] + f(v,ind+1,1,dp) ,v[ind][2] + f(v,ind+1,2,dp));
    }

    else if(taken == 1){
        points += max(v[ind][0] + f(v,ind+1,0,dp) ,v[ind][2] + f(v,ind+1,2,dp));
    }
    else if(taken == 2){
        points += max(v[ind][0] + f(v,ind+1,0,dp) ,v[ind][1] + f(v,ind+1,1,dp));
    }

    return dp[ind][taken] = points;
}

//tabulation way of doing this problem

int f_dp(vector<vector<int>>& v, vector<vector<int>>& dp){
    int n = v.size();
    
    // base case - first index
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int ind = 1; ind < n; ind++){
        dp[ind][0] = v[ind][0] + max(dp[ind-1][1], dp[ind-1][2]);
        dp[ind][1] = v[ind][1] + max(dp[ind-1][0], dp[ind-1][2]);
        dp[ind][2] = v[ind][2] + max(dp[ind-1][0], dp[ind-1][1]);
    }

    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}


int f_dp_space_optmization(vector<vector<int>>& v){
    int n = v.size();
    vector<int>prev(3);
    // base case - first index
    prev[0] = v[0][0];
    prev[1] = v[0][1];
    prev[2] = v[0][2];

    for(int ind = 1; ind < n; ind++){
        vector<int>curr(3);
        curr[0] = v[ind][0] + max(prev[1], prev[2]);
        curr[1] = v[ind][1] + max(prev[0], prev[2]);
        curr[2] = v[ind][2] + max(prev[0], prev[1]);
        prev = curr;
    }

    return max({prev[0], prev[1], prev[2]});
}

int main(){
    int n;
    cin>>n;

    vector<vector<int> >v;
    for(int i = 0 ; i<n ; i++){
        int x,y,z;
        cin>>x>>y>>z;
        vector<int>c = {x,y,z};
        v.push_back(c);
    }
    vector<vector<int> >dp(100005,vector<int>(3,-1));
    // int ans = 0 ;
    // for(int i = 0 ; i<3 ; i++){
    //     ans = max(v[0][0] + f(v,1,0,dp) , max(v[0][1] + f(v,1,1,dp),v[0][2] + f(v,1,2,dp)));
    // }
    // dp.clear();
    // int ans_2 = f_dp(v,dp);
    //cout<<ans_2<<endl;
    int ans = f_dp_space_optmization(v);
    cout<<ans<<endl;
}