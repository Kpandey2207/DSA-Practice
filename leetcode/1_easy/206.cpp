class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;

        deque<ListNode*> dq;

        ListNode* temp = head;
        while(temp){
            dq.push_back(temp);
            temp = temp->next;
        }

        ListNode* newHead = dq.back();
        dq.pop_back();

        temp = newHead;

        while(!dq.empty()){
            temp->next = dq.back();
            dq.pop_back();
            temp = temp->next;
        }

        temp->next = NULL;

        return newHead;
    }
};