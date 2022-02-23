#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 0, n = nums.size();
        while(cur < n){
            if(nums[pre] == nums[cur]) ++cur;
            else nums[++pre] =nums[cur++];
        }
        return nums.empty() ? 0 : (pre + 1);
    }
};

int main()
{
    Solution S;
    int x[10] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> array(x, x+10);
    int resultlen = S.removeDuplicates(array);
    for(int i; i < resultlen; i++){
        cout << array[i] <<" ";
    }
    cout<<endl;
    cout<< resultlen <<endl;
    return 0;
}

