class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *current = head ; 
        ListNode *ans = head ; 
        ListNode *dn = ans ; 
        int x = 0 ; 
        while(current){
            if(x > 0 and current -> val == 0){
                ListNode *newnode = new ListNode(x) ;
                x = 0 ; 
                ans -> next = newnode ; 
                ans = newnode ; 
            }
            x += current -> val ; 
            current = current -> next ; 
        }
        return dn -> next ; 
    }
};
