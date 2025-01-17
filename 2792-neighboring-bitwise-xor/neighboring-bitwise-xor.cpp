class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int first=0;
        int last=0;
        for(auto it:derived){
            if(it){
                last=~last;
            }
        }
        return first==last;
    }
};