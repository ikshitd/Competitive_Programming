#include <bits/stdc++.h> 
using namespace std ; 
#define endl "\n" 
#define int long long int 
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
const int mx = 1e2 + 10 ; 
map <string , vector <string>> gr ; 
map <string , int> visited ; 
map <string ,int> depth ; 
void bfs(string source){
	visited[source] = 1 ; 
	depth[source] = 1 ;
	queue <string> q ; 
	q.push(source) ; 
	while(!q.empty()){
		string f = q.front() ; 
		q.pop() ;
		for(auto x : gr[f]){
			if(!visited[x]){
				q.push(x) ;
				visited[x] = 1 ; 
				depth[x] = depth[f] + 1 ;
			}
		}
	}
}
void solve(){
	int n ; 
	cin >> n ; 
	for(int i =0 ; i < n ;i++){
		string a , b , c; 
		cin >> a >> b >> c ; 
		transform(a.begin() , a.end() , a.begin() , ::tolower) ; 
		transform(c.begin() , c.end() , c.begin() , ::tolower) ; 
		gr[c].push_back(a) ;
	}
	bfs("polycarp") ;
	int ans = 1 ;
	for(auto i : depth){
		ans = max(ans , i.second) ;
	} 
	cout << ans << endl ;
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
