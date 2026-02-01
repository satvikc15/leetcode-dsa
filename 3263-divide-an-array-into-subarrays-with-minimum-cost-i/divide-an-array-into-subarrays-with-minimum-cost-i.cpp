class Solution {
public:
    int minimumCost(vector<int>& nums) {
        priority_queue<int,vector<int>,less<int>> pq;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>3){
                pq.pop();
            }
        }
        int ans=nums[0];
        int temp=pq.top();
        pq.pop();
        int count=0;
        for(int i=0;i<2;i++){
            if(nums[0]!=pq.top()){
                ans+=pq.top();
                count++;
            }
            pq.pop();
        }
        if(count==2){
            return ans;
        }else if(count==0){
            return ans+temp+pq.top();
        }
        else return ans+temp;
    }
};