class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> myStack;
        string filteredString;

        // Filter out everything but unsigned characters and set to lowercase.
        for(char c : s){
            if(isalpha(c) || isdigit(c)){
                filteredString += tolower(c);
            }
        }

        // Push characters into stack
        for(char c : filteredString){
            myStack.push(c);
        }

        // Add reverse to empty string. Grab the top value then pop from the stack
        string result;
        while(!myStack.empty()){
            result = result + myStack.top();
            myStack.pop();
        }

        // Check if reverse result is the same as original
        if(result == filteredString){
            return true;
        }
        return false;
    }
};
