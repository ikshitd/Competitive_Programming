#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
#define int int64_t 
#define double long double 

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e18 ;

// space complexity --> O(n * x) 
int solve() {
    int n ; 
    cin >> n ; 
    int a[n] ;  
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ; 
    }
    int x ; 
    cin >> x ;
    int dp[n + 1][x + 1] ;
    memset(dp , 0 , sizeof(dp)) ;
    dp[0][0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        dp[i][a[i]] = 1 ;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= x ; j++){
            dp[i][j] = dp[i - 1][j] ;
            if(j - a[i] >= 0){
                dp[i][j] += dp[i - 1][j - a[i]] ;
            }
        }
    }
    cout << dp[n - 1][x] << "\n" ;
    return 0 ;
}

// space complexity --> O(2 * x) 
int find_answer(){
    int n ; 
    cin >> n ; 
    int a[n] ; 
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    int x ; 
    cin >> x ;
    int dp[2][x + 1] ;
    memset(dp , 0 , sizeof(dp)) ;
    dp[0][0] = 1 ; 
    dp[0][a[0]] = 1 ;
    for(int i = 1; i < n ;i++){
        for(int j = 0 ; j <= x ; j++){
            dp[1][j] = dp[0][j] ;
            if(j - a[i] >= 0){
                dp[1][j] += dp[0][j - a[i]] ;
            }
        }
        for(int i = 0 ; i <= x ; i++){
            dp[0][i] = dp[1][i] ;
        }
    }
    cout << dp[1][x] << "\n" ;
    return 0 ;
}

// space complexity --> O(x) 
int find_ans(){
    int n ; 
    cin >> n ; 
    int a[n] ;
    for(int i = 0 ; i < n ;i++){
        cin >> a[i] ;
    }
    int x ; 
    cin >> x ;
    int dp[x + 1] ; 
    memset(dp , 0 , sizeof(dp)) ;
    dp[0] = 1 ;
    dp[a[0]] = 1;
    for(int i = 1 ; i < n ; i++){
        for(int j = x ; j >= 0 ; j--){
            if(j - a[i] >= 0){
                dp[j] += dp[j - a[i]] ; 
            }
        }
    }
    cout << dp[x] << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    for (int i = 1; i <= TET; i++) {
        if (find_ans()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}

