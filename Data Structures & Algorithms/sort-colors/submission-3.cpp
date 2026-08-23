class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int curr = 0;
        int hi = nums.size() - 1;

        while(curr <= hi){
            
        if (nums[curr] == 0) {
            swap(nums[low], nums[curr]);
            low++;
            curr++;
        } else if (nums[curr] == 2) {
            swap(nums[hi], nums[curr]);
            hi--;
        } else {
            curr++;
        }
    }


        }

};