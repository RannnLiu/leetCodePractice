#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector <int> >& obstacleGrid) {
       if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
       int m = obstacleGrid.size(), n = obstacleGrid[0].size();
       vector<vector <long> > dp(m + 1, vector<long>(n + 1, 0));
       dp[0][1] = 1;
       for(int i = 1; i <= m; ++i){
           for(int j = 1; j <= n; ++j){
               if(obstacleGrid[i - 1][j - 1] != 0) continue;
               dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
           }
       }
       return dp[m][n];
    }
};


int main()
{
    vector<vector <int> > test;
    vector<int> v;
    int n, m, temp;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    for(int i = 0; i < n; ++i){
        v.clear();
        for(int j = 0; j < n; ++j){
            cin >> temp;
            v.push_back(temp);
        }
        test.push_back(v);
    }
    //print out the obstacleGrid:
    /*
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    */
    Solution S;
    int ans = S.uniquePathsWithObstacles(test);

    return 0;
}