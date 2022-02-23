#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.back() < target) return nums.size();
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};

int main()
{
    vector <int> list;
    int temp;
    do{
        cin >> temp;
        list.insert(list.end(), temp);
    }while(getchar()!='\n');
    int target;
    cout <<"type in the target: ";
    cin >> target;
    Solution S;
    int ans = S.searchInsert(list, target);
    cout << ans << endl;
    return 0;
}