#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int curSum = 0;
        for(int num : nums){
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};

int main()
{
    vector<int> list;
    int temp;

    do{
        cin >> temp;
        if(!temp) break;
        list.insert(list.end(),temp);
    }while(getchar()!='\n');

    for(int i = 0; i < list.size(); i++){
        cout << list.at(i) << " ";
    }
    cout << endl;

    Solution S;
    int ans = S.maxSubArray(list);
    cout << ans << endl;
    return 0;
}