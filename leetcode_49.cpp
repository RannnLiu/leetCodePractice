#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector <string> > groupAnagrams(vector<string>& strs) {
        vector<vector <string> > res;
        unordered_map<string, int> m;
        for(string str: strs){
            string t = str;
            sort(t.begin(), t.end());
            if(!m.count(t)){
                m[t] = res.size();
                res.push_back({});
            }
            res[m[t]].push_back(str);
        }
        return res;
    }
};

int main()
{
    vector <string> strs;
    string str;
    do{
        cin >> str;
        strs.insert(strs.end(), str);
    }while(getchar()!='\n');
    vector<vector <string> > ans;
    Solution S;
    ans = S.groupAnagrams(strs);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); j++){
        cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    /*
    for(int i = 0; i < strs.size(); ++i){
        cout << strs.at(i) << " ";
    }
    */
    cout << endl;
    return 0;
}