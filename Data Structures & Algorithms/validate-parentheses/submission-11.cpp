class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        // Iterate through each character. If an opening brackets, push onto stack.
        // Otherwise, check if stack is empty first.
        // Then check if it is a closing bracket on top of the stack for each case.
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                myStack.push(c);
            }else{
                if(myStack.empty()){
                    return false;
                }
                // Checks for the match
                if(c == ')' && myStack.top() == '('){
                    myStack.pop();
                }else if(c == ']' && myStack.top() == '['){
                    myStack.pop();
                }else if(c == '}' && myStack.top() == '{'){
                    myStack.pop();
                }else{
                    return false;
                }
            }   
        }
        
        if(myStack.empty()){
            return true;
        }
        return false;
    }
};
