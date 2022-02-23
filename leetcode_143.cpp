#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。

2. 将第二个链翻转。

3. 将第二个链表的元素间隔地插入第一个链表中。
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *mid = slow -> next;
        slow -> next = NULL;
        ListNode *last = mid;
        ListNode *pre = NULL;
        
        while(last){
            ListNode *next = last -> next;
            last -> next = pre;
            pre = last;
            last= next;
        }
        
        while(head && pre){
            ListNode *next = head -> next;
            head -> next = pre;
            pre = pre -> next;
            head -> next -> next = next;
            head = next;
        }
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
    S.reorderList(l);
    while(l){
        cout << l -> val <<" ";
        l = l -> next;
    }
    cout << endl;
    return 0;
}
