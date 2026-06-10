class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        stack<int> stk;

        while(temp!=NULL){
            // Check if k nodes exist
            ListNode* check=temp;
            int count=0;
            while(check!=NULL && count<k){
                check=check->next;
                count++;
            }
            if(count<k)
                break;
            int copy=k;
            ListNode* ele=temp;
            while(copy--){
                stk.push(ele->val);
                ele=ele->next;
            }
            ele=temp;
            copy=k;
            while(copy--){
                ele->val=stk.top();
                stk.pop();
                ele=ele->next;
            }
            copy=k;
            while(copy-- && temp!=NULL)
                temp=temp->next;
        }
        return head;
    }
};