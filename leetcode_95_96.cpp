#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //95
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n);
    }
    vector<TreeNode* > helper(int start, int end){
        if(start > end) return {nullptr};
        vector<TreeNode* > res;
        for(int i = start; i <= end; ++i){
            auto left = helper(start, i - 1);
            auto right = helper(i + 1, end);
            for(auto a: left){
                for(auto b : right){
                    TreeNode *node = new TreeNode(i);
                    node -> left = a;
                    node -> right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }

    //96
    //n = 2 的情况可由下面式子算出（这里的 dp[i] 表示当有i个数字能组成的 BST 的个数）：
    //dp[2] =  dp[0] * dp[1]　　　(1为根的情况，则左子树一定不存在，右子树可以有一个数字)
    //          + dp[1] * dp[0]　　  (2为根的情况，则左子树可以有一个数字，右子树一定不存在)
    //同理可写出 n = 3 的计算方法：
    //dp[3] =  dp[0] * dp[2]　　　(1为根的情况，则左子树一定不存在，右子树可以有两个数字)
    //          + dp[1] * dp[1]　　  (2为根的情况，则左右子树都可以各有一个数字)
    //          + dp[2] * dp[0]　　  (3为根的情况，则左子树可以有两个数字，右子树一定不存在)
    int numTrees(int n) {
        vector <int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                dp[i] = dp[i] + dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

};
/*
void print_tree(TreeNode* root){
    if(!root) return;
    cout << root -> val << endl;
    print_tree(root -> left);
    print_tree(root -> right);
}
*/

int main()
{
    int n;
    cout << "96: type in the n: ";
    cin >> n;
    Solution S;
    int ans = S.numTrees(n);
    cout << ans << endl;
    Solution S1;
    vector<TreeNode* > res = S1.generateTrees(n);
    for(int i = 0; i < res.size(); ++i){
        cout << res.at(i) << " ";
    }
    cout << endl;
    return 0;
}