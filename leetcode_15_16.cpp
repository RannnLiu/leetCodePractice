#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    //15
    vector<vector <int> > threeSum(vector<int>& nums) {
        vector<vector <int> > res;
        sort(nums.begin(), nums.end());
        if(nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for(int k = 0; k < (int)nums.size() - 2; ++k){
            if(nums[k] > 0) break;
            if(k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1;
            int j = (int)nums.size() - 1;
            while(i < j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    ++i;
                    --j;
                }
                else if(nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }

    //16
    int threeSumClosest(vector<int>& nums, int target) { //其中三个数的和最接近target 返回三个数的和
        int closest = nums[0] + nums[1] + nums[2]; //初始化closest为前三个数的和
        int diff = abs(closest - target); //求closest和target的差
        sort(nums.begin(), nums.end()); //nums排序 从小到大
        for(int i = 0; i < nums.size() - 2; ++i){ //i从0到倒数第二个
            int left = i + 1; //左边从i后面一个开始
            int right = nums.size() - 1; //右边从倒数第一个开始
            while(left < right){ //left在right的前面
                int sum = nums[i] + nums[left] + nums[right]; //i和left和right的和
                int newDiff = abs(sum - target); //重新计算和与target的差
                if(diff > newDiff){ //如果新的差更小-新的和更接近target
                    diff = newDiff; //更新差
                    closest = sum; //更新closest是新的和
                }
                if(sum < target) ++left; //和比target小 left后移一个 找大的
                else --right; //和比target大 right往前移一个 找小的
            }
        }
        return closest; //返回closest
    }
};

int main()
{
    /*
    //15main
    vector <int> list;
    int temp;
    do{
        cin >> temp;
        list.insert(list.end(), temp);
    }while(getchar()!='\n');
    Solution S;
    vector<vector <int> > ans = S.threeSum(list);
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl; 
    }
    cout << endl;
    */
    //16main
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
    int ans = S.threeSumClosest(list, target);
    cout << ans << endl;
    return 0;
}