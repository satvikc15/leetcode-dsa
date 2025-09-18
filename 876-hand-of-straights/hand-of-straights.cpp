class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        int n = hand.size()/groupSize;
        int num=0;
        for(int i=0;i<hand.size();i++){
            if(mpp.find(hand[i])!=mpp.end()){
                int count=1;
                mpp[hand[i]]--;
                if(mpp[hand[i]]==0) mpp.erase(hand[i]);
                int temp=hand[i]+1;
                while(count<groupSize){
                    if(mpp.find(temp)!=mpp.end()){
                        count++;
                        mpp[temp]--;
                        if(mpp[temp]==0) mpp.erase(temp);
                        temp++;
                    }else{
                        break;
                    }
                }
                if(count==groupSize) num++;
                else return false;
            }
        }
        cout << num;
        return num==n;


    }
};