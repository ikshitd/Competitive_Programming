#include <bits/stdc++.h> 
#define char unsigned char 

using namespace std ; 

typedef long long ll ; 
typedef long double ld ; 
const ll INF = 1e18 ; 

class Graph{
	ll v ; 
	vector <pair <int , int>> *l ; 
	public : 
	Graph(int n){
		this -> v = n ; 
		l = new vector <pair <int , int>> [n + 1] ;
	}
	void addedge(int source , int destination , int weight){
		l[source].push_back(make_pair(weight , destination)) ;
		l[destination].push_back(make_pair(weight , source)) ;
	}
	int dijkstra(int source ,int destination){
		vector <ll> distance (v + 1 , INF) ; 
		set <pair <int , int>> s ; // distance , node 
								   //
		distance[source] = 0 ; 
		s.insert({0 , source}) ;

		while(!s.empty()){
			auto it = s.begin() ; 
			int node = it -> second ; 
			int distance_till_now = it -> second ;
			s.erase(it) ;
			
			for(auto val : l[node]){
				int neighbour = val.second ; 
				int currentedge = val.first ; 
				if(distance_till_now + currentedge < distance[neighbour]){

					auto f = s.find(make_pair(distance[neighbour] , neighbour)) ; 
					if(f != s.end()){
						s.erase(f) ;
					}
					distance[neighbour] = distance_till_now + currentedge ; 
					s.insert(make_pair(distance[neighbour] , neighbour)) ;
				}
			}
		}
		
		for(int i = 0 ; i < v ; i++){
			cout << "The distance of "  << i << "from source node is " << distance[i] << "\n" ; 
		}
		return distance[destination] ;
	}
};
void solve(){

}

int32_t main(){
	
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	clock_t clock_begin = clock();

	int t = 1 ;
	/* cin >>  t ; */
	while(t--){
		solve() ;
	}

	cerr << "Run Time : " << ((double)(clock() - clock_begin) / CLOCKS_PER_SEC) << "\n" ;
	return 0 ;

}
