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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while(curr && curr -> next){
            if(curr -> val == curr -> next -> val){
                curr -> next = curr -> next -> next;
            }
            else curr = curr -> next;
        }
        return head;
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
    ListNode * ans = S.deleteDuplicates(l);
    while(ans){
        cout << ans -> val << endl;
        ans = ans -> next;
    }
    return 0;
}