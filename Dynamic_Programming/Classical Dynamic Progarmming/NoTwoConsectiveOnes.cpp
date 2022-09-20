#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
int n ; 
int func2(int n){
	if(n == 0 or n == 1){
		return n ; 
	}
	return func2(n - 1) + func2(n - 2) ; 
}
int func(int idx , int n , bool one){
	int ans = 0 ; 
	if(idx == n + 1){
		return 1 ; 
	}
	// either place 0 
	ans += func(idx + 1 , n , false) ; 
	// either place 1
	if(one == false){
		ans += func(idx + 1 , n , true) ; 
	}
	return ans ; 
	// ans for array [idex.. n] ; 
}
void solve(){
	cin >> n ;
	cout << func(1 , n , false) << endl ; 
	cout << func2(n + 2) << endl ;
	return ; 
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
