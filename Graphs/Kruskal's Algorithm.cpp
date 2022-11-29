#include <bits/stdc++.h> 
using namespace std; 
// DSU WITH PATH COMPRESSTION AND UNION BY RANK 
class dsu{
	int *parent ; 
	int *rank ; 
public :
	dsu(int n){
		parent = new int [n + 1] ; 
		rank = new int [n + 1] ;

		for(int i = 1  ; i <= n ; i++){
			parent[i] = -1 ; 
			rank[i] = 1 ;
		}
	}
	// find function 
	int findset(int x){
		if(parent[x] == -1){
			return x ;
		}
		return parent[x] = findset(parent[x]) ;
	}
	// unite function 
	void unite(int x , int y){
		int s1 = findset(x) ; 
		int s2 = findset(y) ; 
		if(s1 != s2){
			if(rank[s1] < rank[s2]){
				parent[s1] = s2 ; 
				rank[s2] += rank[s1]  ;
			}
			else{
				parent[s2] = s1 ; 
				rank[s1] += rank[s2] ;
			}
		}
	}
}; 
class Graph{
	vector <vector <int>> edgelist ;
	int V ; 
public: 
	Graph(int v){
		this -> V = v ; 
	}
	void addEdge(int x , int y , int w){
		edgelist.push_back({w , x , y}) ;
	}
	int kruskal_mst(){
		// main logic and is very easy 
		// sorting on the basis of the weight 
		sort(edgelist.begin() , edgelist.end()) ;
		
		dsu s (V) ;
		int ans = 0 ; 
		for(auto edge : edgelist){
			int w = edge[0] ; 
			int x = edge[1] ; 
			int y = edge[2] ; 
			// take the edge if it doesn't form a cycle 
			
			if(s.findset(x) != s.findset(y)){
				s.unite(x , y) ;
				ans += w ;
			}
		}
		return ans ;
	}
};
void solve(){
	int n , m ; 
	cin >> n >> m ; 
	Graph g(n) ;
	for(int i = 1 ; i <= m ; i++){
		int x , y , w ; 
		cin >> x >> y >> w ; 
		g.addEdge(x , y , w) ;
	}
	cout << g.kruskal_mst() << endl ; 
	return ;
}
int32_t main(){
	int t = 1 ; 
	while(t--){
		solve() ;
	}
}
