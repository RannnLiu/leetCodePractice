#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for(int i = 2; i < n; ++i){
            if(!prime[i]) continue;
            ++res;
            for(int j = 2; i * j < n; ++j){
                prime[i * j] = false;
            }
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
    int ans = S.countPrimes(n);
    cout << ans << endl;
    return 0;
}