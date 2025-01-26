class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }while(slow!=fast);
            slow=nums[0];
            while(fast!=slow){
                slow=nums[slow];
                fast=nums[fast];
            }
        
            return slow;
        
    }
};