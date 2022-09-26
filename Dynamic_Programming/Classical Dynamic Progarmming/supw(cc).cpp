#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
void solve(){
	int n ; 
	cin >> n ; 
	int arr[n] , dp[n] ; 
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i] ; 
	}
	for(int i = 0 ; i < 3 ;i++){
		dp[i] = arr[i] ; 
	}
	for(int i = 3 ; i < n ; i++){
		dp[i] = min(dp[i - 1] , min(dp[i -2] , dp[i - 3])) + arr[i] ; 
	}
	/* for(auto i : dp){ */
	/* 	cout << i << " " ; */ 
	/* } */
	/* cout << endl ; */ 
	cout << min(dp[n - 1] , min(dp[n - 2] , dp[n - 3]))  << endl  ; 
	return ; 
}
int32_t main(){
	int t = 1 ;
	while(t--){
		solve() ; 
	}
}
