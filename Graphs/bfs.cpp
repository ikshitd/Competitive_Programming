#include <bits/stdc++.h> 
#define int long long int
#define endl "\n" 
using namespace std ; 

// here n represents the number of nodes from 1 - n and m represents the number of edges
int n  , m ; 
const int mx = 1e5 ; 

vector <int> gr[mx] ;
int visited[mx + 1 ]; 

void bfs(int current){
	queue <int> q ; 
	q.push(current) ; 
	visited[current] = 1 ; 
	while(!q.empty()){
		int f = q.front() ;
		cout << f << " " ; 
		q.pop() ; 
		for(auto x : gr[f]){
			if(!visited[x]){
				q.push(x) ; 
				visited[x] = 1 ;
			}
		}
	}
	cout << endl ;
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
}
int32_t main(){
	int t = 1 ; 
	/* cin >> t ; */
	while(t--){
		solve() ;
	}
}
