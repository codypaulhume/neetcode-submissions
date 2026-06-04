class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        // if(s.length() % 2 != 0 || s.length() == 0){
        //     return false;
        // }

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                myStack.push(c);
            }else{
                // Checks for the match
                if(!myStack.empty() && c == ')' && myStack.top() == '('){
                    myStack.pop();
                }else if(!myStack.empty() && c == ']' && myStack.top() == '['){
                    myStack.pop();
                }else if(!myStack.empty() && c == '}' && myStack.top() == '{'){
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
