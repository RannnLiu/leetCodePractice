#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; --i){
            if(digits[i] == 9) digits[i] = 0;
            else{
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        if(digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
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
    vector <int> ans;
    ans = S.plusOne(list);
    for(int i = 0; i < ans.size(); ++i){
        cout << list.at(i) << " ";
    }
    cout << endl;
    return 0;
}