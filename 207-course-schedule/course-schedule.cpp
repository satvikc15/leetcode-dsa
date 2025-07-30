class Solution {
private:
    bool dfs(int i,vector<vector<int>>& adj,vector<bool>&vis,vector<bool>&pathVis){
        vis[i]=true;
        pathVis[i]=true;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[i]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> pathVis(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true){
                    return false;
                }
            }
        }
        return true;
    }
};