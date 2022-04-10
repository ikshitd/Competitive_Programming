#include <bits/stdc++.h>
#define int  long long int
#define F first
#define S second
#define pb push_back
const int mod = 1e9 + 7 ; 
const int sz = 5 ; 
using namespace std;
struct Mat{
    int m[sz][sz] ; 
    
    Mat(){

        memset(m , 0 , sizeof(m)); 
    }

    void identity(){
        for(int i = 0 ; i < sz ;i++){
            m[i][i] = 1; 
        }
    }

    Mat operator*(Mat a){

        Mat res ;
        for(int i = 0 ; i < sz ; i++){

            for(int j = 0; j < sz ;j++){

                for(int k = 0 ; k < sz ; k++){

                    res.m[i][j] += a.m[i][k] * m[k][j] ; 
                    res.m[i][j] %= mod ; 
                }
            }
        }
        return res ; 
    }
};
int new_fibo(int a , int b , int c , int d , int e , int n ){
    Mat res ; 
    res.identity() ; 
    Mat t ; 
    t.m[0][0] = a ; 
    t.m[0][1] = b ; 
    t.m[0][2] = c ; 
    t.m[0][3] = d ; 
    t.m[0][4] = e ; 
    t.m[1][0] = t.m[2][1] = t.m[3][2] = t.m[4][4] = 1 ; 
    if(n <= 4){
        return n - 1; 
    }
    n-= 4; 
    while(n){
        if(n &1 ){
            res = res * t ; 
        }
        t = t * t ; 
        n = n / 2 ; 
    }
    return (3 * res.m[0][0] + 2 * res.m[0][1] + res.m[0][2] + res.m[0][4])% mod ; 
}
void solve(){

    int a , b , c, d , e , n;  
    cin >> a >> b >> c >> d >> e >> n ; 
    cout << new_fibo(a,b,c,d,e,n) << endl ; 
}
int32_t main(){
    int t  = 1;
    //cin >> t ;
    while(t--){
        solve();
    }
}
