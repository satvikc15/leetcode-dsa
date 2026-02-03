class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool a=false;
        bool b=false;
        bool c=false;

        int l=0,r=1;
        int n=nums.size();
        while(r<n){
            if(nums[r]>nums[r-1]){
                r++;
                a=true;
            }else{
                break;
            }
        }
        if(a){
            while(r<n){
                if(nums[r]<nums[r-1]){
                r++;
                b=true;
                }else{
                    break;
                }
            }
        }else return false;
        //cout << r  << endl;
        if(b){
            while(r<n){
                if(nums[r]>nums[r-1]){
                r++;
                c=true;
                }else{
                    break;
                }
            }
        }else return false;
        cout << c<<endl;
        return c&&true && r==n;
    }
};