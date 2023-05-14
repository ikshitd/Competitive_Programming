#include <bits/stdc++.h> 

using namespace std; 

bool dfs(int current, vector<vector<int>> &graph,vector<bool> &vis, vector<bool> &visited) {
	visited[current] = true; 
	vis[current] = true; 
	for(auto val : graph[current]) {
		if(!visited[val]) {
			if(dfs(val, graph, vis, visited) == true) {
				return true; 
			}
		}
		else if(vis[val] == true) {
			return true; 
		}
	}
	vis[current] = false; 
	return false; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int N; 
    cin >> N; 
    vector<vector<int>> a (N, vector<int> (N)); 
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N; j++) {
    		cin >> a[i][j]; 
    	}
    }
    vector<vector<int>> graph (N); 
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N ; j++) {
    		if(a[i][j] != 0) {
    			graph[i].push_back(j); 
    		}
    	}
    }
    vector<bool> visited (N + 1, false), vis(N + 1, false); 
    for(int i = 0; i < N; i++) {
    	if(!visited[i]) {
    		if(dfs(i, graph, vis, visited) == true) {
    			cout << "YES" << "\n"; 
    			return 0; 
    		}
    	}
    }
    cout << "NO" << "\n"; 
    return 0; 
    
}
