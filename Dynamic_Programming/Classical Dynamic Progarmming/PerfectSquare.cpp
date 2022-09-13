#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
int perfectSquare(int n){
	vector <int> dp (n + 1, 0) ; 
	dp[0] = 0 ; 
	dp[1] = 1 ; 
	for(int i = 2 ; i <= n ; i++){
		int ans = INT_MAX ; 
		for(int j = 1 ; j * j <= i ;j++){
			ans = min(ans , dp[i - (j * j)]) ; 
		}
		dp[i] = ans + 1 ;
	}
	return dp[n] ; 
}
int solve(){
	int n ; 
	cin >> n; 
	cout << perfectSquare(n) << endl ; 
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
