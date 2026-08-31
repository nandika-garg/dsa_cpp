/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ptr=head;
        ListNode* beforestart=NULL;
        for (int i=1; i<left; i++){
            beforestart=ptr;
            ptr=ptr->next;
        }
        ListNode* start=ptr;

        ListNode* prev = NULL;
        for (int i=0; i<=(right-left); i++){
            ListNode* nextnode = ptr->next;
            ptr-> next=prev;
            prev = ptr;
            ptr = nextnode;
        }
        start->next=ptr;
        if (beforestart==NULL) return prev;
        beforestart->next=prev;

       return head; 
    }
};