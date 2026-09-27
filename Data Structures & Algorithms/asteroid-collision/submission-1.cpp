class Solution {
    stack<int> st;

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        for (int x : asteroids) {

            while (!st.empty() && x < 0 && st.top() > 0) {

                if (st.top() < -x) {
                    st.pop();
                }
                else if (st.top() == -x) {
                    st.pop();
                    x = 0;
                    break;
                }
                else {
                    x = 0;
                    break;
                }
            }

            if (x != 0) {
                st.push(x);
            }
        }


        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
