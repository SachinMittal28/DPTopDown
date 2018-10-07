#include<bits/stdc++.h>
using namespace std;

int IsSubsetSum(unordered_map<string, int> &dp, vector<int>  &set, int n, int sum){

    if(sum!=0 && n==0) return false;
    if(sum==0) return true;


    string key = to_string(n) + "|" + to_string(sum);

    if (dp.find(key) == dp.end()){
        auto x = IsSubsetSum(dp, set,n-1,sum);
        auto y = IsSubsetSum(dp, set,n-1,sum-set[n-1]);

        dp[key]=  x || y;
    }

    return dp[key];


}

int main() {


    vector<int> set = { 12, 1, 3, 8, 20, 50 };  //initialising vector
    int sum = 14;

    unordered_map<string, int> dp;
    int n = set.size();


    bool ans = IsSubsetSum(dp, set,n,sum);

    cout<<ans<<endl;

    return 0;
}
