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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while(head){
            ListNode *tmp = head -> next;
            curr = dummy;
            while(curr -> next && (curr -> next -> val <= head -> val)){
                curr = curr -> next;
            }
            head -> next = curr -> next;
            curr -> next = head;
            head = tmp;
        }
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
    ListNode *ans = S.insertionSortList(l);
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}