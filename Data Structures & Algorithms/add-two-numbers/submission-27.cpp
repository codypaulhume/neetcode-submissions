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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Add each node and carry the ones place over if >= 10
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        vector<ListNode*> nodes;

        int val1 = 0, val2 = 0, total = 0;
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr) {

            // Checks if one list is longer than the other
            if (temp1 != nullptr) {
                val1 = temp1->val;
            } else {
                val1 = 0;
            }
            if (temp2 != nullptr) {
                val2 = temp2->val;
            } else {
                val2 = 0;
            }

            total = val1 + val2 + carry;

            if (total >= 10) {
                total = total - 10;
                carry = 1;
            }else{
                carry = 0;
            }

            ListNode* newNode = new ListNode(total);
            nodes.push_back(newNode);

            // Reset
            val1 = 0, val2 = 0, total = 0;

            // Iterate
            if(temp1 != nullptr){
                temp1 = temp1->next;
            }
            if(temp2 != nullptr){
               temp2 = temp2->next; 
            } 
        }

        // Check for last carry
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            nodes.push_back(newNode);
        }

        // Connect the nodes
        // Note: It is length - 1 since we cannot point to a place in a vector that does not exist
        int length = nodes.size();
        for (int i = 0; i < length - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        return nodes[0];
    }
};
