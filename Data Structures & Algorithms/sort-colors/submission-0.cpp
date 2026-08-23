class Solution {
public:
    void sortColors(vector<int>& nums) {

        unordered_map <int, int > mpp;

        for ( int num : nums){

            mpp[num]++;
        }

        int index = 0;

      for (int color= 0; color<=2; color++){

        while(mpp[color] > 0){
            nums[index] = color;
            index++;
            mpp[color]--;
        }

      }
    
};
};