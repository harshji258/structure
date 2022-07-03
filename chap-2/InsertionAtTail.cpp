#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertNode(node* &head,int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	node* head=NULL;
	insertNode(head,1);
	insertNode(head,2);
	display(head);
	int n;
	cout<<"enter a value you want insert : ";
	cin>>n;
	insertNode(head,n);
	display(head);
    return 0;
}
