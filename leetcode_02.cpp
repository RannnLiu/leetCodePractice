#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        int carry = 0;
        while(l1 || l2){
            int val1 = l1 ? l1 -> val : 0;
            int val2 = l2 ? l2 -> val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(carry) curr -> next = new ListNode(1);
        return dummy -> next;
    }
};

ListNode *build_list(ListNode *l, int value){
    ListNode *l_node = new ListNode();
    l_node -> val = value;
    l_node -> next = NULL;
    ListNode *curr = l;
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = l_node;
    return l;
}

int main()
{
    int value;
    cout << "l1 = ";
    cin >> value;
    ListNode *l1_node = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l1_node, value);
    }

    cout << "l2 = ";
    cin >> value;
    ListNode *l2_node = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l2_node, value);
    }

    Solution S;
    ListNode *ans = S.addTwoNumber(l1_node, l2_node);
    while(ans){
        cout << ans -> val <<endl;
        ans = ans -> next;
    }
    return 0;
}