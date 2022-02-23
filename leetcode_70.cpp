#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};

int main()
{
    int n;
    cout << "type in n: " << endl;
    cin >> n;
    Solution S;
    int ans = S.climbStairs(n);
    cout << ans << endl;
    return 0;
}