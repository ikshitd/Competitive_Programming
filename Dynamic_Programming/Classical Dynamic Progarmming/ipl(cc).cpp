#include <bits/stdc++.h> 
#define int long long int 
using namespace std ;
/* think opposite */
/* this problem is just the complement of the supw problem just take the minimum value in the three consecutive days and subtract is from the sum of all the give values */ 
void solve(){
	int n ; 
	cin >> n ; 
	int arr[n] , dp[n] ; 
	int s= 0 ; 
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i] ; 
		s += arr[i]  ; 
	}
	for(int i = 0 ; i < 3 ;i++){
		dp[i] = arr[i] ; 
	}
	for(int i = 3 ; i < n ; i++){
		dp[i] = min(dp[i - 1] , min(dp[i -2] , dp[i - 3])) + arr[i] ; 
	}
	cout << s -  min(dp[n - 1] , min(dp[n - 2] , dp[n - 3]))  << endl  ; 
	return ; 
}
int32_t main(){
	int t = 1 ;
	while(t--){
		solve() ; 
	}
}
