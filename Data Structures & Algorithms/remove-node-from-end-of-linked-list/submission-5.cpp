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
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        // Grab the length of the LL
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            length++;
            temp = temp->next;
        }
        // Edge case (length = 1)
        if(length == n){
            return head->next;
        }
        int gap = length - n;

        // Find node before to iterate to. Then skip over node to "remove"
        ListNode* curr = head;
        for(int i = 1; i < gap; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};
