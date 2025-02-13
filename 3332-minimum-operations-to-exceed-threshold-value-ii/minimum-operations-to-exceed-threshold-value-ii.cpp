class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        int count=0;
        while(true){
            if(pq.top()>=k){
                break;
            }
            count++;
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            pq.push((long long)min(a,b)*2+(long long)max(a,b));
        }
        return count;
    }
};