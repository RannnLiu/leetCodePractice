#include <iostream>
#include <iomanip>
using namespace std;

//iteration
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double half = myPow(x, n / 2);
        if(n % 2 == 0) return half * half;
        if(n > 0) return half * half * x;
        return half  * half / x;
    }
};

int main()
{
    double x;
    int n;
    cout << "type in the x = ";
    cin >> x;
    cout <<"type in the n = ";
    cin >> n;
    Solution S;
    double ans = S.myPow(x, n);
    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}