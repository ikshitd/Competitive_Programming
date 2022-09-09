#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
const int N = 5 ; 
class Stack{
public : 
	int num[N] ; 
	int top ; 

	Stack(){
		top = -1 ; 
	}
	int isEmpty(){
		if(top == -1) return 1 ; 
		else{
			return 0 ; 
		}
	}
	int isFull(){
		if(top == (N - 1)){
			return 1   ; 
		}
		else{
			return 0 ; 
		}
	}
	int push(int n){
		// check if the stack if full or not 
		if(isFull()){
			return 0 ; 
		}
		top+= 1 ; 
		num[top] = n ; 
		return n ; 
	}
	int pop(){
		if(isEmpty()){
			return 0 ; 
		}
		int temp = num[top] ; 
		top = top - 1 ; 
		return temp  ;
	}
	void display(){
		for(int i = top ; i >= 0 ; i--){
			cout << num[i]  <<  " "  ; 
		}
		cout << endl ;
	}
}; 
int32_t main(){
	Stack st ;
	int t ; 
	cin >> t ; 
	int arr[t] ; 
	for(int i = 0 ; i < t ; i++){
		int x ; 
		cin >> x ; 
		arr[i] = st.push(x) ; 
	} 
	st.display() ; 
	int a = st.pop() ; 
	cout << a << endl ; 
	st.display() ; 
}
