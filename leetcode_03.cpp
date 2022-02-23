#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = -1;
        int n = s.size();
        unordered_map <int, int> m;
        for(int i = 0; i < n; ++i){
            if(m.count(s[i]) && m[s[i]] > left){
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

int main()
{
    string str;
    getline(cin, str);
    Solution S;
    int ans = S.lengthOfLongestSubstring(str);
    cout << str << endl;
    cout << ans << endl;
    return 0;
}