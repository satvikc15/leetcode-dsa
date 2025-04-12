class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int og,vector<vector<bool>>&visited){
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        visited[sr][sc]=true;
        for(auto [a,b]:dir){
            int na=a+sr;
            int nb=b+sc;
            if(na>=0 && nb>=0 && na<image.size() && nb<image[0].size() && image[na][nb]==og && !visited[na][nb]){
                image[na][nb]=color;
                dfs(na,nb,image,color,og,visited);
            } 
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        dfs(sr,sc,image,color,og,visited);
        return image;
    }
};