#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
bool comp(vector <int> b1 , vector <int> b2){
	return b1[2] < b2[2] ; 
}
bool canPlace(vector <int> v1 , vector <int> v2){
	if(v1[0] < v2[0] and v1[1] < v2[1] and v1[2] < v2[2]){
		return true ; 
	}
	return false ; 
}
int boxStacking(vector <vector <int>> v){
	int n = v.size() ; 
	// sort on the basis of the height of the boxes 
	sort(v.begin() , v.end() , comp); 
	// create a dp array and store the max answers in them 
	vector <int> dp (n + 1 , 0) ; 
	for(int i = 0 ; i < n ; i++){
		dp[i] = v[i][2] ; 
	}
	int ans = 0 ; 
	for(int i = 1 ; i < n ; i++){
		for(int j = 0;j < i ; j++){
			if(canPlace(v[j] , v[i])){
				dp[i] = max(dp[i] , v[i][2] + dp[j]) ; 
				ans = max(ans , dp[i]) ; 
			}
		}
	}
	return ans ; 
}
void solve(){
	vector <vector <int>> b = {
		{2 , 1 , 2} , 
		{3 , 2 , 3} , 
		{2 , 2 , 8} , 
		{2 , 3 , 4} , 
		{2 , 2 , 1} , 
		{4 , 4 , 5} , 
	} ; 

	int height = boxStacking(b) ; 
	cout << height << endl ; 
	return ; 
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
