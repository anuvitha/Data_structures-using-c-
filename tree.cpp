#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(){
	int x;
	struct node *newnode=new node;
	cout<<"enter data to be inserted(-1 for no node)"<<endl;
	cin>>x;
	if(x==-1){
		return 0;
	}
	newnode->data=x;
	cout<<"enter the left child of "<<x<<endl;
	newnode->left=create();
	cout<<"enter the right child of "<<x<<endl;
	newnode->right=create();
	return newnode;
}
int inorder(struct node *root){
	if(root==NULL){
		return 0;
	}
	inorder(root->left);
	cout<<root->data<<"->";
	inorder(root->right);
}
int preorder(struct node *root){
	if(root==NULL){
		return 0;
	}
	cout<<root->data<<"->";
	preorder(root->left);
	preorder(root->right);
}
int postorder(struct node *root){
	if(root==NULL){
		return 0;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"->";
}
int main(){
	struct node *root;
	root=NULL;
	root=create();
	cout<<"inorder traversal:"<<endl;
	inorder(root);
	cout<<"preorder traversal:"<<endl;
	preorder(root);
	cout<<"post order traversal:"<<endl;
	postorder(root);
	return 0;
}
