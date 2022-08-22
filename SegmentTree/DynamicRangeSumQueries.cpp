#include <bits/stdc++.h>
 
using namespace std;
 
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define read(a , n)	   for(int i = 0 ;i < n; i++) cin >> arr[i] ;
 
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
 
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
 
const int N = 200005;
struct segmenttree{
 
	int n ; 
	vector <int> st ;
 
	void init(int _n){
		this->n = _n ; 
		st.resize(4 * n , 0); 
	} 	
 
	void build(int start , int ending , int node , vector <int> &v){
		// base case leaf node
		if(start == ending){
			st[node] = v[start] ; 
			return ; 
		}
		
		int mid = (start + ending) /2 ; 
		// left subtree 
		build(start , mid , 2 * node + 1 , v);
		// right subtree
		build(mid + 1 , ending , 2 * node + 2 , v) ; 	
		// for summation 
		st[node] = st[2 * node + 1] + st[2 * node + 2] ; 
	}
 
	int query(int start , int ending , int l , int r , int node){
		// non onverlapping case 
		if(start > r or (ending < l)){
			return 0 ; 
		}
		// overlapping case
		if(start >= l and ending <= r){
			return st[node] ; 
		}
		// partial overlapping case
		int mid = (start + ending )/ 2 ; 
		int q1 = query(start , mid , l , r , 2 * node + 1) ; 
		int q2 = query(mid + 1 , ending , l , r , 2 * node + 2) ; 
		return q1 + q2 ; 
	}
 
	void build(vector <int> &v){
		build(0 , v.size() - 1 , 0 ,v) ; 
	}
 
	void update(int start , int ending , int node , int index , int value){
		
		if(start == ending){
			st[node] = value ; 
			return ; 
		}
		int mid = (start + ending) /2 ; 
		if(index <= mid){
			update(start , mid , 2 * node + 1 , index , value) ; 
		}
		else{
			update(mid + 1 , ending , 2 * node + 2 , index , value) ; 
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2] ; 
	}
 
	int query(int l , int r){
		return query(0 , n - 1 , l , r , 0); 
	}
 
	void update(int x ,int y){
		update(0 , n - 1 , 0, x , y); 
	}
};
void solve() {
	int n , q ; 
	cin >> n >> q ; 
	vector <int> v  ; 
	for(int i = 0 ;i < n ; i++){
		int x ; 
		cin >> x ; 
		v.pb(x) ; 
	}
	segmenttree tree ; 
	tree.init(v.size()) ; 
	tree.build(v) ; 
	while(q--){
		int a ; 
		cin >>a ; 
		if(a == 1){
			int k , u ; 
			cin >> k >> u ; 
			tree.update(k - 1 , u) ; 
			continue ; 
		}
		int l , r ; 
		cin >> l >> r ; 
		cout << tree.query(l - 1 , r - 1) << endl ; 		
	}	
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	clock_t z = clock();
 
	int t = 1;
	// cin >> t;
	while (t--) solve();
 
	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
	return 0;
}
