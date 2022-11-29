#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
using namespace std; 


#define int long long 
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
template <class A> void write(vt <vt <A>> &v){
	EACH(x , v){
		EACH(y , x){
			cout << y << " " ; 
		}
		cout << endl ;
	}
	cout << endl ;
}
int n  , m ; 
vector <pair <int, int>> edgelist ; 
int findset(int i , int parent[]){
	if(parent[i] == -1){
		return i ;
	}
	return findset(parent[i] , parent) ;
}
void unite(int x , int y , int parent[]){
	int s1 = findset(x , parent) ; 
	int s2 = findset(y , parent) ;
	if(s1 != s2){
		parent[s1] = s2 ;
	}
}
bool containscycle(){
	int *parent = new int [n] ;
	for(int i = 1 ; i<= n ; i++){
		parent[i] = -1 ; 
	}

	for(auto edge : edgelist){
		int i = edge.first ;
		int j = edge.second ;

		int s1 = findset(i , parent) ; 
		int s2 = findset(j , parent) ; 

		if(s1 != s2){
			unite(s1 , s2 , parent) ;
		}
		else{
			return true ; 
		}
	}
	delete [] parent ; 
	return false ;
}
void solve(){
	cin >> n >> m ; 
	for(int i = 1 ; i <= m ; i++){
		int x , y ; 
		cin >> x >> y ; 
		edgelist.push_back(make_pair(x , y)) ; 
	}
	cout << containscycle() << endl ;
	return ;
}
int32_t main(){
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	int TET = 1 ; 
	/* read(TET) ; */ 
	FOR(i , 1 , TET + 1){
		solve() ;
	}
	return 0 ;
}
