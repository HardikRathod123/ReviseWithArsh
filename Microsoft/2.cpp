/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto a : tokens){
            if(a.size() > 1 || isdigit(a[0])) st.push(stoi(a));
            else {
                auto op2=st.top(); 
                st.pop();
                auto op1=st.top(); 
                st.pop();
                switch(a[0]) {
                    case '+': op1+=op2; break;
                    case '-': op1-=op2; break;
                    case '*': op1*=op2; break;
                    case '/': op1/=op2; break;
                }
                st.push(op1);
            }            
        }
        return st.top();
    }
};
