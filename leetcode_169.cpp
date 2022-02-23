#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int cnt = 0;
        for(int num : nums){
            if(cnt == 0) {
                result = num;
                ++ cnt; 
            }
            else (num == result) ? ++cnt : --cnt;
        }
        return result;
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
    int ans = S.majorityElement(list);
    cout << ans << endl;
    return 0;
}