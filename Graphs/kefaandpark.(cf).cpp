#include <bits/stdc++.h> 
using namespace std ; 
#define int long long int 
#define endl "\n" 
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int n = 1e5 + 5 , m ;
vector <vector <int>> v(n);
vector <int> arr (n) ;
int ans = 0 ;
void dfs(int current , int parent , int counter , int mxcounter){
	if(arr[current] == 1){
		counter+= 1 ;
	}
	else{
		counter = 0 ;
	}
	mxcounter = max(mxcounter , counter) ; 
	int numchildren = 0 ; 
	for(auto x : v[current]){
		if(x != parent){
			dfs(x, current , counter , mxcounter) ;
			numchildren += 1 ;
		}
	}
	if(numchildren == 0 and mxcounter <= m){
		ans += 1 ;
	}
}
void solve(){
	cin >> n >> m ; 
	for(int i = 1 ; i<= n ;i++){
		cin >> arr[i] ;
	}
	for(int i = 1 ; i < n ;i++){
		int x , y ; 
		cin >> x >> y ; 
		v[x].push_back(y) ; 
		v[y].push_back(x) ;
	}
	dfs(1 , 0 , 0 , 0) ; 
	cout << ans << endl ; 
	return ;
} 

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1 ;
	/* cin >> t ; */ 
	while(t--){
		solve() ;
	} 
}
