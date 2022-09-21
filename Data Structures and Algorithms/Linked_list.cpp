#include <bits/stdc++.h> 
#define int long long int 
using namespace std ; 
class Node{
public : 
	int data ; 
	Node *next ; 
	Node(int a){
		data = a ; 
		next = NULL ; 
	}
}; 
Node *insertatbeginning(Node *head , int val){
	Node *node =new Node(val) ; 
	node -> next = head ; 
	head = node ; 
	return head ; 
}
Node *insertatend(Node *head , int val){
	Node *node = new Node(val); 
	if(head == NULL){
		head = node ; 
	}
	else{
		Node *current = head ; 
		while(current -> next != NULL){
			current = current -> next ; 
		}
		current -> next =node ; 
		return head ; 
	} 
	return head ; 
}
void display(Node *head){
	Node *current = head ; 
	while(current){
		cout << current -> data << " " ; 
		current = current -> next ; 
	}
	cout << endl ;
}
bool search(Node *head , int key){
	Node *current = head ; 
	while(current){
		if(current -> data == key){
			return true ; 
		}
		current = current -> next ; 
	}
	return false ; 
}
Node *deleteatbeginning(Node *head){
	Node *node = head ; 
	head = head -> next ; 
	delete node ; 
	return head ; 
}
Node *deletion(Node *head , int val){
	if(head == NULL){
		return NULL ; 
	}
	if(head -> next == NULL){
		head = deleteatbeginning(head) ; 
	}
	Node *current = head ; 
	while(current -> next-> data != val){
		current = current -> next ; 
	}
	Node *node = current -> next ; 
	current -> next = current -> next -> next ; 
	delete node ; 
	return head ; 
}
Node *reverse(Node *head){
	Node *current = head ; 
	Node *prev = NULL ; 
	while(current){
		Node *next_node = current -> next ; 
		current -> next = prev ; 
		prev =current ; 
		current = next_node ; 
	}
	return prev ; 
}
Node *reverserecursion(Node *current , Node *prev){
	if(current == NULL){
		return prev ; 
	}
	Node *next_node = current -> next ; 
	current -> next = prev ; 
	prev = current ; 
	reverserecursion(next_node , prev) ; 
}
// kth node from the end
void kth(int k, Node* head)
{
    Node* forw = head;
    Node* backw = head;
    for (int i = 0; i < k - 1; i++)
    {
        forw = forw->next;
    }
    while (forw->next)
    {
        backw = backw->next;
        forw = forw->next;
    }
    cout << backw->data;
}
bool issorted(Node *head){
	Node *current = head ; 
	while(current -> next){
		if(current -> data > current -> next -> data){
			return fasle ; 
		}
		current = current -> next ; 
	}
	return true ; 
}
// to reverse the k consecutive nodes
Node *reversek(Node *head , int k){
	Node *prev = NULL ; 
	Node *current = head ; 
	Node *next_node ; 
	int cnt = 0 ; 
	while(current != NULL and cnt < k){
		next_node = current -> next ; 
		current -> next = prev ; 
		prev = current ; 
		current = next_node ; 
		cnt += 1 ; 
	}
	if(next_node != NULL){
		head -> next = reversek(next_node , k) ; 
	} 
	return prev ; 
}
// to find the midpoint of the linked list 
Node *midpoint(Node *head){
	Node *slow = head ; 
	Node *fast = head ; 
	while(slow and fast and fast -> next and fast -> next -> next){
		slow = slow -> next ; 
		fast = fast -> next -> next ; 
	}
	return slow ; 
}
void makecycle(Node *head , int pos){
	Node *current = head ; 
	Node* start ; 
	int cnt = 1 ; 
	while(current -> next != NULL){
		if(cnt == pos){
			start = current ; 
		}
		current = current -> next ; 
		cnt += 1 ; 
	}	
	current -> next = start ; 
}
// cycle detection
bool detectcycle(Node *head){
	Node *slow = head ; 
	Node *fast = head ; 
	while(slow and fast and fast -> next and fast -> next -> next){
		slow = slow -> next ; 
		fast = fast -> next -> next ; 
		if(fast == slow){
			return true ; 
		}
	}
	return false ; 
}
// remove the cycle from the linked list
Node *removecycle(Node *head){
	Node *fast = head ; 
	Node *slow = head ; 

	do{
		slow = slow -> next ; 
		fast = fast -> next -> next ; 
	}while(slow != fast) ; 

	fast = head ; 
	while(slow -> next != fast -> next){
		slow = slow -> next ; 
		fast = fast -> next ; 
	}
	slow -> next = NULL ; 
	return head ; 
}
int length(Node *head){
	int cnt = 0 ; 
	Node *current = head ; 
	while(current){
		cnt += 1 ; 
		current = current -> next ; 
	}
	return cnt ; 
}
// append the last k nodes of the linked list to the beginning of the linked list
Node *kappend(Node *head , int k){
	Node *newhead ; 
	Node *newtail ; 
	Node *tail = head ; 
	int l = length(head) ; 
	k = k % l  ; 
	int cnt = 1 ; 
	while(tail-> next != NULL){
		if(cnt == l - k){
			newtail = tail ; 
		}
		if(cnt == l - k + 1){
			newhead = tail ; 
		}
		tail = tail -> next ; 
		cnt += 1 ;
	}
	newtail -> next = NULL ; 
	tail -> next = head ; 
	return newhead ; 
}
// to make the two linked list intersect
void intersect(Node *head1 , Node *head2 , int pos){
	Node *current = head1 ; 
	pos -= 1 ; 
	while(pos--){
		current = current -> next ; 
	}
	Node *curr = head2 ; 
	while(curr -> next != NULL){
		curr = curr -> next ; 
	}
	curr -> next = current ; 
}
// find the intersection of the given two linked list
int intersection(Node *head1 , Node *head2){
	int l1 = length(head1) ; 
	int l2 = length(head2) ; 
	int d = 0 ; 
	Node *ptr1 ; 
	Node *ptr2 ; 
	if(l1 > l2){
		d = l1 - l2 ; 
		ptr1 = head1 ; 
		ptr2 = head2 ; 
	}
	else{
		d = l2 - l1  ; 
		ptr1 = head2 ; 
		ptr2 = head1 ; 
	}
	while(d--){
		ptr1 = ptr1-> next ; 
		if(ptr1 == NULL){ return -1 ; 
		}
	}
	while(ptr1 != NULL and ptr2 != NULL){
		if(ptr1 == ptr2){
			return ptr1 -> data ; 
		}
		ptr1 = ptr1 -> next ; 
		ptr2 = ptr2 -> next ;
	}
	return -1 ; 
}
/* merging the two sorted linked list */
Node *merge(Node *head1 , Node *head2){
	Node *ptr1 = head1 ; 
	Node *ptr2 = head2 ; 
	Node *dn = new Node(-1) ; 
	Node *ptr3 = dn ; 
	while(ptr1 != NULL and ptr2 != NULL){
		if(ptr1 -> data < ptr2 -> data){
			ptr3-> next = ptr1 ; 
			ptr1 = ptr1 -> next ; 
		}
		else{
			ptr3 -> next = ptr2 ; 
			ptr2 = ptr2 -> next ; 
		}
		ptr3 = ptr3 -> next ; 
	}
	while(ptr1 != NULL){
		ptr3 -> next = ptr1 ; 
		ptr1 = ptr1 -> next ; 
		ptr3 = ptr3 -> next ; 
	}
	while(ptr2 != NULL){
		ptr3 -> next = ptr2 ; 
		ptr2 = ptr2 -> next ; 
		ptr3 = ptr3 -> next ; 
	}
	return dn -> next ; 
}
/* merge the two sorted linked list using recursion */
Node *mergerecursive(Node *head1 , Node *head2){
	if(head1 == NULL){
		return head2 ;
	}
	if(head2 == NULL){
		return head1 ; 
	}
	Node *result ; 
	if(head1 -> data < head2 -> data){
		result = head1 ; 
		result -> next = mergerecursive(head1 -> next , head2) ; 
	}
	else{
		result = head2 ; 
		result -> next = mergerecursive(head1 , head2 -> next) ; 
	}
	return result ; 
}
void solve(){
	int arr[] = {1 , 2 , 3} ; 
	int v[] = {7 , 8 , 9} ; 
	Node *head  = NULL ; 
	Node *head2 = NULL ; 
	for(int i = 0 ; i < 3 ; i++){
		head = insertatend(head , arr[i]) ; 
	}
	for(int i = 0 ; i < 3 ; i++){
		head2 = insertatend(head2 , v[i]) ; 
	}
	head = mergerecursive(head , head2) ; 
	display(head) ; 
} 
int32_t main(){
	int t = 1 ; 
	while(t--){
		solve() ; 
	}
}
