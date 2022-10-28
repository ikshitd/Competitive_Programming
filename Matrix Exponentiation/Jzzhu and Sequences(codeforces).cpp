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
const int mx = 1e5 ;
const int mod = 1e9 + 7 ;
const int sz = 2 ;
int x , y ;
struct Mat{
    int m[sz][sz] ; 

    Mat(){
        memset(m , 0 , sizeof(m)) ; 
    }
    void identity(){
        for(int i =0 ; i < sz ; i++){
            m[i][i] = 1 ; 
        }
    }
    Mat operator* (Mat a){
        Mat res ; 
        for(int i = 0 ; i< sz ; i++){
            for(int j = 0 ; j <sz ; j++){
                for(int k = 0 ; k < sz ; k++){
                    res.m[i][j] += a.m[i][k] * m[k][j] ; 
                    res.m[i][j] %= mod ; 
                }
            }
        }
        return res ;  
    }
}; 
int fib(int n){
    Mat res ; 
    res.identity() ; 
    Mat t ; 
	t.m[0][0] = 1 ; 
	t.m[0][1] = -1 ; 
	t.m[1][0] = 1 ;
	n -= 2 ;
    while(n){
        if(n & 1){
            res = res * t ; 
        }
        t = t *t ; 
        n = n / 2 ; 
    }
	return (((res.m[0][0] * y + mod) + res.m[0][1] * x + mod) % mod + mod) % mod; 
}
void solve(){
	cin >> x >> y ; 
	int n ;
	cin >> n ; 
	if(n == 1){
		cout << (x + mod) % mod << endl ;
		return ;
	}
	cout << fib(n) << endl ;
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
