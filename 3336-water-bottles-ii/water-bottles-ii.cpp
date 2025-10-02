class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            empty-=numExchange;
            numExchange++;
            count+=1;
            empty+=1;
        }
        return count;
    }
};