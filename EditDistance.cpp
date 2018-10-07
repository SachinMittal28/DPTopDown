#include<bits/stdc++.h> 
using namespace std;
int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 


int EditDistance(auto &dp, string X, string Y, int i, int j){
   
  
    if(i==0) return j;
    if(j==0) return i;
    
    string key = to_string(i) + "|" + to_string(j);
    
    if (dp.find(key) == dp.end()){
        
        if(X[i] == Y[j])  // If last characters are same, ignore last char 
        dp[key]= EditDistance(dp, X, Y, i-1, j-1); 
        
        else 
        dp[key] = 1+min(EditDistance(dp, X, Y, i, j-1),
                      EditDistance(dp,X, Y, i-1, j),
                      EditDistance(dp, X, Y, i-1, j-1));
                          
    }
    
    
     return dp[key];
        

    
}

int main(){
    
    string X,Y;
    
    cin>>X>>Y;
    
    int m = X.size(), n=Y.size();
    
   unordered_map<string, int> dp;
  

    int ans = EditDistance(dp, X,Y, m-1, n-1);
    
    cout<<ans;
    
}