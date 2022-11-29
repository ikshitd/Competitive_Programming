#include <bits/stdc++.h> 
using namespace std; 


#define int long long int
#define double long double
#define endl "\n" 

#define vt vector 
#define all(x) (x).begin() , (x).end() 
#define sz(x) (int)(x).size()
#define FOR(i , a , b) for(int i = (a); i < (b); i++)
#define EACH(x , a) for(auto &x : a) 

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN = 1e5 ; 
const int mod = 1e9 + 7 ;

template <class T> bool ckmin(T &a , T const &b){
	return (b < a ? a = b , 1 : 0);
}

template <class T> bool ckmax(T &a , T const &b){
	return (a < b ? a = b , 1 : 0); 
}

template <class T> void read(T &x){
	cin >> x ;
}

template <class A , class ...T> void read(A &x , T&... t){
	read(x); 
	read(t...); 
}

template <class T> void read(vt <T> &v){
	EACH(x , v){
		read(x);
	}
}
template <class T> void read(vt <vt <T>> &v){
	EACH(x , v){
		EACH(y , x){
			read(y) ;
		}
	}
}
template <class T> void write(T &x){
	cout << to_string(x) << endl ; 
}

template <class A> void write(vt <A> &v){
	EACH(x , v){
		cout << x << " ";
	}
	cout << endl ;
}
vector <int> gr[mxN] ;
vector <bool> visited (mxN , false) ;
vector <int> order ;

void dfs(int current){
	visited[current] = true ; 
	for(auto x : gr[current]){
		if(!visited[x]){
			dfs(x) ;
		}
	}
	order.push_back(current) ;
	return ;
}
void solve(){
	int n  , m ; 
	cin >> n >> m ; 
	for(int i = 0 ; i < m ; i++){
		int x , y ; 
		cin >> x >> y ; 
		gr[x].push_back(y) ;
	}
	for(int i = 1 ; i <= n ;i++){
		if(!visited[i]){
			dfs(i) ; 
		}
	}
	reverse(all(order)) ;
	write(order) ;
	return ;
}

int32_t main(){
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	int TET = 1 ; 
	read(TET) ; 
	FOR(i , 1 , TET + 1){
		solve() ;
	}
	return 0 ;
}
