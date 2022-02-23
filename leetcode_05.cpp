#include <iostream>
#include <string>
#include <vector>
using namespace std;

//dp[i, j] = 1                      if i == j

//           = s[i] == s[j]         if j = i + 1

//           = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1     

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size();
        vector<vector <int> > dp(n, vector <int> (n, 0));
        int left = 0;
        int len = 1;
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j){
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if(dp[j][i] && len < i - j + 1){
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);
    }
};

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;
    Solution S;
    string ans = S.longestPalindrome(str);
    cout << ans << endl;
    return 0;
}