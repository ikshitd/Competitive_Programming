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

const int N = 200000;

int arr[N] , cnt[N * 10]  ,distinct = 0 ;

struct query{
	int l , r , ans  , id , block; 

	bool operator< (query P) const{
		return make_pair(this->block , this-> r) < make_pair(P.block , P.r) ; 
	}
}q[N];

void add(int val){
	cnt[val] += 1 ; 
	if(cnt[val] == 1){
		distinct += 1 ; 
	}
}

void remove(int val){
	cnt[val] -= 1 ; 
	if(cnt[val ] == 0){
		distinct -= 1 ; 
	}
}

bool comp(query a , query b){
	return a.id  < b.id ; 
}
void solve(){
	int n ; 
	cin >> n;
	int m = sqrt(n);  
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i] ; 
	}	
	int queries ; 
	cin >> queries ; 
	for(int i = 0 ; i < queries ; i++){
		cin >> q[i].l >> q[i].r ;
		q[i].l -= 1 ; 
		q[i].r -= 1 ; 
		q[i].id = i ; 
		q[i].block = q[i].l / m ; 
	}
	sort(q , q + queries) ; 
	// for(int i =0 ;i < queries ; i++){
	// 	cout << q[i].id << " "<< q[i].l << " " << q[i].r << endl ;
	// }
	int x = 0 , y =0 ; 
	for(int i = 0 ; i < queries ; i++){
		while(y <= q[i].r){
			add(arr[y]); 
			y += 1 ; 
		}

		while(y > q[i].r + 1){
			y -= 1 ; 
			remove(arr[y]) ; 
		}

		while(x < q[i].l){
			remove(arr[x]) ; 
			x += 1 ; 
		}

		while(x > q[i].l){
			x -= 1 ;  
			add(arr[x]) ; 
		}

		q[i].ans = distinct ; 
	}
	sort(q , q + queries , comp) ; 

	for(int i = 0 ; i < queries ; i++){
		cout << q[i].ans << endl ; 
	}
	return ; 
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
