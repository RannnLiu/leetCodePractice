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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        // get the length of the list
        int n = 0;
        ListNode *curr = head;
        while(curr){
            ++n;
            curr = curr -> next;
        }
        k = k % n;
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i = 0; i < k; ++i){
            if(fast) fast = fast -> next;
        }
        if(!fast) return head;
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        fast -> next = head;
        fast = slow -> next;
        slow -> next = NULL;
        return fast;
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
    while(getchar()!='\n'){
        cin >> value;
        build_list(l, value);
    }
    cout << endl;
    int k;
    cout << "Enter a k: ";
    cin >> k;
    Solution S;
    ListNode* ans = S.rotateRight(l,k);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}