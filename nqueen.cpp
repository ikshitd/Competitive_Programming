#include <bits/stdc++.h>
#define int long long int 
#define F first
#define S second
#define pb push_back
const int mod = 1e9 + 7 ; 
using namespace std ; 
bool canPlace(int n , int board[][20] , int x , int y){

	// check for columns 
	for(int k = 0 ; k < x ; k++){
		if(board[k][y] == 1){
			return false ; 
		}
	}
	// check for left diagonal 
	int i = x ; 
	int j = y ; 
	while(i >= 0 and j >= 0){
		if(board[i][j] == 1){
			return false ; 
		}
		j -=1 ; 
		i -=1 ; 
	}

	// check for the right diagonal 
	i = x ; 
	j = y ; 
	while(i >= 0 and j < n){
		if(board[i][j] == 1){
			return false ; 
		}
		i -= 1; 
		j += 1 ; 
	}

	return true ; 

}
void printBoard(int n , int board[][20]){
	for(int i = 0 ; i< n ; i++){
		for(int j = 0 ; j< n ; j++){
			cout << board[i][j] << " " ; 
		}

		cout << endl ; 
	}
	cout << endl ; 
}
bool nqueen(int n , int board[][20] , int i){
	// base case 
	if(i ==  n){
		printBoard(n , board) ; 
		return true ; 
	}
	//recursive case 
	for(int j = 0 ; j < n ;j++){
		if(canPlace(n , board , i , j)){
			board[i][j] = 1 ; 
			bool success = nqueen(n , board , i + 1) ; 
			if(success){
				return true ; 
			}
			// backtrack 
			board[i][j] = 0 ; 
		}
	}
	return false ; 
}
void solve(){
    
    int board[20][20] = {0} ; 
    int n ; 
    cin >> n ;

    nqueen(n , board , 0) ; 
    return ; 
}
int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ; 
    freopen("output.txt" , "w" , stdout) ; 
#endif 
    int t = 1 ; 
    // cin >> t ; 
    while(t--){

        solve();
    }
}