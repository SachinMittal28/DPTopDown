#include<bits/stdc++.h>
using namespace std;

int CountCoinChange(unordered_map<string, int> &dp, vector<int>  &set, int m, int n){

    if(n==0) return 1; // If n is 0 then there is 1 solution   (do not include any coin) 
    if(n<0) return 0;
    if(m==0 ) return 0;

    string key = to_string(m) + "|" + to_string(n);

    if (dp.find(key) == dp.end()){
       dp[key] = CountCoinChange(dp,set,m-1,n)+CountCoinChange(dp,set,m,n-set[m-1]);
    }

    return dp[key];


}

int main() {


    vector<int> set = { 1,2,3};  //initialising vector
    int n = 4;

    unordered_map<string, int> dp;
    int m = set.size();
    

    int ans = CountCoinChange(dp, set,m,n);

    cout<<ans<<endl;

    return 0;
}
