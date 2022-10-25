#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n" 

const int mod = 1e9 + 7 ; 
const int mx = 1e5 + 1;

vector <int> gr[mx] ; 
int visited[mx + 1] ;

bool cycle = false ;

void dfs(int current , int parent){
	cout << current << " " ;
	visited[current] = 1 ; 
	for(auto x : gr[current]){
		if(!visited[x]){
			dfs(x , current) ;
		}
		else if(x != parent){
			// it is a backedge 
			// cout << current << " " << x << endl ;
			cycle = true ;
		}
	}
}
void solve(){
	int n , m ; 
	cin >> n >> m ; 
	for(int i = 0 ; i < m ; i++){
		int x , y ; 
		cin >> x >> y ; 
		gr[x].push_back(y) ; 
		gr[y].push_back(x) ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!visited[i]){
			dfs(i , 0) ;
		}
	}
	if(cycle == true){
		cout << "YES" << endl ;
	}
	else{
		cout << "NO" << endl ;
	}
	return ;
} 

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	clock_t z = clock();

	int T = 1 ;
	/* cin >> T ; */ 
	while(T--){
		solve() ;
#ifndef ONLINE_JUDGE 
	cout << "--------------------------------------------------" << endl ;  
#endif 
	}
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) ;
	return 0;
} 
