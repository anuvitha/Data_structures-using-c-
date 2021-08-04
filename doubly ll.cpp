#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node *head=NULL;
struct node *last=NULL;
int data;
void insert();
void insert_at_end();
void insert_in_middle();
int create(int n){
	struct node* newnode=new node,*temp;
	int i;
	cout<<"enter the data for 1st node:";
	cin>>data;
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	head=newnode;
	last=head;
	for(i=1;i<n;i++){
	struct node* newnode=new node;
	cout<<"enter the data for " <<i+1<< " node:";
	cin>>data;
	newnode->data=data;
	newnode->prev=last;
	newnode->next=NULL;
	last->next=newnode;
	last=newnode;
	}
	return 0;
}
void insert(){
	struct node* newnode=new node;
	cout<<"insertion at beginning"<<endl;
	cout<<"enter data to be inserted:";
	cin>>data;
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
void insert_at_end(){
	struct node* newnode=new node;
	cout<<"insertion at end"<<endl;
	cout<<"enter data to be inserted:";
	cin>>data;
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=last;
	last->next=newnode;
	last=newnode;
}
void insert_in_middle(){
	struct node* newnode=new node,*temp=head;
	int a,i;
	cout<<"insertion at middle"<<endl;
	cout<<"enter the position to enter data:";
	cin>>a;
	if(head==NULL){
		insert();
	}
	else{
		cout<<"enter data to be inserted:";
	cin>>data;
	newnode->data=data;
	for(i=0;i<a-1;i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next->prev=newnode;
	temp->next=newnode;
   }
}
void delete_at_beginning(){
	struct node* temp=head;
	head=head->next;
	head->prev=NULL;
	cout<<"deleted element"<<temp->data<<endl;
}
void delete_at_end(){
	struct node* temp=last;
	last=last->prev;
	last->next=NULL;
	cout<<"deleted element"<<temp->data<<endl;
}
int delete_at_middle(){
	struct node* temp=head;
	int i=1,pos;
	cout<<"enter the position to delete";
	cin>>pos;
	while(i<pos){
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	cout<<"deleted element:"<<temp->data<<endl;
}
void display(){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	int n;
	cout<<"enter the data for no nodes:";
	cin>>n;
	create(n);
	insert();
	insert_at_end();
	insert_in_middle();
	display();
	cout<<"deletion"<<endl;
	delete_at_beginning();
    delete_at_end();
    delete_at_middle();
	display();
}
