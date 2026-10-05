class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create a hashmap to store orignal values of speed and postion so we can reference it later
        unordered_map<int,int> CarSpeed;

        for(int i=0;i<position.size();i++){
            CarSpeed[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());


        int fleet = 0;
        double lead =0;


        for(int i=0;i<position.size();i++){
            double time = (double)(target - position[i]) / CarSpeed[position[i]];

            if(time > lead){
                fleet++;
                lead=time;
            }

        }
        return fleet;







        
    }
};
