#include <bits/stdc++.h> 
#define char unsigned char 

using namespace std; 
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll ; 
typedef long double ld ; 

class Graph{
	vector <pair <int ,int>> *l ; 
	int v ; 

	public: 
	Graph(int n){
		this -> v = n ; 
		l = new vector <pair <int , int>>  [n] ; 
	}

	void addedge(int x , int y , int w){
		l[x].push_back(make_pair(y , w)) ; 
		l[y].push_back(make_pair(x , w)) ; 
	}

	ll prim_mst(){
		priority_queue <pair <int , int> , vector <pair <int , int>> , greater <pair <int , int>>> q; 
		bool *visited = new bool [v] {0} ;
		ll answer = 0 ; 
		q.push({0 , 0}) ; // (weight , node) ;
		while(!q.empty()){
			auto best = q.top() ; 
			q.pop() ; 
			int to = best.second ; 
			int weight = best.first ; 
			if(visited[to]){
				continue ;
			}
			answer += weight ;
			visited[to] = true ; 
			for(auto x : l[to]){
				if(!visited[x.first]){
					q.push(make_pair(x.second , x.first)) ;
				}
			}
		}
		return answer ;
	}
};

void solve(){
	ll n , m ; 
	cin >> n >> m ; 
	Graph gr (n) ; 
	for(int i = 0 ; i < m ; i++){
		ll x , y , w ; 
		cin >> x >> y >> w ; 
		gr.addedge(x  - 1, y - 1 , w) ; 
	}
	cout << gr.prim_mst() << "\n" ; 
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	int t = 1 ;
	/* cin >>  t ; */
	while(t--){
		solve() ;
	}
	return 0 ;
}
