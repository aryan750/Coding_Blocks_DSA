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


node* buildTree(){
	int d;
	cin>>d;

	if(d == -1){
		return NULL;
	}

	node*root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}


//Root -- Left -- Right
void print_Preorder(node*root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	print_Preorder(root->left);
	print_Preorder(root->right);
}

//Left -- Root -- Right
void print_Inorder(node*root){
	if(root == NULL){
		return ;
	}

	print_Inorder(root->left);
	cout<<root->data<<" ";
	print_Inorder(root->right);
}

void print_Postorder(node*root){
	if(root == NULL){
		return ;
	}

	print_Postorder(root->left);
	print_Postorder(root->right);
	cout<<root->data<<" ";
}


int height(node*root){
	if(root == NULL){
		return 0;
	}
	int ls = height(root->left);
	int rs = height(root->right);
	return max(ls,rs)+1;
}

// void print_kth_level(node*root , int k){
// 	if(root == NULL){
// 		return ;
// 	}
// 	if(k == 1){
// 		cout<<root->data<<" ";
// 		return ;
// 	}

// 	print_kth_level(root->left, k-1);
// 	print_kth_level(root->right, k-1);
// 	return ;
// }

//level order print--O(n^2)
// void print_all_levels(node*root){
// 	int h = height(root);

// 	for(int i =1;i<=h;i++){
// 		print_kth_level(root, i);
// 		cout<<endl;
// 	}
// 	return ;
// }


//BFS-1 -- O(n)
void bfs(node*root){
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* f = q.front();
		cout<<f->data<<" ";
		q.pop();

		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	return ;
}

//BFS-2 
//using NULL to change the line 
void bfs2(node*root){
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
			cout<<f->data<<" ";
			q.pop();

			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}
		}
	}
	return ;
}

int count(node*root){
	if(root == NULL){
		return 0;
	}
	return 1+count(root->left)+count(root->right);
}

int sum(node*root){
	if(root == NULL){
		return 0 ;
	}

	return root->data + sum(root->left) + sum(root->right);
}
 //compl: O(n^2)
int diameter(node*root){
	if(root == NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1+h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1,max(op2,op3));

}

//finding diameter more efficient
class Pair{
public:
	int height;
	int diameter;
};

Pair fastDiameter(node*root){
	Pair p;
	if(root == NULL){
		p.diameter = p.height = 0;
		return p;
	}

	//Otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height,right.height);
	p.diameter = max(left.height + right.height,max(left.diameter,right.diameter));
	return p;
}

int replaceSum(node*root){
	if(root == NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}

	//recursive
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;
	return temp + root->data;
}

class HBPair{
public:
	int height;
	bool balance;
};

HBPair isheightBalance(node*root){
	HBPair p;
	if(root == NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}

	//rec case
	HBPair left = isheightBalance(root->left);
	HBPair right = isheightBalance(root->right);

	// if(abs(left.height - right.height) <= 1 && left.heigh)
	p.height = max(left.height,right.height) + 1;

	if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
		p.balance = true;
	}
	else{
		p.balance = false;
	}
	return p;
}

node* buildTreeFromArray(int *a, int s , int e){
	if(s>e){
		return NULL;
	}

	//rec case
	int mid = (s+e)/2;
	node*root = new node(a[mid]);
	root->left = buildTreeFromArray(a,s,mid-1);
	root->right = buildTreeFromArray(a,mid+1,e);

	return root;
}

node* createTreeFromTrav(int *in , int *pre , int s, int e){
	static int i =0;
	if(s>e){
		return NULL;
	}

	//rec case
	node*root = new node(pre[i]);

	int index = -1;
	for(int j = s;s<=e;j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}

	i++;
	root->left = createTreeFromTrav(in,pre,s,index-1);
	root->right = createTreeFromTrav(in,pre,index+1,e);
	return root;
}

void print_right_view(node*root, int curr_level, int &max_level){
	if(root == NULL){
		return ;
	}

	if(max_level < curr_level){
		//discoverred a new level
		cout<<root->data<<" ";
		max_level = curr_level;
	}

	//right
	print_right_view(root->right, curr_level+1, max_level);
	//left 
	print_right_view(root->left,curr_level+1, max_level);
}

void print_kth_level(node*root , int k){
	if(root == NULL || k < 0){
		return ;
	}
	if(k == 0){
		cout<<root->data<<" ";
		return ;
	}

	print_kth_level(root->left, k-1);
	print_kth_level(root->right, k-1);
	return ;
}


