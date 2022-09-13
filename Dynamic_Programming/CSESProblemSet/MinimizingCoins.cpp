#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int mod = 1e9 + 7 ; 
const int INF = 1e9 ; 
void solve(){
	int n , x ; 
	cin >> n >> x ; 
	int arr[n] ; 
	for(int i =0 ; i< n ; i++){
		cin >> arr[i] ; 
	}
	vector <int> dp(x + 1 , INF) ; 
	dp[0] = 0 ; 
	for(int i = 1 ; i <= x ;i++){
		for(int j = 0 ;j < n ; j++){
			if(i - arr[j] >= 0){
				dp[i] = min(dp[i] , dp[i - arr[j]] + 1) ; 
			}
		}
	}
	cout << endl ;
	cout << (dp[x] == INF ? -1 : dp[x]) << endl ; 
	return ;
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve() ; 
	}
}
