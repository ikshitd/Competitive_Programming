#include <bits/stdc++.h> 
#define int long long int 
using namespace std ;
const int N = 1e5 ; 
int memo[N]; 
int func(int n){
	if(n == 0){ 
		return 0 ; 
	}
	int &ans = memo[n] ; 

	if(ans != -1){
		return ans ; 
	}
	ans = INT_MAX ; 
	if(n % 2 == 0){
		ans = min(ans , func(n / 2)) ; 
	}
	if(n % 3 == 0){
		ans = min(ans , func(n / 3)) ; 
	}
	ans = min(ans , func(n - 1)) ;
	ans += 1 ;
	return ans ; 
}
void solve(){
	int n ; 
	cin >> n ; 
	memset(memo , -1 , sizeof(memo)) ; 
	cout << func(n) << endl ; 
	return ;
}
int32_t main(){
	int t = 1 ;
	while(t--){
		solve() ; 
	}
}
