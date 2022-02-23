#include<iostream>
#include<stdio.h>
#include<math.h>
//#define INT_MAX pow(2,31)-1

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        return reverse(x) == x;
    }
    int reverse(int x) {
        int res = 0;
        while (x != 0){
            if(res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    int number;
    cout << "Enter a number: " <<endl;
    cin >> number;
    Solution S;
    int result;
    result = S.isPalindrome(number);
    if(result) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}