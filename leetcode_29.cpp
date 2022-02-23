#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long m = labs(dividend); //返回绝对值
        long n = labs(divisor);
        long res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if(n == 1) return sign == 1 ? m : -m;
        while(m >= n){
            long t = n;
            long p = 1;
            while(m >= (t << 1)){
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        return sign == 1 ? res : -res;
    }
};

int main()
{
    int dividend, divisor;
    cin >> dividend;
    cin >> divisor;
    Solution S;
    int ans = S.divide(dividend, divisor);
    cout << ans << endl;
    return 0; 
}