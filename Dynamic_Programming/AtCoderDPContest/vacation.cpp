#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int mod = 1e9 + 7 ; 
const int INF = 1e9 ; 
void solve(){
	int n  ;
	cin >> n ; 
	int arr[n][3] ; 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cin >> arr[i][j] ; 
		}
	}
	int dp[n][3] = {0} ;  
	// fill the first row of the dp array 
	for(int j = 0 ; j < 3 ;j++){
		dp[0][j] = arr[0][j] ; 
	}
	// lets fill other dp values 
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < 3 ; j++){
			for(int k = 0 ; k < 3 ; k++){
				if(j != k){
					dp[i][j] = max(dp[i][j] , dp[i -1][k] + arr[i][j]) ; 
				}
			}
		}
	}
	cout << *max_element(dp[n - 1] , dp[n - 1] + 3) << endl ; 
	return ; 
}

int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve() ; 
	}
}
