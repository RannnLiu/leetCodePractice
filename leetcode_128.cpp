#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set <int> s(nums.begin(), nums.end());
        for(int val : nums){
            if(!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1;
            int next = val + 1;
            while(s.count(pre)) s.erase(pre--);
            while(s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

int main()
{
    vector <int> nums;
    int temp;
    do{
        cin >> temp;
        nums.insert(nums.end(), temp);
    }while(getchar() != '\n');
    
    Solution S;
    int ans = S.longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}