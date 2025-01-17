class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s=0;
        for(auto it:derived){
            s^=it;
        }
        if(s!=0) return false;
        return true;
    }
};