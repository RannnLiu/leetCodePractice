#include <iostream>
#include <vector>
using namespace std;

//- 先扫描第一行第一列，如果有0，则将各自的flag设置为true
//- 然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
//- 再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
//- 最后根据第一行第一列的flag来更新第一行第一列
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false;
        bool colZero = false;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 0) colZero = true;
        }
        for(int i = 0; i < n; ++i){
            if(matrix[0][i] == 0) rowZero = true;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(rowZero){
            for(int i = 0; i < n; ++i) 
                matrix[0][i] = 0;
        }
        if(colZero){
            for(int i = 0; i < m; ++i)
            matrix[i][0] = 0;
        }
    }
};

int main()
{
    vector <vector <int> > test;
    vector <int> v;
    int m, n;
    int temp;
    cout << "type in the m(row): ";
    cin >> m;
    cout <<"type in the n(column): ";
    cin >> n;
    test.clear();
    for(int i = 0; i < m; ++i){
        v.clear();
        for(int j = 0; j < n; ++j){
            cin >> temp;
            v.push_back(temp);
        }
        test.push_back(v);
    }
    Solution S;
    S.setZeroes(test);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << test[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}