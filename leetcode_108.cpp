#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
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
    //make a bst and return in level order
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur -> left = helper(nums, left, mid - 1);
        cur -> right = helper(nums, mid + 1, right);
        return cur;
    } 
};

//not print in level order
void print_tree(TreeNode* root){
    if(!root) {
        cout << "NULL ";
        return;
    }
    cout << root -> val << " ";
    print_tree(root -> left);
    print_tree(root -> right);
}

int main()
{
    vector <int> list;
    int temp;
    do{
        cin >> temp;
        list.insert(list.end(), temp);
    }while(getchar()!='\n');
    Solution S;
    TreeNode *ans = new TreeNode();
    ans = S.sortedArrayToBST(list);
    print_tree(ans);
    cout << endl;
    return 0;
}