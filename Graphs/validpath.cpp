class Solution {
public:
	//using bfs 
    bool validPath(int n, vector<vector<int>>&  nodes, int source, int destination){
        // using bfs 
        unordered_map <int , vector <int>> m ; 
        for(auto i : nodes){
            m[i[0]].push_back(i[1]) ; 
            m[i[1]].push_back(i[0]) ;
        }
        bool *visited = new bool [n] {0} ;
        visited[source] = true ; 
        queue <int> q ; 
        q.push(source) ; 
        
        while(!q.empty()){
            int f = q.front() ; 
            q.pop() ; 
            if(f == destination){
                return true ; 
            }
            for(auto nbrs : m[f]){
                if(visited[nbrs] == false){
                    visited[nbrs] = true ; 
                    q.push(nbrs) ; 
                }
            }
        }
        return false ; 
    }
	bool dfs(unordered_map<int, vector<int>>& graph, vector<bool>& seen, int currNode, int destination) {
        if (currNode == destination) {
            return true;
        }
        if (!seen[currNode]) {
            seen[currNode] = true;
            for (auto& nextNode : graph[currNode]) {
                if (dfs(graph, seen, nextNode, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
	// using dfs 
    bool validPath2(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> seen(n);
        return dfs(graph, seen, source, destination);
    }
	//using dfs using stack 
	bool validPath3(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map <int , vector <int>> m ;
        for(auto i : edges){
            int a = i[0]  , b = i[1] ; 
            m[a].push_back(b) ; 
            m[b].push_back(a) ; 
        }
        
        bool *visited = new bool [n]{0} ; 
        stack <int> s ({source}) ; 
        visited[source] = true ; 
        
        while(!s.empty()){
            int current = s.top() ; 
            s.pop() ; 
            if(current == destination){
                return true ;
            }
            
            for(auto nbrs : m[current]){
                if(!visited[nbrs]){
                    visited[nbrs] = true ;
                    s.push(nbrs) ; 
                }
            }
        }
        return false ; 
    }
};
};
