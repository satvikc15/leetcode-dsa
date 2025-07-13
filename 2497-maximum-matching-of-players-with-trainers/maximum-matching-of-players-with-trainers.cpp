class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.rbegin(),players.rend());
        sort(trainers.rbegin(),trainers.rend());
        int n=trainers.size();
        int count=0;
        int r=0;
        int i=0;
        int m=players.size();
        while(i<m && r<n){
            if(players[i]<=trainers[r]){
                i++;
                r++;
                count++;
            }else{
                i++;
            }
        }

        return count;
    }
};