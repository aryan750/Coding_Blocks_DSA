#include<bits/stdc++.h>
using namespace std;


string find_window(string s, string p){

	int SL = s.length();
	int PL = p.length();

	if(PL > SL){
		return "None";
	}

	int FS[256] = {0};
	int FP[256] = {0};

	int count = 0;
	int min_len = INT_MAX;
	int start = 0;
	int start_idx = -1;

	for(int i = 0;i<PL;i++){
		char ch = p[i];
		FP[ch] ++;
	}

	//3.sliding window(Expansion & contraction )

	for(int i = 0;i<SL;i++){

		char ch = s[i];
		FS[ch]++;

		//Maintian the count of character
		if(FP[ch] != 0 && FS[ch] <= FP[ch]){
			count++;
		}

		//if all the characters match
		if(count == PL){

			char temp =s[start];
			//not present or it is present but its freq is higher than required
			//loop to remove all un-wanted characters
			while(FP[temp] == 0 || FS[temp] > FP[temp] ){

				FS[temp]--;
				start ++;
				temp = s[start];
			}

			int window_len = i-start+1;
			//window size
			if(window_len < min_len){
				min_len = window_len;
				start_idx = start;
			}
		}
	}
	if(start_idx == -1){
		return "None";
	}
	string ans = s.substr(start_idx,min_len);
	return ans;
}



int main(){

	string s = "hllloeaeo World";
	string p = "eelo";

	cout<<find_window(s,p)<<endl;

	return 0;
}