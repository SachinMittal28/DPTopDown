#include<bits/stdc++.h>
using namespace std;

int LIS(auto &dp, vector<int>  &set, int n){
    
    
    if(n==0) return 1;
    int key = n;
    
    if (dp.find(key) == dp.end()){
        
        int m = 0;
        
        for (int k=0; k<n;k++){
            if(set[k]<set[n])
                m= max(m, LIS(dp, set, k));
        }
        
        dp[key]=m+1; //if doesnt enter in above for loop then it will be 1
    }
    
    
    return dp[key];
    
}

int main(){
    
    vector<int> set = { 3, 10, 2, 1, 20};  //initialising vector
    
    unordered_map<int, int> dp;
    
    int ans = LIS(dp, set, set.size()-1);
    
    cout<<ans;
    
}
