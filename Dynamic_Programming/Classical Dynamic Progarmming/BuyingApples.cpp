
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
const int INF = 1e15 ;
void solve(){
	int n , k ; 
	cin >> n >> k ; 
	vector  <int> v (k) ; 
	for(int i = 0 ; i < k ;i++){
		cin >> v[i] ;
	}
	vector <int> dp (k + 1 , INF) ; 
	dp[0] = 0 ; 
	for(int i = 0 ; i < k ; i++){
		for(int j = 0 ;j < k ; j++){
			if(i + j + 1 <= k and dp[i] != INF and v[i] != -1){
				dp[i + j + 1] = min(dp[i + j + 1] , dp[i] + v[j]) ;
			}
		}
	}
	if(dp[k] == INF){
		cout << -1 << endl ;
		return ;
	}
	cout << dp[k] << endl ; 
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
