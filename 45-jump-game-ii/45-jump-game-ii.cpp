class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) // 0 jumps if only one element is present
            return 0;
        
        int ladder=nums[0];
        int stairs=nums[0];
        int jump=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums.size()-1 == i)
                return jump;
            
            ladder=max(ladder,nums[i]+i);
            
            stairs--; // signifies that we climbing the stairs
            
            if(stairs==0) // end of the ladder we are climbing
            {
                jump++;
                stairs=ladder-i; // new stairs are from ladder-i(overlap will be there)
                
            }
        }
        return jump;
    }
};