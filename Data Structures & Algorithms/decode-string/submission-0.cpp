class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;

        string current = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                strStack.push(current);
                numStack.push(num);
                current = "";
                num = 0;
            }
            else if (c == ']') {
                int count = numStack.top();
                numStack.pop();
                string saved = strStack.top();
                strStack.pop();

                string repeated = "";
                for (int i = 0; i < count; i++) {
                    repeated += current;
                }
                current = saved + repeated;
            }
            else {
                current += c;
            }
        }
        return current;
    }
};