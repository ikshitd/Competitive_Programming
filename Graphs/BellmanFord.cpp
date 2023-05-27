#include <bits/stdc++.h> 
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; 
    cin >> N >> M; 
    vector<vector<int>> edges; 
    for(int i = 0; i < M; i++) {
        int x, y, w; 
        cin >> x >> y >> w;
        edges.push_back({x, y, w}); 
    }
    vector<int> distance (N + 1,INT_MAX);  
    auto bellmanford = [&] (int src) {
        distance[src] = 0; 
        // relax all the edges for N - 1 times; 
        for(int i = 0; i < N - 1; i++) {
            for(auto val: edges) {
                int from = val[0]; 
                int to = val[1]; 
                int wt = val[2]; 
                if(distance[from] != INT_MAX and distance[from] + wt < distance[to]) {
                    distance[to] = distance[from] + wt; 
                }
            }
        }
        for(auto val: edges) {
            int from = val[0]; 
            int to = val[1]; 
            int wt = val[2]; 
            if(distance[from] != INT_MAX and distance[from] + wt < distance[to]) {
                cout <<" Negative weight cycle found" << "\n"; 
                exit(0); 
            }
        }
    };
    bellmanford(1);
    for(int i = 1;  i <= N;i++) {
        cout <<  distance[i]  << " "; 
    }
    cout << "\n"; 
    return 0; 
}
