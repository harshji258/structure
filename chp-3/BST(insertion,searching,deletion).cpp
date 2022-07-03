#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
	Node(int val){
	  data=val;	
	  left=NULL;
	  right=NULL;
	}
};
  
Node* insertBST(Node *root,int val){
	if(root==NULL){
	  return new Node(val);
	}
	else if(val<root->data)
	    root->left=insertBST(root->left,val);
	else
	 	root->right=insertBST(root->right,val);
	return root;
}
Node* searchInBST(Node* root,int val){
	if(root==NULL)
	 return NULL;
	if(root->data==val)
	  return root;
	else if(root->data>val)
	  return searchInBST(root->left,val);
	else
	  return searchInBST(root->right,val);
}
void inorder(Node *root){
	if(root==NULL)
	 return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* inoderSucc(Node* root){
	Node* curr=root;
	while(curr && curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
Node* deleteInBST(Node* root,int key){
	if(key<root->data)
	  root->left=deleteInBST(root->left,key);
	else if(key>root->data)
	  root->right=deleteInBST(root->right,key);
	else{
		if(root->left==NULL){
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node* temp=root->left;
			free(root);
			return temp;
		}
		 Node* temp=inoderSucc(root->right);
		 root->data=temp->data;
		 root->right=deleteInBST(root->right,temp->data);
	} 
	return root;
}
int main(){
	Node *root=NULL;
	cout<<"creating BST"<<endl;
	root=insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,4);
	insertBST(root,7);
	insertBST(root,2);
	inorder(root);
	cout<<endl<<"searching in BST :"<<endl;
	if(searchInBST(root,7)==NULL)
	  cout<<"key is not present"<<endl;
	else
	  cout<<"key is present"<<endl;
	cout<<"deletingin BST :\n";
	 deleteInBST(root,5);
	inorder(root);
	
}
