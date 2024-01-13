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

map<string,int> lim = {
    {"red",12},
    {"green",13},
    {"blue",14}
};

int solve(vector<string> inputs){
    int sum = 0;
    for(int i=0;i<inputs.size();i++){
        cout << "i : "<< i << endl;
        string input = inputs[i] + ";";
        vector<string> games;
        int l=0,r=0;
        bool colon = false;
        while(r < input.size() && l < input.size()){
            // cout << "l : " << l << " r : " << r << input << endl;
            if(r < input.size() && input[r] == ':'){
                colon = true;
                l+=2;
                r+=2;
            }
            if(!colon){
                l++;
                r++;
                continue;
            }
            if(r < input.size() && input[r] != ';'){
                r++;
            }else{
                string cur = input.substr(l,r-l);
                // print(cur);
                games.push_back(cur);
                r+=2;
                l=r;
            }
        }
        
        bool canAdd = true;
        map<string,int> mini={
            {"red",INT_MIN},
            {"green",INT_MIN},
            {"blue",INT_MIN},            
        };
        // cout << "i : " << i << endl;
        for(string s:games){
            stringstream ss(s);
            vector<string> v;
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            for(int i=0;i<v.size();i++) {
                if(v[i][0] == ' '){
                    v[i] = v[i].substr(1);
                }
                if(v[i][v[i].size()-1] == ' '){
                    v[i] = v[i].substr(0,v[i].size()-1);
                }
            }   
            for(int i=0;i<v.size();i++){
                stringstream ss(v[i]);
                vector<string> val;
                while(ss.good()) {
                    string st;
                    getline(ss,st,' ');
                    val.push_back(st);
                }
                // if(lim[val[1]] < stoi(val[0])){
                //     cout << "val 1 : " << val[1] << endl;
                //     cout << "val 0 : " << stoi(val[0]) << endl;
                //     canAdd = false;
                //     break;
                // }
                mini[val[1]] = max(mini[val[1]],stoi(val[0]));
            }       
            // if(!canAdd){
            //     break;
            // }
        }
        // if(canAdd){
        //     sum += (i+1);
        // }
        int pro = 1;
        for(pair<string,int> p:mini){
            pro = pro * p.second;
        }
        sum += pro;
        cout << "game : " << i+1 << endl;
        for(string s:games){
            cout << s << " ";
        }cout << endl;
        cout << "sum : " << sum << endl;
    }
    return sum;
}

int main()
{
	string line;
	ifstream myfile("2_input.txt");
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

