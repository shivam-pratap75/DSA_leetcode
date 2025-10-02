class Solution {
public:

    int maxBottlesDrunk(int numBottles, int numExchange) {
        
    int result=numBottles;
    if(numBottles<numExchange){
        return result;
    }else if(numBottles==numExchange){
        return result+1;
    }else{

    while(numBottles>=numExchange){
    
      numBottles -=numExchange;
      numBottles++;
      result++;
      numExchange++;

    }
    }

return result;
    }
};