#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        
        if(right == nums.size() || nums[right] != target) return res;
        res[0] = right;
        right = nums.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = right - 1;
        return res;
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
    cout << "type in the target: ";
    cin >> target;
    Solution S;
    vector <int> ans;
    ans = S.searchRange(list, target);
    for (int i = 0; i < ans.size(); ++i){
        cout << list.at(i) << " ";
    }
    cout << endl;
    return 0;
}