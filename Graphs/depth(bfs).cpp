#include <bits/stdc++.h> 
#define int long long int
#define endl "\n" 
using namespace std ; 

// here n represents the number of nodes from 1 - n and m represents the number of edges
int n  , m ; 
const int mx = 1e5 ; 

vector <int> gr[mx] ;
int visited[mx + 1 ]; 
int parent[mx + 1] ;
int depth[mx + 1] ;

void bfs(int source){
	queue <int> q ; 
	visited[source] = 1 ; 
	for(int i = 1 ; i <= n ; i++){
		parent[i] = -1 ;
	}
	q.push(source) ;
	parent[source] = source ;
	depth[source] = 0 ; 
	while(!q.empty()){
		int f = q.front() ; 
		q.pop() ; 
		for(auto x : gr[f]){
			if(!visited[x]){
				q.push(x) ;
				parent[x] = f ; 
				depth[x] = depth[f] + 1; 
				visited[x] = 1 ;
			}
		}
	}
	return ;
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
			bfs(i) ;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << depth[i] << " " ;
	}
	cout << endl ; 
	return ; 
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */
	while(t--){
		solve() ;
	}
}
