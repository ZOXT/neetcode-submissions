class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : nums) {
            if (hashSet.find(num - 1) == hashSet.end()) {
                int streak = 1;
                while (hashSet.find(num + streak) != hashSet.end()) {
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
