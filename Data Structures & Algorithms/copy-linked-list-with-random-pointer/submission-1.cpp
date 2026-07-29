/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> myMap;

        // Iterate through the original LL and create all the nodes with its old node as the key value pair

        Node* temp = head;
        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            myMap[temp] = newNode;
            temp = temp->next;
        }

        // Assigning pointers. Grab the current node "current". Set it's "next" pointer by finding the 
        // old value's key value pair. BECAUSE all old nodes are paried with the new nodes.

        Node* temp2 = head;

        while(temp2 != nullptr){
            Node* current = myMap[temp2];
            current->next = myMap[temp2->next];
            current->random = myMap[temp2->random];
            temp2 = temp2->next;
        }
        temp2 = head;
        return myMap[temp2];
    }
};
