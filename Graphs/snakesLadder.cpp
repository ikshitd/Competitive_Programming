#include <bits/stdc++.h> 
using namespace std ; 
class GraphInt{
public : 
	int V ; 
	list <int> *l ; 
	GraphInt(int v){
		V = v ; 
		l = new list <int> [V]  ; 
	}
	void addEdge(int x , int y , bool undir = true){
		l[x].push_back(y) ; 
		if(undir == true) l[y].push_back(x) ; 
	}
	void printAdjList(){
		for(int i = 0 ; i < V ; i++){
			cout << i << "-->" ; 
			for(auto j : l[i]){
				cout << j << "," ; 
			}
			cout << endl; 
		}
	}
	// level order traversal 
	void bfs(int source , int destination){
		queue <int> q ; 
		bool *visited = new bool [V] {0} ; 
		int *dist = new int [V] {0} ; 
		int *parent = new int [V] {0} ; 
		for(int i = 0 ; i < V ; i++){
			parent[i] = -1 ; 
		}
		q.push(source) ; 
		visited[source] = true ; 
		while(!q.empty()){
			int f = q.front() ; 
		// 	cout << f << endl; 
			q.pop() ; 
			for(auto nbrs : l[f]){
				if(!visited[nbrs]){
					q.push(nbrs) ; 
					visited[nbrs] = true ; 
					dist[nbrs] = dist[f] + 1 ; 
					parent[nbrs] = f ; 
				}
			}
		}
		// print the distances of every node from the source 
		/*for(int i = 0 ; i < V ; i++){
			cout << i << "->" << dist[i] << endl ; 
		}*/ 
		// find the shortest path from source to destination 
		int temp = destination ; 
		while(temp != -1){
			cout << temp << "<--" ; 
			temp = parent[temp] ; 
		}
		cout << endl ; 
	}
}; 
class Node{
public : 
	string name ; 
	list <string> neigh ; 
	Node(string name){
		this -> name = name ; 
	}
}; 
class GraphString{
public : 
	// we need all the nodes and a hashmap <string , node*> 
	unordered_map <string ,Node*> m ; 
	GraphString(vector <string> cities){
		for(auto city : cities){
			m[city] = new Node(city) ; 
		}
	}
	void addEdge(string x , string y , bool undir= false){
		m[x] -> neigh.push_back(y) ;
		if(undir == true) m[y] -> neigh.push_back(x) ; 
	}
	void printAdjList(){
		for(auto cityPair : m){
			auto city = cityPair.first ; 
			Node *node = cityPair.second ; 
			cout << city << "-->" ; 
			for(auto nbr : node -> neigh){
				cout << nbr << "," ; 
			}
			cout << endl ; 
		}
	}
}; 
int main(){
	int board[50] = {0}; 
	board[2] = 13 ; 
	board[5] = 2 ; 
	board[9] = 18 ; 
	board[18] = 11 ; 
	board[17] = -13 ; 
	board[20] = -14 ; 
	board[24] = -8 ; 
	board[25] = -10 ; 
	board[32] = -2 ; 
	board[34] = -22 ; 
	GraphInt g(50) ; 
	
	// now we have to insert the edges 
	for(int u = 0 ;u < 36 ;  u++){
		for(int dice = 1 ; dice <= 6 ; dice++){
			int v = u + dice + board[u + dice] ; 
			g.addEdge(u , v , false) ; 
		}
	}
	g.bfs(0 , 36) ;
}

