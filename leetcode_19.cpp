#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *curr = dummy;
        ListNode *pre = dummy;
        while(n--){
            curr = curr -> next;
        }
        while(curr && curr -> next){
            pre = pre -> next;
            curr = curr -> next;
        }
        pre -> next = pre -> next -> next;
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
    cout << "l = ";
    cin >> value;
    ListNode *l_node = new ListNode(value);
    while(getchar() != '\n'){
        cin >> value;
        build_list(l_node, value);
    }
    cout << endl;
    int n;
    cout << "need delete nth node from the end of list: ";
    cin >> n;
    Solution S;
    ListNode *ans = S.removeNthFromEnd(l_node, n);
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}