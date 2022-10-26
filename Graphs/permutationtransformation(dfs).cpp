#include <bits/stdc++.h> 
using namespace std ; 
#define endl "\n" 
#define int long long int 
#define double long double 
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
const int mx = 1e2 + 5 ;
int arr[mx]  , ans[mx] ;
void dfs(int l , int r ,int d = 0){
	if(l > r){
		return ;
	}
	int idx = l , max = arr[l] ; 
	for(int i = l ; i <= r ; i++){
		if(arr[i] > max){
			max = arr[i] ; 
			idx = i ;
		}
	}
	ans[idx] = d ; 
	dfs(l , idx - 1 , d + 1) ; 
	dfs(idx + 1 , r , d + 1) ;
}
void solve(){
	int n ; 
	cin >> n ; 
	for(int i = 0 ; i < n ;i++){
		cin >> arr[i] ;
	}
	dfs(0 , n - 1 , 0) ;
	for(int i = 0 ; i < n ; i++){
		cout << ans[i] << " " ;
	}
	cout << endl ;
	return ;
}

int32_t main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1 ; 
	cin >> t ; 
	while(t--){
		solve();
	}
} 
