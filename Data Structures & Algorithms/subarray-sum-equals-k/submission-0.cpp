class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;
        int answer = 0;
        int prefixSum =0;
        mpp[0] = 1;

        for (int num: nums) {
            prefixSum += num;
            int needed = prefixSum  - k;

            if(mpp.find(needed) != mpp.end()){
                answer +=  mpp[needed];

            }
            mpp[prefixSum]++;

        }
        return answer;



        
    }
};