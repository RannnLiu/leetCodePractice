#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, n = nums.size();
        for(i = n - 2; i >= 0; --i){
            if(nums[i + 1] > nums[i]){
                for(j = n - 1; j > i; --j){
                    if(nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
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
    Solution S;
    S.nextPermutation(list);
    for(int i = 0; i < list.size(); ++i){
        cout << list.at(i) << " ";
    }
    cout << endl;
    return 0;
}