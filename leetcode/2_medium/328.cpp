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
    ListNode* oddEvenList(ListNode* head) {\
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* topEven=head->next;
        ListNode* currEven=head->next;
        ListNode* currOdd=head;
        while(currEven!=NULL && currEven->next!=NULL){
            ListNode* newOdd=currEven->next;
            currEven->next=newOdd->next; // remove odd from even chain
            currOdd->next=newOdd;        // attach after odd tail
            currOdd=newOdd;              // move odd tail
            if(currEven->next!=NULL)
                currEven=currEven->next; // move even tail
        }
        currOdd->next=topEven;
        return head;
    }
};