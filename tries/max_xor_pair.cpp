#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node{
public:
	node* left;
	node* right;
	node(){
		left = NULL;
		right = NULL;
	}
};

void insert(ll n,node* head){
	
	node*temp = head;
	for(ll i = 31; i >= 0;i--){
		ll bit = (n>>i)&1;
		if(bit == 0){
			if(temp->left == NULL){
				temp->left = new node();
			}
			temp = temp->left;
		}
		else{
			if(temp->right == NULL){
				temp->right = new node();
			}
			temp = temp->right;
		}
	}
}

ll max_xor_helper(node* root, ll *arr, ll n,ll k){
		
	ll max_xor = INT_MIN;
	node *curr = root;
	ll value = k;
	ll curr_xor = 0;
	for(ll j = 31; j >= 0; j--) {
		ll b = (value >> j) & 1;
		if(b == 0) {
			if(curr->right != NULL) {
				curr_xor += (int)pow(2, j);
				curr = curr->right;
			} else {
				curr = curr->left;
			}
		} else {
			if(curr->left != NULL) {
				curr_xor += (int)pow(2, j);
				curr = curr->left;
			} else {
				curr = curr->right;
			}
		}
	}
	if(curr_xor > max_xor)
		max_xor = curr_xor;
	return max_xor;
}



int main(){

	ll n;
	cin>>n;
	ll input[n];
	ll pre = 0;
	node* head = new node();
	for(int i= 0;i<n;i++){
		cin>>input[i];
	}
	insert(0,head);
	ll result = INT_MIN;
	for(ll i = 0;i<n;i++){
		pre = pre^input[i];
		insert(pre,head);
		ll x = max_xor_helper(head,input,n,pre);
		result = max(x,result);
	}
	cout<<result<<endl;	
	return 0;
}