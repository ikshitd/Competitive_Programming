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

int n , m , k  , arr[20][20] , ans = 0 , mid; 

map <int , int> mp[21][21] ; 

void subsetleft(int arr[][20] , int i , int j , int val , int cnt){
	val = val ^ arr[i][j] ; 
	if(cnt == mid){
		mp[i][j][val]++ ; 
		return ;
	}
	// we can move right or down 
	if(i + 1 < n){
		subsetleft(arr , i + 1 , j , val , cnt + 1) ;
	}
	if(j + 1 < m){ 
		subsetleft(arr , i , j + 1 , val , cnt + 1) ;
	} 
	return ; 
}
void subsetRight(int arr[][20] , int i , int j , int val , int cnt){
	if(cnt ==(n + m - 2 - mid)){
		ans += (mp[i][j][val ^ k]); 
		return ; 
	}

	val = val ^ arr[i][j] ; 
	if(i > 0){
		subsetRight(arr , i - 1 , j , val , cnt + 1) ; 
	}
	if(j > 0){
		subsetRight(arr , i , j - 1 , val , cnt  + 1) ; 
	}
	return ; 
}
void solve() {

	cin >> n >> m >> k ;
	for(int i = 0 ;i < n ; i++){
		for(int j = 0 ;j < m ;j++){
			cin >> arr[i][j] ; 
		}
	}
	mid = (n + m - 2) / 2 ; 
	int val = 0  ,cnt = 0 ; 
	subsetleft(arr , 0 , 0 , val , cnt); 
	subsetRight(arr , n - 1  , m -1 , val , cnt)  ;
	cout << ans << endl ; 
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