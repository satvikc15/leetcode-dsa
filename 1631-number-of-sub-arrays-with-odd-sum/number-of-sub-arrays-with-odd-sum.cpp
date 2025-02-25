#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> temp(arr.size(),0);
        int sum=0;
        int count=0;
        int odd=0,even=0;
        for(int i=0;i<arr.size();i++){
            sum=(arr[i]+sum)%mod;
            temp[i]=sum%mod;
            if(temp[i]%2==1) {
                count=(count+1+even)%mod;
                odd++;
            }else{
                count=(count+odd)%mod;
                even++;
            }
        }
        return count;
        
    }
};