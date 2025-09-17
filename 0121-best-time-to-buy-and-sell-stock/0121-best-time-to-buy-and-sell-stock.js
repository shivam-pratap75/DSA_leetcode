/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let result=0;
    let a ;
    let j;

    for(let i=0;i<prices.length;i++){
        a=prices[i];
        j=i+1;
        while(j<prices.length){

            if(a-prices[j]>=0){
                break;
            }
            if(result<prices[j]-a){
                result=prices[j]-a;
            }


            j++;
        }
        

    }
    return result;
};