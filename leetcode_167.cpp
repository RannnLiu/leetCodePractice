#include <iostream>
#include <vector>
using namespace std;

//O(nlgn)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i){
            int t = target - numbers[i];
            int left = i + 1;
            int right = numbers.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
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
    cin >> target;
    Solution S;
    vector <int> ans = S.twoSum(list, target);
    for(int i = 0; i < ans.size(); ++i){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    return 0;
}