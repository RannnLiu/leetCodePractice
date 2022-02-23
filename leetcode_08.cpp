#include<iostream>
#include<string>
#include<math.h>
#include<string>
using namespace std;


class Solution{
public:
    int myAtoi(string str){
        if (str.empty()) return 0;//the string is null return 0
        int sign = 1, base = 0, i = 0, n = str.size();//n is the length of the string
        while (i < n && str[i] == ' ') ++i; //skip the whitespace move to the next
        if (i < n && (str[i] == '+'||str[i] == '-')){
            sign = (str[i++] == '+') ? 1: -1;//whether is positive or negative
        }
        while (i < n && str[i] >= '0' && str[i] <= '9'){
            if(base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};

int main()
{
    string str;
    getline(cin, str);
    Solution S;
    int ans = S.myAtoi(str);
    cout << ans << endl;
    return 0;
}