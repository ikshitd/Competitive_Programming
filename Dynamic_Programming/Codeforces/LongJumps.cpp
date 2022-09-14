#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int mod = 1e9 + 7 ; 
const int N = 2e5 ; 
int arr[N] , dp[N] ; 
int n  ; 
int maxval(int idx){
	if(idx > n){
		return 0 ; 
	}
	if(dp[idx] != -1){
		return dp[idx] ; 
	}
	dp[idx] = arr[idx] ; 
	return arr[idx] + maxval(idx + arr[idx]) ; 
}
void solve(){
	memset(dp , -1 , sizeof(dp)) ; 
	cin >> n ; 
	for(int i = 1 ; i <=  n ; i++){
		cin >> arr[i] ; 
	} 
	int ans = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans , maxval(i)) ; 
	}
	cout << ans << endl ; 
	return ; 
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
