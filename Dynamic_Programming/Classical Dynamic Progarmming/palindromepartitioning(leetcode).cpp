#include <bits/stdc++.h> 
using namespace std ; 
#define endl "\n" 
#define int int64_t 
#define double long double 
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
const int mx = 1e5 ;
class Solution {
public:
	string s ; 
	map <int , vector <vector <string>>> mp ;
	bool is_palindrome(int i , int j){
		while(i <= j){
			if(s[i] != s[j]){
				return false ;
			}
			i += 1 ; 
			j -= 1 ;
		}
		return true ;
	}
	vector <vector <string>> dp(int i){
		// base case 
		if(i == s.size()) return vector <vector <string>> () ;

		if(mp.count(i)) return mp[i] ;
		
		vector <vector <string>> ans ;
		for(int j = i ; j < s.size() ; j++){
			if(is_palindrome(i , j)){
				vector <vector <string>> res = dp(j + 1) ;
				string substring = s.substr(i , j - i + 1) ;
				for(auto &x : res){
					x.insert(x.begin() , substring) ;
				}
				if(res.empty()){
					res.push_back({substring}) ;
				}
				for(auto &x : res){
					ans.push_back(x) ;
				}
			}
		}
		return mp[i] = ans ;
	}
    vector<vector<string>> partition(string s) {
		this -> s = s ; 
		return dp(0) ;
    }
};
void solve(){
	string s ;
	cin >> s ;
	Solution H ; 
	vector <vector <string>> res = H.partition(s) ; 
	for(auto x : res){
		for(auto y :x){
			cout << y << " " ;
		}
		cout << endl ;
	}
	return ;
} 

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t = 1 ; 
	/* cin >> t ; */ 
	while(t--){
		solve(); 
	} 
} 

