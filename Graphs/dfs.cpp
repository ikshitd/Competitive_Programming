#include <bits/stdc++.h> 
#define int long long int
#define endl "\n" 
using namespace std ; 

// here n represents the number of nodes from 1 - n and m represents the number of edges
int n  , m ; 
const int mx = 1e5 ; 

vector <int> gr[mx] ;
int visited[mx + 1 ]; 

void dfs(int current , int parent){
	cout << current << " " ; 
	visited[current] = 1 ; 
	for(auto x : gr[current]){
		if(!visited[x]){
			dfs(x , current) ; 
		}
	}
}
void solve(){
	cin >> n >> m ;
	for(int i = 0 ; i < m ; i++){
		int x , y ; 
		cin >> x >> y ;
		gr[x].push_back(y) ;
		gr[y].push_back(x) ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(visited[i] != 1){
			dfs(i , 0) ;
		}
	}
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */
	while(t--){
		solve() ;
	}
}
