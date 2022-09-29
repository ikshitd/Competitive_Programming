#include <bits/stdc++.h> 
#define int long long int 
#define endl "\n" 
#define PI 3.1415926535897932384626 
const int mod = 1e9 + 7 ; 
const int N = 1e5 ; 
int arr[N] ; 
using namespace std ;
// memoisation 
// complexity - O(n) ; 
vector <int> memo  ; 
string s ; 
int dp(int idx){
	if(idx == s.size()){
		return 1 ; 
	}
	if(memo[idx] != -1){
		return memo[idx] ; 
	}
	int ans = 0 ; 
	// either take a single digit or take the combination of two digits if they are between 1 - 26 ; 
	if(s[idx] >= '1' and s[idx] <= '9'){
		ans += dp(idx + 1) ; 
	}
	// for numbers 10 - 19 ;
	if(idx + 1 < s.size() && s[idx] == '1'){
		ans += dp(idx + 2) ; 
	}
	// for numbers 20 - 26 ;
	if(idx + 1 < s.size() && s[idx] == '2' && s[idx + 1] <= '6'){
		ans += dp(idx + 2 ) ; 
	}
	return memo[idx] = ans ; 
}
void solve(){
	while(1){
		cin >> s ; 
		if(s == "0"){
			break ; 
		}
		memo.clear() ;
		memo.resize(s.size() , -1) ; 
		cout << dp(0) << endl ; 
	}
	return ; 
} 
int32_t main(){
	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ; 
	srand(chrono::high_resolution_clock::now().time_since_epoch().count()) ; 
	int t= 1 ; 
	while(t--){
		solve() ; 
	}
	return 0 ; 
}
