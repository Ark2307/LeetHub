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
    
    ListNode *reverse(ListNode *l1){
        ListNode *curr = l1 ;
        ListNode *prev = NULL ;
        ListNode *next = NULL ;
        
        while(curr != NULL){
            next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev ;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode *head = new ListNode(0 , NULL) ;
        
        l1 = reverse(l1) ;
        l2 = reverse(l2) ;
        
        ListNode *p = l1 ;
        ListNode *q = l2 ;
        
        while(p != NULL && q != NULL){
            p = p->next ;
            q = q->next ;
        }
        
        bool flag = 0 ;
        
        if(p == NULL)
        {
            head->next = l2 ;
            flag = 1 ;
        }
        else
            head->next = l1 ;
        
        q = l2 , p = l1 ;
        
        while(l1 != NULL && l2 != NULL){
            int x = l1->val + l2->val + carry ;
            carry = x / 10 ;
            x %= 10 ;
            
            if(flag)
                l2->val = x ;
            
            else
                l1->val = x ;
            l1 = l1->next ;
            l2 = l2->next ;
        }
        
        if(flag){
            while(l2 != NULL){
                int x = l2->val + carry ;
                carry = x / 10 ;
                x %= 10 ;
                l2->val = x ;
                l2 = l2->next ;
            }
            
            if(carry > 0){
                ListNode *extra = new ListNode(carry , NULL) ;
                while(q->next != NULL){
                    q = q->next ;
                }
                q->next = extra ;
            }
        }
        
        else{
            while(l1 != NULL){
                int x = l1->val + carry ;
                carry = x / 10 ;
                x %= 10 ;
                l1->val = x ;
                l1 = l1->next ;
            }
            
            if(carry > 0){
                ListNode *extra = new ListNode(carry , NULL) ;
                while(p->next != NULL){
                    p = p->next ;
                }
                p->next = extra ;
            }            
        }
        
        return reverse(head->next) ;
    }
    
};