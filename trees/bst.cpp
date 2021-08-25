#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//accepts the old root node and data & returns the new nroot ndoe
node*insertinBST(node*root, int data){

	//base case
	if(root == NULL){
		return new node(data);
	}

	//rec case- insert in the subtree and update the pointer
	if(data <= root->data){
		root->left = insertinBST(root->left,data);
	}
	else{
		root->right = insertinBST(root->right,data);
	}
	return root;
}



node* build(){
	int d;
	cin>>d;

	node*root = NULL;

	while(d != -1){
		root = insertinBST(root,d);
		cin>>d;
	}
	return root;
}

void bfs(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* f = q.front();
		if(f == NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<" ,";
			q.pop();

			if(f->left){
				q.push(f->left);
			}

			if(f->right){
				q.push(f->right);
			}
		}
	}
	return;

}

void inorder(node*root){
	if(root == NULL){
		return;
	}

	inorder(root->left);
	cout<<root->data<<",";
	inorder(root->right);
}

bool search(node*root, int data){

	if(root == NULL){
		return false;
	}

	if(root->data == data){
		return true;
	}

	if(data <= root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}


node*deleteinBST(node*root, int data){
	if(root == NULL){
		return NULL;
	}

	else if(data < root->data){
		root->left = deleteinBST(root->left,data);
		return root;
	}

	else if(data == root->data){
		//found the node to delete 3 case
		//1.node with 0 children 
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		//2. Node with 1 children
		if(root->left != NULL && root->right == NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		if(root->right != NULL && root->left == NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		//3.Node having 2 children 
		node*replace = root->right;

		while(replace->left != NULL){
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deleteinBST(root->right,replace->data);
		return root;
	}

	else{
		root->right = deleteinBST(root->right,data);
		return root;
	}
}

bool isBST(node*root, int minV = INT_MIN, int maxV= INT_MAX){
	if(root == NULL){
		return true;
	}

	if(root->data >= minV && root->data<= maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

class LinkedList{

public:
	node*head;
	node*tail;
};

LinkedList flatten(node*root){
	LinkedList l;

	if(root == NULL){
		l.head = l.tail = NULL;
		return l;
	}

	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}

	//left node is not null
	if(root->left != NULL & root->right == NULL ){
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}

	//right is not null
	if(root->left == NULL && root->right != NULL){
		LinkedList rightLL = flatten(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}

	//both sides are not null
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);

	leftLL.tail->right = root;
	root->right = rightLL.head;
	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}


int main(){

	node*root = build();
	inorder(root);
	cout<<endl; 
	bfs(root);
	cout<<endl;

	// int s;
	// cin>>s;

	// // if(search(root,s)){
	// // 	cout<<"present";
	// // }
	// // else
	// // 	cout<<"Not present";
	// // cout<<endl;

	// root = deleteinBST(root,s);
	// inorder(root);
	// cout<<endl;
	// bfs(root);

	// if(isBST(root)){
	// 	cout<<"Yes"<<endl;
	// }
	// else{
	// 	cout<<"No"<<endl;
	// }

	LinkedList l = flatten(root); 
	node*temp = l.head;
	while(temp != NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	cout<<endl;




	return 0;
}













