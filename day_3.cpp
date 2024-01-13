#include "bits/stdc++.h"
#define ll long long
#define print(var) cout<<#var<<"="<<var<<endl
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define rev(v)  sort(v.begin(),v.end())         // reverse
#define mx(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mn(v)  *min_element(v.begin(),v.end())     // find min element in vector

using namespace std;

int MOD=1e9+7;

int solve(vector<string> inputs){
    int sum = 0;
	int n = inputs.size();
	int m = inputs[0].size();
	vector<vector<bool>> charMap(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
		// cout << inputs[i] << endl;
		for(int j=0;j<m;j++){
			if(!(inputs[i][j] >= '0' && inputs[i][j] <= '9')){
				if(inputs[i][j] != '.'){
					charMap[i][j] = true;
				}
			}
		}
    }
	map<int,pair<int,pair<int,int>>> nums; 
	for(int i=0;i<n;i++){
		string s = inputs[i];
		int l=0,r=0;
		string curNum = ""; 
		while(r<m){
			if((s[r] >= '0' && s[r] <= '9')){
				curNum += s[r];
				r++;
			}else{
				if(curNum == ""){
					l++;
					r++;
				}else{
					nums[stoi(curNum)] = {i,{l,r-1}};
					curNum="";
					l=r;
				}
			}
		}
	}
	for(auto p:nums){
		int num = p.first;
		int row = p.second.first;
		int cl = p.second.second.first;
		int cr = p.second.second.second;
		// print(num);
		// print(row);
		// print(cl);
		// print(cr);
		// cout << endl;
		bool canAdd = false;
		for(int i=cl;i<=cr;i++){
			if(row-1 >= 0){
				if(charMap[row-1][i] == true){
					canAdd = true;
				}
			}
			if(row+1 < n){
				if(charMap[row+1][i] == true){
					canAdd = true;
				}
			}

		}
		// if(!canAdd){

		// }
		if(cr+1 < m){
			if(charMap[row][cr+1] == true){
				canAdd = true;
			}
			if(row+1 < n){
				if(charMap[row+1][cr+1] == true){
					canAdd = true;
				}
			}
			if(row-1 >= 0){
				if(charMap[row-1][cr+1] == true){
					canAdd = true;
				}
			}
		}
		if(cl-1 >= 0){
			if(charMap[row][cl-1] == true){
				canAdd = true;
			}
			if(row+1 < n){
				if(charMap[row+1][cl-1] == true){
					canAdd = true;
				}
			}
			if(row-1 >= 0){
				if(charMap[row-1][cl-1] == true){
					canAdd = true;
				}
			}
		}
		// cout << "canAdd: " << canAdd << endl;
		if(canAdd == true){
			// cout << "num : " << num << endl;
			sum += num;
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << charMap[i][j] << " ";
	// 	}cout << endl;
	// }
    return sum;
}

int main()
{
	string line;
	// ifstream myfile("3_input.txt");
	ifstream myfile("3_test.txt");
	vector<string> inputs;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inputs.push_back(line);
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";

	cout << "Sum : " << solve(inputs) << endl;
	return 0;
}

