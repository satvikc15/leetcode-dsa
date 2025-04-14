class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size(),count=0;
        for(int i=0;i<n;i++){
            int t1=arr[i];
            for(int j=i+1;j<n;j++){
                int t2=arr[j];
                if(abs(t1-t2)<=a){
                    for(int k=j+1;k<n;k++){
                        int t3=arr[k];
                        if(abs(t1-t3)<=c && abs(t2-t3)<=b){
                            count++;
                        }
                    }
                }
            }
        }
                    return count;

    }
};