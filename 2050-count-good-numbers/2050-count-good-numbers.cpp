class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  
        long long oddCount = n / 2;         
        
        return (modPow(5, evenCount) * modPow(4, oddCount)) % MOD;
    }
    
private:
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
};