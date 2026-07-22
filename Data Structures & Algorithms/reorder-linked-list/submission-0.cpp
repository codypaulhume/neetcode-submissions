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
    void reorderList(ListNode* head) {
        //Split the list in half
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Reach midpoint by using fast and slow pointers
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        // Grab the newHead node (beginning of second half "head"). Break off first list.
        ListNode* newHead = slow->next;
        slow->next = nullptr;

        ListNode* secondHead = newHead;
        ListNode* after = secondHead->next; 
        ListNode* prev = nullptr;

        while(secondHead != nullptr){
            after = secondHead->next;
            secondHead->next = prev;
            prev = secondHead;
            secondHead = after;
        }
        // Now the prev is looking at the new head

        // Pair the nodes
        ListNode* l1Head = head;
        ListNode* l2Head = prev;
        ListNode* curr = head;

        while(l2Head != nullptr){
            l1Head = l1Head->next;
            curr->next = l2Head;
            l2Head = l2Head->next;
            curr = curr->next;
            curr->next = l1Head;
            curr = curr->next;
        }
    }
};
