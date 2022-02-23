#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //12 integer to roman
    string intToRoman(int num) {
        string res = "";
        
        char roman1[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; 
        vector <char> roman;
        roman.insert(roman.begin(), roman1, roman1 + 8);
        
        int value1[7] = {1000, 500, 100, 50, 10, 5, 1}; 
        vector <int> value;
        value.insert(value.begin(), value1, value1 + 8);

        for(int n = 0; n < 7; n += 2){
            int x = num / value[n];
            if(x < 4){
                for(int i = 1; i <= x; ++i) res += roman[n];
            }else if(x == 4){
                res = res + roman[n] + roman[n - 1];
            }else if(x > 4 && x < 9){
                res += roman[n - 1];
                for(int i = 6; i <= x; ++i) res += roman[n];
            }else if(x == 9){
                res = res + roman[n] + roman[n - 2];
            }
            num = num % value[n];
        }
        return res;
    }

    //13 Roman to Integer
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for(int i = 0; i < s.size(); ++i){
            int val = m[s[i]];
            if(i == s.size() - 1 || m[s[i + 1]] <= m[s[i]]) res += val;
            else res -= val;
        }
        return res;
    }
};

int main()
{
    string str;
    int num;
    cout <<"type in the num: ";
    cin >> num;
    Solution S;
    str = S.intToRoman(num);
    cout << str << endl;
    int ans = S.romanToInt(str);
    cout << ans << endl;
    return 0;
}