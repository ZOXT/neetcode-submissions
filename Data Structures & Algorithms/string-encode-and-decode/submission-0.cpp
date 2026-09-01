class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string s: strs){
            encoded+= to_string(s.size()) + "$" + s;
        }

         return encoded;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i < s.size()){
            int j = s.find("$", i);
            int len = stoi(s.substr(i, j-i));
            string substr = s.substr(j+1, len);
            result.push_back(substr);
            i = len+ j+1;

        
        }
        return result;


    }
};
