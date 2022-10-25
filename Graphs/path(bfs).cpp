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

// prining the path from source to the destination using bfs
void bfs(int source , int destination = -1){
	queue <int> q ; 
	q.push(source) ; 
	visited[source] = 1 ; 
	for(int i = 1 ; i <= n ; i++){
		parent[i] = -1 ; 
	}
	parent[source] = source ; 
	while(!q.empty()){
		int f = q.front() ; 
		q.pop() ; 
		for(auto x : gr[f]){
			if(!visited[x]){
				q.push(x) ;
				visited[x] = 1 ; 
				parent[x] = f ; 
			}
		}
	}
	// to print the path from source to destination
	if(destination != -1){
		int temp = destination ; 
		while(temp != source){
			cout << temp << " " ; 
			temp = parent[temp] ;
		}
		cout << source << endl ;
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
	int q ; 
	cin >> q ; 
	while(q--){
		int s , d ; 
		cin >> s >> d ; 
		bfs(s , d) ;
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
