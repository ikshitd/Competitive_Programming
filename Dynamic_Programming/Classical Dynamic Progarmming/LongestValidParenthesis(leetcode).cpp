#include <bits/stdc++.h> 
#define int long long int 
#define endl "\n" 
#define PI 3.1415926535897932384626 
const int mod = 1e9 + 7 ; 
const int N = 1e5 ; 
int arr[N] ; 
using namespace std ;
void solve(){
	// longest valid parenthesis leetcode - hard - dp approach 
	string s ; 
	cin >> s ; 
	int n = s.length() ; 
	int ans = 0 ; 
	// initialize the dp vector with 0 
	vector <int> dp(n , 0) ; 
	for(int i = 1 ; i < n ; i++){
		// we are not worried about the (
		if(s[i] == ')'){
			// if s[i - 1] == ( then it is one of the valid answers with dp[i] = 2 ; 
			if(s[i - 1] == '('){
				dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2 ; 
			}
			else{
				// if s[i- 1] != ( then s[i - 1] == ) and hence check the value of s[i - dp[i - 1] - 1] if it is ( then it is a valid answer with dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 ;
				if(i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == '('){
					dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) ; 
				}
			}
			ans = max(ans , dp[i]) ; 
		}
	}
	cout << ans << endl ; 
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
