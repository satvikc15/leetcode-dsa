class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> st(languages.size());
        for(int i=0;i<languages.size();i++){
            for(auto lang:languages[i]){
                st[i].insert(lang);
            }
        }
        unordered_set<int> col;
        for(auto it:friendships){
            int u = it[0]-1;
            int v = it[1]-1;
            bool flag=false;
            for(auto it:st[u]){
                if(st[v].count(it)){
                    flag=true;
                }
            }
            if(!flag){
                col.insert(u);
                col.insert(v);
            }
        }
        int res = INT_MAX;
        for(int i=1;i<=n;i++){
            int known = 0;
            for (int user : col) {
                if (st[user].count(i)) {
                    known++;
                }
            }

            res = min(res,(int)col.size()-known);
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};