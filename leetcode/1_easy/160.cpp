/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        long long s1=0,s2=0;
        while(tempA!=NULL){
            tempA=tempA->next;
            s1++;
        }
        while(tempB!=NULL){
            tempB=tempB->next;
            s2++;
        }
        tempA=headA;
        tempB=headB;
        if(s1>=s2){
            int n=s1-s2;
            while(n--)
            tempA=tempA->next;
        }
        else{
            int n=s2-s1;
            while(n--)
            tempB=tempB->next;
        }
        while(tempB!=NULL){
            if(tempA==tempB)
                return tempB;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};