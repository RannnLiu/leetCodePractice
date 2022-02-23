#include <iostream>
#include <vector>
using namespace std;

//其中 dp[i] 表示达到i位置时剩余的跳力，若到达某个位置时跳力为负了，说明无法到达该位置
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;
    }
};

int main()
{
    vector <int> list;
    int temp;
    do{
        cin >> temp;
        if(!temp) break;
        list.insert(list.end(), temp);
    }while(getchar()!='\n');
    Solution S;
    bool ans = S.canJump(list);
    cout << ans << endl;
    return 0;
}