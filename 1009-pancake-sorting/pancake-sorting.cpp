class Solution {
public:
    void flip(vector<int>&arr,int idx){
        int l=0,r=idx;
        while(l<r){
            swap(arr[l],arr[r]);
            r--;
            l++;
        }

    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for(int i=arr.size()-1;i>=0;i--){
            bool flag=false;
            for(int j=0;j<i;j++){
                if(arr[j]==i+1){
                    flip(arr,j);
                    ans.push_back(j+1);
                    flag=true;
                    break;
                }
            }
            if(flag){
                flip(arr,i);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};