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

node*create_tree(int *in, int *pre, int s, int e){

	static int i = 0;
	if(s > e){
		return NULL;
	}

	node*root = new node(pre[i]);
	int index = -1;
	for(int j =s;s<=e;j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = create_tree(in , pre, s, index-1);
	root->right = create_tree(in , pre, index+1, e);
	return root;
}

void printAtLevelK(node*root, int k){
	if(root == NULL || k < 0){
		return ;
	}
	if(k== 0){
		cout<<root->data<<" ";
		return ;
	}

	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
	return;
}


int printAtDistanceK(node*root, node* target, int k){

	if(root == NULL){
		return -1;
	}

	if(root == target){
		printAtLevelK(root, k);
	}

	int DL = printAtDistanceK(root->left,target, k);

	if(DL != -1){
		//2 case
		//ancestor itself or need to go in right subtree
		if(DL + 1 == k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->right,k-DL-2);
		}
		return DL + 1;
	}
	int DR = printAtDistanceK(root->right,target, k);

	if(DR != -1){
		//2 case
		//ancestor itself or need to go in right subtree
	 	if(DR + 1 == k){
			cout<<root->data<<" ";
		}
		else{
			printAtLevelK(root->right,k-DR-2);
		}
		return DR + 1;
	}
	//node was present in left
	return -1;
}

node*settarget(node*root, int da){

	if(root == NULL){
		return NULL;
	}
	if( root->data == da){
		return root;
	}
	root->left = settarget(root->left, da);
	root->right = settarget(root->right, da);
	return root;
}

int main(){

	int n;
	cin>>n;
	int pre[n];
	int in[n];

	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	node*root = create_tree(in , pre, 0,n-1);
	int t;
	cin>>t;
	while(t > 0){
		
		int da;
		cin>>da;
		node*target = settarget(root,da);

		int b;
		cin>>b;

		int ans = printAtDistanceK(root, target, b);
		cout<<ans<<endl;
		t--;
	}

	



	return 0;
}