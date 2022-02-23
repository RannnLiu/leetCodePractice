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
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = head;
        //找到中间的点断开
        while(fast && fast -> next){
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        pre -> next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr -> next;
        }
        if(l1) curr -> next = l1;
        if(l2) curr -> next = l2;
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
    ListNode *l = new ListNode(value);
    while(getchar() != '\n'){
        cin >> value;
        build_list(l, value);
    }
    Solution S;
    ListNode *ans = S.sortList(l);
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}

