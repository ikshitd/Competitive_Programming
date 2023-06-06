#include <bits/stdc++.h> 
using namespace std; 

vector<vector<int>> dp; 

int matrixChainMultiplication(int currenti, int currentj, vector<int> &a){
	if((int) currenti == (int) currentj) {
		return 0; 
	}
	int & answer = dp[currenti][currentj]; 
	if(answer != -1) {
		return answer; 
	}
	answer = INT_MAX; 
	for(int k = currenti; k < (int) currentj; k++) {
		answer = min(answer, matrixChainMultiplication(currenti, k, a) + matrixChainMultiplication(k + 1, currentj, a) + a[currenti - 1] * a[k] * a[currentj]); 
	}
	return answer; 
}

void solve() {
	int N; 
	cin >> N; 
	vector<int> a (2 * N); 
	for(int i = 0; i < 2 * N; i++) {
		cin >> a[i];
	}
	a.resize(unique(a.begin(), a.end()) - a.begin()); 
	N = (int) a.size(); 
	dp.resize(N + 1, vector<int> (N + 1,-1)); 
	cout << matrixChainMultiplication(1, (int) N - 1, a) << "\n"; 
	return ; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    solve(); 
}
