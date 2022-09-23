#include <bits/stdc++.h> 
#define int long long int
using namespace std ;
class Node{
public : 
	int data ; 
	Node *next  ; 
	Node(int a){
		data = a ; 
		next = NULL ; 
	}
} ;
void display(Node *head){
	if(head == NULL){
		return ; 
	}
	else{
		Node *current = head ; 
		while(current){
			cout << current -> data << " " ;
			current = current -> next ; 
		}
		cout << endl ; 
		return ;
	}
}
Node *insertatbeginning(Node *head , int val){
	Node *node = new Node(val) ;
	if(head == NULL){
		head = node ; 
	}
	else{
		node -> next = head ; 
		head = node ;
	}
	return head ; 
}
Node *insert(Node *head , int val , int pos){
	Node *node = new Node(val) ;
	if(head == NULL){
		head = node ; 
	}
	else{
		int cnt = 0 ; 
		Node *current = head ; 
		while(current){
			if(cnt == pos - 1){
				break ;
			}
			current = current -> next ; 
			cnt += 1 ; 
		}
		Node *next_node = current -> next ; 
		node -> next = next_node ; 
		current -> next = node ; 
	}
	return head ; 
}
Node *addTwoLinkedList(Node *a , Node *b){
	if(b == NULL ){
		return a ; 
	}
	if(a == NULL){
		return b ;
	}
	Node *result = nullptr ; 
	Node *current = nullptr ; 
	int sum = 0 , carry = 0 ; 
	while(a != NULL and b != NULL){
		sum = a -> data + (b -> data) + carry ; 
		carry = sum / 10 ; 
		sum = sum % 10 ; 
		if(result == nullptr){
			result = new Node(sum) ; 
			current = result ; 
		}
		else{
			current -> next = new Node(sum) ;
			current = current -> next ; 
		}
		a = a -> next ; 
		b = b -> next ; 
	}
	Node *temp = nullptr ; 
	if(a == NULL){
		temp = b ; 
	}
	if(b == NULL){
		temp = a ; 
	}
	while(temp != NULL){
		sum = temp -> data + carry ; 
		carry = sum / 10 ; 
		sum = sum % 10 ; 
		current -> next = new Node(sum) ;
		current = current -> next ; 
		temp = temp -> next ; 
	}
	if(carry > 0){
		current -> next = new Node(carry) ;
	}
	return result ; 
}
void solve(){
	Node *head = nullptr ; 
	head = insertatbeginning(head , 1); 
	head = insertatbeginning(head , 2); 
	head = insertatbeginning(head , 3); 
	Node *head2 = nullptr ; 
	head2 = insertatbeginning(head2 , 4) ;  
	head2 = insertatbeginning(head2 , 5) ;  
	head2 = insertatbeginning(head2 , 6) ;  
	head2 = insertatbeginning(head2 , 8) ; 
	// 123 + 4568 == 4691
	Node *ans = addTwoLinkedList(head , head2) ;
	display(ans) ; 
	return ;
}
int32_t main(){
	int t ; 
	cin >> t ; 
	while(t--){
		solve() ; 
	}
}
