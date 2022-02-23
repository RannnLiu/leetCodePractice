#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return ""; //n要大于0
        string res = "1"; //初始化结果为n = 1, res = 1
        while( --n ){ 
            string cur = ""; //初始化cur为空
            for(int i = 0; i < res.size(); ++i){ //遍历每一位
                int cnt = 1; 
                while(i + 1 < res.size() && res[i] == res[i + 1]){ //
                    ++cnt; 
                    ++i; 
                }
                cur = cur + to_string(cnt) + res[i]; //将整数cnt转换为字符串表示形式
            }
            res = cur;
        }
        return res;
    }
};

int main()
{
    int n;
    cout << "type in the n: ";
    cin >> n;
    Solution S;
    string ans = S.countAndSay(n);
    cout << ans << endl;
    return 0;
}