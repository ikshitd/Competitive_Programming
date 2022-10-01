#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define N 10 
int front =0 , rear = -1 ; 
int currentsize = 0 ;  
int arr[N]   ;
bool isEmpty(){
	return currentsize == 0 ; 
} 
bool isFull(){
	return currentsize == N ; 
}
int size(){
	return currentsize ; 
}

void enqueue(int val){
	if(isFull() == false){
		if(rear == N - 1){
			rear = -1 ; 
		}
		arr[++rear] = val ; 
		currentsize +=1 ; 
	}
}
int dequeue(){
	int data = arr[front++] ; 
	if(front == N){
		front = 0 ; 
	}
	currentsize -= 1 ; 
	return data ; 
}
void print(){
	while(currentsize > 0){
		printf("%d " , arr[front]) ; 
		dequeue() ; 
	}
	printf("\n") ; 
}
int main(){
	enqueue(10) ; 
	enqueue(29) ; 
	enqueue(3232) ; 
	enqueue(32) ; 
	dequeue() ; 
	print() ; 
}
