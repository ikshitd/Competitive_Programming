#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
class Node{
public : 
	int data ; 
	Node *next = NULL ; 
	Node(int a){
		data = a ; 
		next = NULL ; 
	}
}; 
bool isEmpty(Node *head){
	return head == NULL ; 
}
Node *push(Node *head , int x){
	Node *node = new Node(x) ; 
	node -> next = head ; 
	return node ; 
}
Node *pop(Node *head){
	if(isEmpty(head)){
		cout << "THE STACK IS EMPTY" << endl ; 
		return NULL ; 
	}
	else{
		return head -> next ; 
	}
}
void print(Node *head){
	Node *current = head ; 
	while(current != NULL){
		cout << current -> data << " "  ;
		current = current -> next ; 
	}
	cout << endl ; 
	return ; 
}
int32_t main(){
	Node *head = nullptr ; 
	head = push(head , 7) ; 
	head = push(head , 6) ; 
	head = push(head , 3) ; 
	head = pop(head) ; 
	head = push(head , 90) ; 
	print(head) ; 
	return 0 ; 
} 
