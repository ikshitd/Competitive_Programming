#include <bits/stdc++.h> 
#define int long long int
using namespace std ; 
void solve(){
	int n = 10 ; 
	int dp[n + 1] ; 
	dp[0] = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		dp[i] = dp[i / 2] + (i & 1) ; 
		cout << i << " " << dp[i] << endl ; 
	}
	cout << endl ;
	return ; 
}
int32_t main(){
	int t = 1 ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
