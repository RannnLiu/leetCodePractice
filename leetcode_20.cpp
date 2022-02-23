#include<iostream>
#include<stack>
using namespace std;

//这里需要用一个栈，开始遍历输入字符串，如果当前字符为左半边括号时，
//则将其压入栈中，如果遇到右半边括号时，若此时栈为空，则直接返回 false，如不为空，
//则取出栈顶元素，若为对应的左半边括号，则继续循环，反之返回 false

class Solution {
public:
    bool isValid(string s) {
        stack<int> parentheses;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else{
                if(parentheses.empty()) return false;
                if(s[i] == ')' && parentheses.top() != '(') return false;
                if(s[i] == ']' && parentheses.top() != '[') return false;
                if(s[i] == '}' && parentheses.top() != '{') return false; 
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};

int main()
{
    char str[10000];
    cout << "type in the string: ";
    gets(str);
    cout << str << endl;
    Solution S;
    bool ans = S.isValid(str);
    cout << ans << endl;
    return 0;
}