#include <bits/stdc++.h> 

using namespace std; 

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int N; 
    cin >> N; 
    vector<vector<int>> graph (N + 1); 
    for(int i = 0; i < N - 1; i++) {
    	int x, y; 
    	cin >> x >> y; 
    	graph[x].push_back(y); 
    	graph[y].push_back(x); 
    }
    vector<vector<int>> dp (N + 1, vector<int> (2, -1)); 
    auto dfs = y_combinator(
    	[&] (auto self, int current, int take, int parent) -> int{
    		int &answer = dp[current][take]; 
    		if(answer != -1) {
    			return answer; 
    		} 
    		answer = take; 
    		for(auto val : graph[current]) {
    			if(val != parent) {
    				// either we want to take it or not
    				// if(no take); 
    				if(take) {
    					answer += min(self(val, 0, current), self(val, 1 , current)); 
    				}
    				else{
    					answer += self(val, 1, current); 
    				}
    			}
    		} 
    		return answer; 
    	}
    ); 
    cout << min(dfs(1, 0, -1) , dfs(1, 1, -1)) << "\n"; 
    return 0; 
}
