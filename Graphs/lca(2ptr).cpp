#include <bits/stdc++.h> 
#define int long long int
#define endl "\n" 
using namespace std ; 
const int mx = 1e5 ; 
vector <int> gr[mx] ; 
int depth[mx]  , parent[mx] ;
int visited[mx] ; 

void dfs(int current , int par){
	visited[current] = 1 ;
	parent[current] = par;
	depth[current] = depth[par] + 1 ;
	for(auto x : gr[current]){
		if(!visited[x]){
			dfs(x , current) ;
		}
	}
}
// to find the lowest common ancestor using 2 pointer approach 
//O(n) 
int lca(int u , int v){
	if(u == v) return u ; 
	// depth will always be more than the depth of v 
	if(depth[u] < depth[v]) swap(u , v) ;

	int diff = depth[u] - depth[v] ; 

	while(diff--){
		u = parent[u] ; 
	}
	while(u != v){
		u = parent[u] ; 
		v = parent[v] ; 
	}
	return u ; 
}
void solve(){
	int n ; 
	cin >> n ; 
	for(int i = 1; i < n ;i++){
		int x , y ; 
		cin >> x >> y ; 
		gr[x].push_back(y) ; 
		gr[y].push_back(x) ;
	}
	int q ; 
	cin >> q ; 
	while(q--){
		int x , y ; 
		cin >> x >> y ; 
		cout <<lca(x , y) << endl ;
	}
	return ;
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */
	while(t--){
		solve() ;
	}
}
