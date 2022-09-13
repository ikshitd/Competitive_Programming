#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
// BOTTOM UP APPROACH
int longestIncreasingSubsequence(vector <int> arr){
	int n = arr.size() ; 
	vector <int> dp (n , 1) ; 

	int len = 1 ; 
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < i ;j++){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i] , 1 + dp[j]) ; 
				len = max(len , dp[i]) ; 
			}
		}
	}
	return len ; 
}
void solve(){
	vector <int> arr {50 , 4 , 10 , 8 , 30 , 100} ; 
	cout << longestIncreasingSubsequence(arr) << endl ; 
	return ;
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
