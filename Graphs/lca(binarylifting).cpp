#include <bits/stdc++.h> 
#define int long long int
#define endl "\n" 
using namespace std ; 
const int mx = 1e5 ; 
const int mx2 = 20 ; 
vector <int> gr [mx] ; 
ng
int depth[mx]  , parent[mx][mx2] ; 

void dfs(int current , int par){
	depth[current] = depth[par] + 1 ; 
	parent[current][0] = par ; 

	for(int j = 1 ; j < mx2 ; j++){
		parent[current][j] = parent[parent[current][j - 1]][j - 1] ; 
	}
	for(auto x : gr[current]){
		if(x != par){
			dfs(x , current) ;
		}
	}
}

int lca(int u , int v){
	if(u == v){
		return u ;
	}
	if(depth[u] < depth[v]) swap(u , v) ;
	int diff = depth[u] - depth[v] ; 
	for(int j = mx2 - 1 ; j >= 0 ; j--){
		if((diff >> j) & 1){
			// if the jth bit is set 
			u = parent[u][j] ; 
		}
	} 
	// until we reach the same lowest common ancestor
	for(int j = mx2 - 1 ; j >= 0 ; j--){
		if(parent[u][j] != parent[v][j]){
			u = parent[u][j] ; 
			v = parent[v][j] ;
		}
	}
	return parent[u][0] ;
}
int length(int u , int v){
	int l = lca(u , v) ; 
	return depth[u] + depth[v] - 2 * depth[l] ;
}
void solve(){
	int n ; 
	cin >> n ; 
	for(int i = 1 ; i < n ;i++){
		int x , y ; 
		cin >> x >> y ; 
		gr[x].push_back(y) ; 
		gr[y].push_back(x) ;
	}
	dfs(1 , 0) ;
	int  q ; 
	cin >> q ; 
	while(q--){
		int u , v ; 
		cin >> u >> v ; 
		cout << lca(u , v) << " " << length(u , v) << endl ;
	}
	return ;
}

int32_t main(){
	int t = 1 ; 
	/* cin >> t ;*/
	while(t--){
		solve() ;
	}
}
