class Solution {
public:
    int smallestNumber(int n) {
        vector<int> arr;
        int a=1;
        for(int i=0;i<31;i++){
            arr.push_back(a-1);
            a<<=1;
        }
        for(int i=0;i<30;i++){
            if(arr[i+1]>=n){
                return arr[i+1];
            }
        }
        return -1;
    }
};