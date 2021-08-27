#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
int n;
void enqueue(){
	struct node* newnode=new node;
	if(newnode==NULL){
		cout<<"unable to allocate memory";
	}
	else{	
		cout<<"enter the value to be inserted :";
		cin>>n;
		newnode->data=n;
		newnode->next=NULL;
		if(front==NULL&&rear==NULL){
			front=rear=newnode;
		}
		else{
			rear->next=newnode;
			rear=newnode;
		}
	}
}
void dequeue(){
	if(front==-NULL){
		cout<<"queue is underflow";
	}
	else{
		cout<<"dequeued element is :"<<front->data<<endl;
		front=front->next;
	}
}
void peek(){
	if(front==-NULL&&rear==NULL){
		cout<<"the queue is underflow";
	}
	else{
		cout<<"the top element is :"<<front->data<<endl;
	}
}
void display(){
	struct node *temp=front;
	if(front==NULL&&rear==NULL){
		cout<<"queue is underflowing";
	}
	cout<<"elements in queue:"<<endl;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	int c;
	cout<<"1.insertion into queue"<<endl<<"2.deletion from queue"<<endl<<"3.peek"<<endl<<"4.display"<<endl<<"5.exit"<<endl;
	do{
		cout<<"enter your choice :";
		cin>>c;
		switch(c){
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:peek();
			break;
			case 4:display();
			break;
			case 5:cout<<"exit";
			break;
			default:cout<<"invalid choice";
		}
	}while(c!=5);
	
	return 0;
}
