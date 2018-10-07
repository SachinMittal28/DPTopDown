#include<bits/stdc++.h> 
using namespace std;

int knapsac(auto &dp,int k, auto &v, auto &w, int W){
     
     if(k<0 ) return 0;
    string key = to_string(k) + "|" + to_string(W);
    
    if (dp.find(key) == dp.end()){
        
        if(w[k]>W) dp[key]= knapsac(dp,k-1, v, w, W);
        else
        dp[key]= max(knapsac(dp,k-1, v, w, W), v[k]+knapsac(dp,k-1, v, w, W-w[k]));
    }
    
    return dp[key];
        
        
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t-->0){
	   
	   int n,W;
	   cin >>n>>W;
	   
	   vector<int> v, w;
	   
	   int x;
	   
	   for (int i=0; i<n; i++){
	       cin>>x;
	       v.push_back(x);
	   }
	   
	   for (int i=0; i<n; i++){
	         cin>>x;
	       w.push_back(x);
	   }
	   
	  unordered_map<string, int> dp;
    
        int ans = knapsac(dp,n-1, v, w, W);
        
        cout<<ans<<endl;
	    
	}
	
	
	
	return 0;
}

/*
Input
1
3
4
1 2 3
4 5 1

Output:
3
*/