int printAtDistanceK(node*root ,node*target, int k){

	//base case
	if(root == NULL){
		return -1;
	}

	//reach at the target node
	if(root == target){
		print_kth_level(root,k);
		return 0;
	}

	//next step - ancestor
	int DL = printAtDistanceK(root->left,target,k);

	if(DL != -1){

		//there are 2 cases
		//ancestor itself or you need to go to right subtree
		if(DL+1 == k){
			cout<<root->data<<" ";
		}
		else{
			print_kth_level(root->left,k-2-DL);
		}
		return 1+DL;
	}

	int DR = printAtDistanceK(root->right,target,k);

	if(DR != -1){

		//there are 2 cases
		//ancestor itself or you need to go to left subtree
		if(DR+1 == k){
			cout<<root->data<<" ";
		}
		else{
			print_kth_level(root->right,k-2-DR);
		}
		return 1+DR;
	}
	//node was not present in left
	return -1;
}


node* lca(node*root, int a, int b){

	//base case
	if(root == NULL){
		return NULL;
	}

	if(root->data == a || root->data == b){
		return root;
	}

	//search in left and right subtree	
	node*leftans = lca(root->left,a,b);
	node*rightans = lca(root->right,a,b);

	if(leftans != NULL && rightans != NULL){
		return root;
	}

	if(leftans != NULL){
		return leftans;
	}
	return rightans;

}

class Pairrr{
public:
	int branchSum;
	int maxSum;

	Pairrr(){
		branchSum = 0;
		maxSum = 0;
	}
};

Pairrr maxSumPath(node*root){

	Pairrr p;

	if(root == NULL){
		return p;
	}

	Pairrr left = maxSumPath(root->left);
	Pairrr right = maxSumPath(root->right);

	//construct two values 

	int pp1 = root->data;
	int pp2 = root->data + left.branchSum;
	int pp3 = root->data + right.branchSum;
	int pp4 = root->data + left.branchSum + rightSum;

	int current_ans_through_root = max(pp1,max(pp2,max(pp3,pp4)));

	p.branchSum = max(left.branchSum,max(right.branchSum,0)) + root->data;
	p.maxSum = max(left.maxSum,max(right.maxSum,current_ans_through_root));
	return p;
} 

//findign the level of a given node from the root node/nay given node
int search(node*root, int key, int level){

	if(root == NULL){
		return -1;
	}

	if(root->data == key){
		return level;
	}

	int left = search(root->left,key,level+1);
	if(left != -1){
		return left;
	}
	return search(root->right,key,level+1);
}

//function to find distance btw 2 nodes
int findDistance(node*root, int a, int b){

	node*lca_node = lca(root,a,b);

	int l1=  search(lca_node,a);
	int l2 = search(lca_node,b);
	return l1+l2;
}


int main()
{

	// node*root  =  buildTree();
	// // print_Preorder(root);
	// // cout<<endl;
	// // print_Inorder(root);
	// // cout<<endl;
	// // print_Postorder(root);
	// // cout<<endl;
	// // cout<<height(root)<<endl;
	// // print_kth_level(root, 3);
	// // print_all_levels(root);
	// // bfs2(root); 
	// // int k = count(root);
	// // cout<<k<<endl;
	// // int p = sum(root);
	// // cout<<p<<endl;
	// // print_all_levels(root);
	// // Pair p = fastDiameter(root);
	// // cout<<p.height<<endl;
	// // cout<<p.diameter<<endl;

	// // bfs2(root);
	// // replaceSum(root);
	// // bfs2(root);

	// if(isheightBalance(root).balance){
	// 	cout<<"Balanced"<<endl;
	// }
	// else{
	// 	cout<<"Not a Balanced tree"<<endl;
	// }
	
	// int a[] = {1,2,3,4,5,6,7};
	// int  n = 7;
	// node*root =  buildTreeFromArray(a,0,n-1);
	// bfs2(root);

	// int in[] = {3,2,8,4,1,6,7,5};
	// int pre[] = {1,2,3,4,8,5,6,7};
	// int n = sizeof(in)/sizeof(int);

	// node*root = createTreeFromTrav(in, pre, 0 ,n-1);
	// // bfs2(root);
	// node*root = buildTree();
	// bfs2(root);
	// // cout<<root<<endl;
	// int max_level = -1;
	// print_right_view(root, 0, max_level); 

	node*root = buildTree();

	node*target = root->left->left;

	bfs2(root);

	printAtDistanceK(root,target,2);

	return 0;
}