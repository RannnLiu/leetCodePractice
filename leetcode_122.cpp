#include <iostream>
#include <vector>
using namespace std;

//只需要从第二天开始，如果当前价格比之前价格高，则把差值加入利润中，
//因为我们可以昨天买入，今日卖出，若明日价更高的话，还可以今日买入，明日再抛出。
//以此类推，遍历完整个数组后即可求得最大利润。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        for(int i = 0; i < n - 1; ++i){
            if(prices[i] < prices[i + 1]){
                res += prices[i + 1] - prices[i];
            }
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
    }while(getchar()!='\n');
    Solution S;
    int ans = S.maxProfit(list);
    cout << ans << endl;
    return 0;
}