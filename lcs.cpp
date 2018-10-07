#include<bits/stdc++.h> 
using namespace std;

int LCS(auto &dp, string X, string Y, int i, int j){
   
  
    if(i<0 || j<0) return 0;
    string key = to_string(i) + "|" + to_string(j);
    
    if (dp.find(key) == dp.end()){
        
        if(X[i] == Y[j])  
        dp[key] = LCS(dp, X, Y, i-1, j-1) + 1;
    
    else
       dp[key] = max(LCS(dp, X, Y, i, j-1),
                          LCS(dp,X, Y, i-1, j));
                          
    }
    
    
     return dp[key];
        

    
}

int main(){
    
    string X,Y;
    
    cin>>X>>Y;
    
    int m = X.size(), n=Y.size();
    
   unordered_map<string, int> dp;
  

    int ans = LCS(dp, X,Y, m-1, n-1);
    
    cout<<ans;
    
}