class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int n = height.size();
        int l=0,r=n-1;
        while(l<r){
            int h = min(height[l],height[r]);
            int temp = (r-l)*h;
            maxi = max(maxi,temp);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxi;
    }
};