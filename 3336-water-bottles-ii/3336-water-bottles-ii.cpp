class Solution {
public:

    int maxBottlesDrunk(int numBottles, int numExchange) {
        
    int result=numBottles;

    while(numBottles>=numExchange){
    
      numBottles = numBottles-numExchange;
      numBottles++;
      result++;
      numExchange++;

    }

return result;
    }
};