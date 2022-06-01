#include <bits/stdc++.h>
#define int long long int 
#define F first
#define S second
#define pb push_back
const int mod = 1e9 + 7 ; 
const int N = 1e5 ; 
using namespace std ; 
int sievearr[N + 1] = {0} ; 
vector <int> primes ;
void sieve(){
	for(int i = 2 ; i <= N ; i++){
		if(sievearr[i] == 0){
			primes.push_back(i); 
		}
		for(int j = i * i ; j <= N ; j+=i){
			sievearr[j] =1 ; 
		}
	}
}
void solve(){
    int m , n ; 
    cin >> m >> n ; 
    sieve(); 

    vector <int> segment(n - m + 1 , 0);
    for(auto p : primes){

    	if(p * p > n){
    		break ; 
    	}

    	int start = (m / p) * p ; 

    	if(p >= m and p <= n){
    		start = 2 * p ; 
    	}
    	for(int j = start ; j <= n ; j+= p){
    		if(j < m){
    			continue ; 
    		}
    		else{
    			segment[j - m] = 1 ; 
    		}
    	}
    }
    for(int i = m ; i <= n ; i++){
    	if(segment[i - m] == 0 and i != 1){
    		cout << i << endl ; 
    	}
    }
    cout << endl ; 
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ; 
    freopen("output.txt" , "w" , stdout) ; 
#endif 
    int t = 1 ; 
    cin >> t ; 
    while(t--){

        solve();
    }
} 