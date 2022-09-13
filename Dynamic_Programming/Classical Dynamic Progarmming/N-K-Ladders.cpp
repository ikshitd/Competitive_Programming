#include <bits/stdc++.h> 
#define int long long int
using namespace std ; 
const int N = 1e3 ; 
// O{k ^ n}
int countways(int n , int k){
	if(n == 0){
		return  1 ;
	}
	int ans = 0 ; 
	for(int jump = 1 ; jump <= k ; jump++){
		if(n - jump >= 0)
			ans += countways(n - jump , k) ; 
	}
	return ans ; 
}
int countwaystopdown(int n , int k , int dp[]){
	if(n == 0){
		return 1 ; 
	}
	if(dp[n] != 0){
		return dp[n] ; 
	}
	int ans = 0 ; 
	for(int j = 1 ;j  <= k ; j++){
		if(n - j >= 0){
			ans += countwaystopdown(n - j , k , dp) ; 
		}
	}
	return dp[n] = ans ; 
}
// O(nk) ; 
int countwaysbottomup(int n ,int k){
	int dp[n + 1] = {0} ; 
	dp[0] = 1 ; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= k ;j++){
			if(i - j >= 0){
				dp[i] += dp[i - j]  ; 
			}
		}
	}
	return dp[n] ; 
}
// O(n) ; 
int countwaysopt(int n , int k){
	int dp[n + 1] = {0} ; 
	dp[0] = dp[1] = 1 ; 
	for(int i = 2 ; i <= n ; i++){
		dp[i] = 2 * dp[i - 1] ; 
	}
	for(int i = k + 1 ; i <= n ; i++){
		dp[i] -= dp[i - k - 1] ; 
	}
	return dp[n] ; 
}
void solve(){
	int n , k ; 
	cin >> n >> k ; 
	int dp[N] = {0} ; 
	cout << countways(n , k) << endl ; 
	cout << countwaystopdown(n , k , dp) << endl ; 
	cout << countwaysbottomup(n , k) << endl ; 
	cout << countwaysopt(n , k) << endl ; 
	return ; 
} 
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}	
