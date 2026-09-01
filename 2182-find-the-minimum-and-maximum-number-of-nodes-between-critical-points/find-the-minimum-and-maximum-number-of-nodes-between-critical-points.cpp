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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist=INT_MAX;
        int maxDist=INT_MIN;
        ListNode* prev=head;
        ListNode* curr=prev->next;
        int first=0;
        int second=0;
        int maxfirst;
        int i=0;
        while (curr->next!=NULL){
            i++;
            bool isLocalMax = (curr->val > prev->val) && (curr->val > curr->next->val);
            bool isLocalMin = (curr->val < prev->val) && (curr->val < curr->next->val);
            bool isCritical = isLocalMax || isLocalMin;
            if(isCritical){
            if (first==0){
                maxfirst=i;
                first=i;
                second=i;
            }
            else{
                first=second;
                second=i;
                int dist=second-first;
                minDist=min(minDist, dist);
            }
         }
            prev=prev->next;
            curr=curr->next;
        }
        if (first!=second){
            maxDist=second-maxfirst;
            return {minDist, maxDist};
        }
        else return {-1,-1};
    }
};