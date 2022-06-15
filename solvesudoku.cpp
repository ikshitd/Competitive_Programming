#include <bits/stdc++.h>
#define int long long int 
#define F first
#define S second
#define pb push_back
const int mod = 1e9 + 7 ; 
using namespace std ; 
bool canPlace(int arr[][9] , int no , int i , int j , int n){
	// for rows and columns 
	for(int k = 0 ; k < n ; k++){
		if(arr[i][k] == no || arr[k][j] == no){
			return false ; 
		}
	}

	// for subgrid
	int sx = (i / 3) * 3 ; 
	int sy = (j / 3) * 3 ; 
	for(int x = sx ; x < sx + 3 ; x++){
		for(int y = sy ; y < sy + 3 ; y++){
			if(arr[x][y] == no){
				return false ; 
			}
		}
	}

	return true ; 
}
void printBoard(int arr[][9] , int n){
	for(int i = 0 ; i < n ;i++){
		for(int j = 0 ;j < n ; j++){
			cout << arr[i][j] << " " ;
		}
		cout << endl ;
	}
	cout << endl ; 
}
bool solvesudoku(int arr[][9] , int i , int j , int n){
	// base case 
	if(i == n){
		printBoard(arr , n) ;
		return true ; 
	}
	// recursive case
	// if we are at the end of row 
	if(j == n){
		return solvesudoku(arr, i + 1 , 0 , n) ; 
	}
	// if the cell is already filled
	if(arr[i][j] != 0){
		return solvesudoku(arr , i , j + 1 , n) ;
	}
	// if the val has to be placed 
	for(int no = 1 ; no <= 9 ; no++){
		if(canPlace(arr , no , i , j , n) == true ){
			arr[i][j] = no ; 
			bool subproblem = solvesudoku(arr , i , j + 1 , n);
			if(subproblem == true){
				return true ; 
			}
		}
		// if it does not make sense place it here 
	}
	arr[i][j]= 0 ; 
	return false ; 
}
void solve(){

	int n = 9 ; 
	int arr[9][9] = 
		{{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    if(!solvesudoku(arr , 0 , 0 ,n)){
    	cout << "The solution does not exist" << endl ; 
    }
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