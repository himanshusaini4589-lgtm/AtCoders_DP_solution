#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> a;
unordered_map<int, long long> mp;

long long f(int i,int mask){

    if(i == n) return 1;


    if(mp.count(mask)) return mp[mask];

    long long ans = 0;
    for(int j = 0; j < n; j++){
        if(!(mask &(1<<j)) && a[i][j] == 1){

            ans = (ans + f(i + 1,(mask | (1<<j)))) % MOD;
        }
    }

    return mp[mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << f(0,0) << "\n";
    return 0;
}