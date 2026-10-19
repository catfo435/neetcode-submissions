class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char i :s){
            if (i == '[' || i == '{' || i == '(') st.push(i);
            else if ( (i == ']' || i == '}' || i == ')') && st.empty()) return false;
            else if ( !st.empty() && (st.top() == '[' && i == ']' || st.top() == '{' && i == '}' || st.top() == '(' && i == ')')) st.pop();
            else if (!st.empty()) return false;
        }
        return st.empty();
    }
};
