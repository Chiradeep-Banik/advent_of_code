#include <bits/stdc++.h>
#define lli long long int

using namespace std;

vector<string> separate(string s,char separator){
    vector<string> result(0);
    if(s.find(separator) == s.npos) return result;
    stringstream ss(s);
    while (ss.good()){
        string sub;
        getline(ss, sub, separator);
        if(sub != ""){
            if(sub[0] == ' '){
                sub = sub.substr(1,sub.size());
            }
            if(sub[sub.size()-1] == ' '){
                sub = sub.substr(0,sub.size()-1);
            }
            result.push_back(sub);
        }
    }    
    return result;
}


lli part1(vector<string> cards){
    lli res =0;
    for(string card: cards){
        vector<string> v = separate(card,':');

        string nums = v[1];
        cout << nums << endl;
        
        vector<string> nums_sp = separate(nums,'|');

        vector<string> win_nums = separate(nums_sp[0],' ');
        set<int> win_nums_int;
        for(string s:win_nums){
            win_nums_int.insert(stoi(s));
            cout << s << endl;
        }
        vector<string> my_nums = separate(nums_sp[1],' ');
        
        lli curScore = 0;
        for(string m_num:my_nums){
            int curNum = stoi(m_num);
            if(win_nums_int.find(curNum) != win_nums_int.end()){
                cout << curNum << endl;
                if(curScore == 0){
                    curScore = 1;
                }else{
                    curScore *= 2;
                }
            }
            cout <<"CurScore : " << curScore << endl;
        }
        res+=curScore;
        // break;
    }
    return res;
}

lli part2(vector<string> cards){
    vector<lli> final_count(cards.size()+1,1);
    final_count[0] = 0;
    int curCard = 1;
    for(string card: cards){
        vector<string> v = separate(card,':');

        string nums = v[1];
        // cout << nums << endl;
        
        vector<string> nums_sp = separate(nums,'|');

        vector<string> win_nums = separate(nums_sp[0],' ');
        set<int> win_nums_int;
        for(string s:win_nums){
            win_nums_int.insert(stoi(s));
            // cout << s << endl;
        }
        vector<string> my_nums = separate(nums_sp[1],' ');
        
        lli curScore = 0;
        for(string m_num:my_nums){
            int curNum = stoi(m_num);
            if(win_nums_int.find(curNum) != win_nums_int.end()){
                curScore++;
            }
        }
        for(int i=curCard+1;i<curCard+1+curScore;i++){
            final_count[i] += final_count[curCard];
        }
        curCard++;
        // break;
    }
    lli res =0;

    for(int i=1;i<final_count.size();i++){
        res+=final_count[i];
        // cout << final_count[i] << " ";
    }
    // cout << endl;
    return res;
}

int main(){
	string line;
	ifstream myfile("4_input.txt");
	vector<string> inputs;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inputs.push_back(line);
		}
		myfile.close();
	}
	else cout << "Unable to open file";

    cout << part1(inputs) << endl;
    cout << part2(inputs) << endl;

	return 0;
}
