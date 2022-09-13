#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int mod = 1e9 + 7 ; 
void solve(){
	int n ; 
	cin >> n ; 
	vector <int> dp (n + 1 , 0) ; 
	dp[0] = 1 ; 
	for(int i = 1 ; i < n + 1 ; i++){
		for(int j = 1 ; j <= 6 ; j++){
			if(i - j >= 0){
				dp[i] += dp[i - j]  ; 
				dp[i] %= mod ; 
			} 
		}
	}
	cout << dp[n] << endl ; 
	return ; 
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve() ; 
	}
}
