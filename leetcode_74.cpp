#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector <int> >& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int left = 0;
        int right = matrix.size();
        while(left < right){
            int mid = (left + right) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) left = mid + 1;
            else right = mid;
        }
        
        int tmp = (right > 0) ? (right - 1) : right;
        left = 0;
        right = matrix[tmp].size();
        while(left < right){
            int mid = (left + right) / 2;
            if(matrix[tmp][mid] == target) return true;
            if(matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};

int main()
{
    vector<vector <int> > matrix;
    vector<int> v;
    int n, m, temp;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    for(int i = 0; i < m; ++i){
        v.clear();
        for(int j = 0; j < n; ++j){
            cin >> temp;
            v.push_back(temp);
        }
        matrix.push_back(v);
    }
    int target;
    cout << "type in the target: ";
    cin >> target;
    Solution S;
    bool ans = S.searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}