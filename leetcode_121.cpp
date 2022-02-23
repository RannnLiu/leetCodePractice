#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = INT_MAX;
        for(int price : prices){
            buy = min(buy, price);
            res = max(res, price - buy);
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
        if(!temp) break;
        list.insert(list.end(), temp);
    }while(getchar() != '\n');
    Solution S;
    int ans = S.maxProfit(list);
    cout << ans << endl;
    return 0;
}