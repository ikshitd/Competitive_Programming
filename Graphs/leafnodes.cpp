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
const int mx = 1e2 ;

vector <int> gr[mx] ;
void dfs(int current , int parent){
	int numchildren  = 0 ;
	for(auto x : gr[current]){
		if(x != parent){
			dfs(x , current) ;
			numchildren += 1 ;
		}
	}
	if(numchildren == 0){
		cout << current << " " ;
	}
}
void solve(){
	int n ; 
	cin >> n ; 
	for(int i = 1 ; i < n ;i++){
		int u , v ; 
		cin >> u >> v ; 
		gr[u].push_back(v) ; 
		gr[v].push_back(u) ;
	}
	dfs(1 , 0 ) ;
}

int32_t main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve();
	}
} 
