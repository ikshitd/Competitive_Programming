#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std ;

// Euclid's Theorem 
int gcd(int a , int b){
    if(b == 0){
        return a ; 
    }
    return (b , a % b) ; 
}
// Another way of finding the gcd of two numbers 
int gcd2(int a , int b){

    if(b == a){
        return a ; 
    }
    else{

        if(a > b){
            return gcd2(a - b  , b) ; 
        }
        else{
            return gcd2(a , b - a); 
        }
    }
}

// Extended Euclid's Theorem to find the sol^n of ax + by = gcd(a , b)

// General Sol^n ==> x = y1 and y = x1 - (a / b) * y1 
vector <int> euclid_theorem(int a , int b){

    if(b == 0){
        return {1 , 0 , a} ; 
    }
    vector <int> result =  euclid_theorem(b , a % b) ; 

    int smallx = result[0] ; 
    int smally = result[1] ; 
    int gcd = result[2] ; 

    int x = smally ; 
    int y = smallx - (a / b) * smally ; 

    return {x , y , gcd} ; 
}

// Using Extended Euclid's Theorem to find out the Modulo Inverse 

// (a * x) % m == 1 ---> To find out the value of x 
int moduloinverse(int a , int m){

    vector <int> ans = euclid_theorem(a , m) ; 

    if(ans[2] != 1){
        cout << "The multiplicative modulo inverse does not exist" << endl ; 
        return (0 , 0) ; 
    }

    int x = ans[0] ; 
    return (x % m + m) % m ; 
}

// Using Extended Euclid's Theorem to find out the sol^n of Linear Diphantine Eq^n 
// ax + by = c --> input a , b , c
// g = gcd(a , b)
// The sol^n will exist only if (c % g == 0)
// k = c / g 
// Let x0 and y0 be the sol^n of the extended Euclid's Theorem then ..
// x = k * (x0)
// y = k * (y0)
vector <int> linear_diphantine(int a , int b , int c){

    vector <int> result = euclid_theorem(a , b) ; 

    if(c % result[2] != 0){
        cout << "The solution does not exist " << endl ; 
        return {0 , 0} ; 
    }
    
    int k = c / result[2] ; 

    int x = result[0] * k ; 
    int y = result[1] * k ; 

    return {x , y} ; 
}
void solve(){

    int a , b , c ; 
    cin >> a >> b >> c ; 
    
    vector <int> ans = linear_diphantine(a , b , c)  ; 

    cout << ans[0] << " " << ans[1] << endl ; 
}
int32_t main(){
    int t = 1 ;
    // cin >> t ;
    while(t--){
    solve();
    }
}
