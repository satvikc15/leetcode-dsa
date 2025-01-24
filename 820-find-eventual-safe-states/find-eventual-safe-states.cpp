class Solution {
public:
    bool f(int i,vector<vector<int>>&graph,map<int,bool>&mpp){
        if(mpp.find(i)!=mpp.end()){
            return mpp[i];
        }
        mpp[i]=false;
        for(int j=0;j<graph[i].size();j++){
            if(!f(graph[i][j],graph,mpp)){
                return mpp[i];
            }
        }
        return mpp[i]=true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        map<int,bool> mpp;
        for(int i=0;i<graph.size();i++){
            if(f(i,graph,mpp)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};