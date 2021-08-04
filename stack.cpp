#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node* top=NULL;

int push(int data){
	struct node* newnode=new node;
	newnode->data=data;
	newnode->next=top;
	top=newnode;
}
void pop(){
	struct node* temp=top;
	cout<<"popped element is"<<temp->data<<endl;
	top=top->next;
}
void display(){
	struct node *temp=top;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	int n,data;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.exit"<<endl;
	do{
		cout<<"Enter the choice of operation";
		 cin>>n;
	switch(n){
		case 1:cout<<"enter the data to be pushed";
		cin>>data;
		push(data);
		break;
		
		case 2:pop();
		break;
		
		case 3:display();
		break;
		
		case 4:cout<<"exit";
		break;
		
		default:cout<<"invalid choice";
		break;
	}
    }while(n!=4);
    return 0;
}
