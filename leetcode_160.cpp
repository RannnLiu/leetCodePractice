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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = getLength(headA), lenB = getLength(headB);
        if(lenA < lenB){
            for(int i = 0; i < lenB - lenA; ++i) headB = headB -> next;
        }
        else {
            for(int i = 0; i < lenA - lenB; ++i) headA = headA -> next;
        }
        while(headA && headB && headA != headB){
            headA = headA -> next;
            headB = headB -> next;
        }
        return (headA && headB) ? headA : NULL;
    }
    int getLength(ListNode *head){
        int cnt = 0;
        while(head){
            ++ cnt;
            head = head -> next;
        }
        return cnt;
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
    ListNode *l1 = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l1, value);
    }
    cout << "l2 = ";
    cin >> value;
    ListNode *l2 = new ListNode(value);
    while(getchar()!='\n'){
        cin >> value;
        build_list(l2, value);
    }
    Solution S;
    ListNode *ans = S.getIntersectionNode(l1, l2);
    while(ans){
        cout << ans -> val <<" ";
        ans = ans -> next;
    }
    cout << endl;
    return 0;
}
