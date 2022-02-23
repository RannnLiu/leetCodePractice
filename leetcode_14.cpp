#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = "";
        for(int j = 0; j < strs[0].size(); ++j){
            char c = strs[0][j];
            for(int i = 1; i < strs.size(); ++i){
                if(j >= strs[i].size() || strs[i][j] != c){
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};

int main()
{
    vector <string> strs = {"flower", "flow", "flight"};
    Solution S;
    string ans = S.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}