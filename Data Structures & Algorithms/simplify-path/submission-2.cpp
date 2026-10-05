class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";

        for (char c : path + "/") {
            if (c == '/') {
                if (curr == "..") {
                    if (!st.empty()) {
                        st.pop_back(); 
                    }
                } else if (curr != "" && curr != ".") {
                    st.push_back(curr); 
                }
                curr.clear();
            } else {
                curr += c;
            }
        }

        string res = "";
        for (const string& dir : st) {
            res += "/" + dir;
        }

        // If the path is empty, return "/"
        return res.empty() ? "/" : res;
    }
};
