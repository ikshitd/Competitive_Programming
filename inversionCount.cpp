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

int merge(int arr[] , int l , int h){
	int i = l ; 
	int mid = (l + h) / 2 ; 
	int j = mid + 1 ;
	vi v ;  
	int cnt = 0 ; 
	while(i <= mid and j <= h){
		if(arr[i] > arr[j]){
			cnt += (mid - i + 1) ; 
			v.pb(arr[j]); 
			j += 1; 
		}
		else{
			v.pb(arr[i]); 
			i += 1 ; 
		}
	}
	while(i <= mid){
		v.pb(arr[i]) ; 
		i += 1; 
	}
	while(j <= h){
		v.pb(arr[j]) ; 
		j += 1 ; 
	}
	return cnt; 
}
int inversionCount(int arr[] , int l , int h){
	if(l >= h){
		return 0;
	}
	int mid = (l + h) / 2 ; 
	int c1 = inversionCount(arr , l , mid) ; 
	int c2 = inversionCount(arr , mid + 1 , h) ; 
	int ci = merge(arr , l , h) ; 
	return c1 + c2 + ci ; 
}
void solve() {
	int n ; 
	cin >> n ; 
	int arr[n] ; 
	for(int i = 0 ;i < n; i++){
		cin >> arr[i] ; 
	}
	int l = 0 , h = n - 1 ; 
	cout << inversionCount(arr , l , h) << endl; 
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
	// cin >> t;b
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}