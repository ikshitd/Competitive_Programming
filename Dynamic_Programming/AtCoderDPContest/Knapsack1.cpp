#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int mod = 1e9 + 7 ; 
const int INF = 1e9 ; 
const int N = 100 ; 
int n , v[N] , w[N] , W , memo[N][100001] ; 
int knapsack(int idx , int weight){
	// base case
	if(idx >= n){
		return 0 ; 
	}
	int &ans = memo[idx][weight] ; 
	if(ans != -1){
		return ans ; 
	}
	// do not take something 
	ans = knapsack(idx + 1 , weight) ; 
	// take something 
	if(w[idx] + weight <= W){
		ans = max(ans , v[idx] + knapsack(idx + 1 , w[idx] + weight)) ; 
	}
	return ans ; 
}
void solve(){
	cin >> n >> W ; 
	for(int i = 0 ; i < n ; i++){
		cin >> w[i] >> v[i] ; 
	}
	memset(memo , -1 , sizeof(memo)) ; 
	cout << knapsack(0 , 0) << endl ; 
	return ;
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve() ; 
	}
}
