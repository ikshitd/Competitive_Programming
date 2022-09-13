#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
void solve(){
	int n ; 
	cin >> n ; 
	int arr[n] ; 
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i] ; 
	}
	int ma = arr[0]  ;
	int mi = arr[0] ; 
	int ans = arr[0] ; 
	for(int i = 1 ; i < n ; i++){
		if(arr[i] < 0){
			swap(ma , mi) ; 
		}
		ma = max(arr[i]  , arr[i] * ma) ; 
		mi = min(arr[i]  , arr[i] * mi) ; 
		ans = max(ans , ma) ; 
	}
	cout << ans << endl ; 
	return ; 
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
