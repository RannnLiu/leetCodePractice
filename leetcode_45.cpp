#include <iostream>
#include <vector>
using namespace std;

//using the "last" to keep track of the maximum distance that has been reached 
//by using the minimum steps "res",
//whereas "cur" is the maximum distance that can be reached by using "res + 1" steps.
//Thus, cur = max(i + A[i]), where 0 <= i <= last.

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int last = 0;
        int cur = 0;
        for(int i = 0; i < n - 1; ++i){
            cur = max(cur, i + nums[i]);
            if(i == last){
                last = cur;
                ++res;
                if(cur >= n - 1) break;
            }
        }
        return res;
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
    int ans = S.jump(list);
    cout << ans << endl;
    return 0;
}