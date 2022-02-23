#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val) nums[res++] = nums[i];
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
        list.insert(list.end(), temp);
    }while(getchar()!='\n');
    int val;
    cout << "type in the val: ";
    cin >> val;
    Solution S;
    int ans = S.removeElement(list, val);
    cout << ans << endl;
    return 0;
}
