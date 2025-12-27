class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        int ans=0;
        int count=0;
        sort(capacity.rbegin(),capacity.rend());
        for(auto it:capacity){
            ans+=it;
            count++;
            if(ans>=sum) return count;
        }
        return count;
    }
};