#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
struct node *head=NULL;
int data;
void insert();
void insert_at_end();
void delete_at_beginning();
void delete_at_end();
int create(int n){
	struct node* newnode=new node,*temp;
	int i;
	cout<<"enter the data for 1st node:";
	cin>>data;
	newnode->data=data;
	newnode->next=NULL;
	head=newnode;
	temp=head;
	for(i=1;i<n;i++){
	struct node* newnode=new node;
	cout<<"enter the data for" <<i+1<< "node:";
	cin>>data;
	newnode->data=data;
	newnode->next=head;
	temp->next=newnode;
	temp=newnode;
	}
	return 0;
}
void insert(){
	struct node* newnode=new node,*temp=head;
	cout<<"enter data to be inserted:";
	cin>>data;
	newnode->data=data;
	if(head==NULL){
	    newnode->next=newnode;
		head=newnode;
	}
	else{
	newnode->next=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	head=newnode;
	temp->next=head;
    }
}
void insert_at_end(){
	struct node* newnode=new node,*temp=head;
	cout<<"insertion at end"<<endl;
	if(head==NULL){
		insert();
	}
	else{
	cout<<"enter data to be inserted:";
	cin>>data;
	newnode->data=data;
	newnode->next=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=newnode;
   }
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
	temp->next=newnode;
    }
}
void delete_at_beginning(){
	struct node* temp=head,*delnode=head;
	if(head==NULL){
		cout<<"there is no node in the list"<<endl;
	}
	cout<<"deleted element is:"<<temp->data<<endl;
	while(delnode->next!=head){
		delnode=delnode->next;
	}
	head=head->next;
	delnode->next=head;
}
void delete_at_end(){
	struct node* temp=head,*current;
	if(head==NULL){
		cout<<"there is no node in the list"<<endl;
	}
	if(head->next==head){
		delete_at_beginning();
	}
	else{
	while(temp->next!=head){
		current=temp;
		temp=temp->next;
	}
	current->next=head;
	cout<<"deleted element is:"<<temp->data<<endl;
   }
}
void delete_at_middle(){
	struct node* temp=head,*current;
	int m,i;
	cout<<"enter a position to delete:";
	cin>>m;
	if(head->next==NULL){
		delete_at_beginning();
	}
	else{
	for(i=0;i<m-1;i++){
		current=temp;
		temp=temp->next;
	}
	if(temp->next==NULL){
	  delete_at_end();	
	}
	current->next=temp->next;
	cout<<"deleted element is:"<<temp->data<<endl;
   }
}
void display(){
	struct node* temp=head;
	while(temp->next!=head){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
int main(){
	int n,a;
	cout<<"enter the data for no nodes:";
	cin>>n;
	if(n>=1){
	create(n);
	cout<<"1.insertion at beginning"<<endl<<"2.insertion at end"<<endl<<"3.insertion at position"<<endl;
	cout<<"4.deletion at first"<<endl<<"5.deletion at end"<<endl<<"6.deletion at position"<<endl<<"7.display"<<endl<<"8.exit"<<endl;
	do{
		cout<<"enter the choice of operation:";
		cin>>a;
		switch(a){
		case 1:cout<<"insertion at beginning"<<endl;
		insert();
		 display();
	     break;
	    case 2:insert_at_end();
	     display();
	     break;
	    case 3:insert_in_middle();
	           display();
	           break;
	    case 4:cout<<"deletion"<<endl;
	         delete_at_beginning();
	         display();
	         break;
        case 5:delete_at_end();
               display();
               break;
        case 6:delete_at_middle();
	           display();
	           break;
	    case 7:display();
	         break;
	    case 8:cout<<"exit";
	        break;
	    default:cout<<"invalid choice";
	    break;
 	    }
   }while(a!=8);
  }
  else{
  	cout<<"enter valid no";
  }
   return 0;
}
