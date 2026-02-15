class Solution {
public:
    string addBinary(string a, string b) {
        int s_a = a.length();
        int s_b = b.length();

        int temp = max(s_a, s_b);
        int crr = 0;
        string result = "";

        for(int i = 0; i < temp; i++){
            int bitA = 0, bitB = 0;

            if(i < s_a){ 
                bitA = a[s_a - 1 - i] - '0';
            }
            if(i < s_b){
                 bitB = b[s_b - 1 - i] - '0';
            }
            int sum = bitA + bitB + crr;

            result.push_back((sum % 2) + '0');
            crr = sum / 2;
        }

        if(crr == 1) result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }
};
