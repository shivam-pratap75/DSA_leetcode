class Solution {
public:

void down(string s, vector<vector<char>>& matrix, int &i, int &j, int numRows, int &k) {
    while(i < numRows && k < s.size()) {      
        matrix[i][j] = s[k];
        k++;
        i++;
    }
    i = numRows - 2; 
    j++; 
}

void up(string s, vector<vector<char>>& matrix, int &i, int &j, int numRows, int &k) {
    while(i >= 0 && k < s.size()) {       
        matrix[i][j] = s[k];
        k++;
        i--;
        
    }
    i = 1; 
    j++; 
}

string convert(string s, int numRows) {
    if(numRows == 1 || s.empty()) return s;
    
    int i = 0, j = 0, k = 0;
    
 
    int num=s.size()-1;
   int numCols = 1; 
if(s.size() > 1) {
    int num = s.size() - 1;
    if(num % (numRows-1) == 0) {
        numCols = num / (numRows-1);
    } else {
        num += numRows - 1;
        numCols = num / (numRows-1);
    }
    
    numCols = max(numCols, 1);
}
    
    vector<vector<char>> matrix(numRows, vector<char>(numCols, '0'));
    
    
    bool goingDown = true;
    while(k < s.size() && j < numCols) {
        if(goingDown) {
            down(s, matrix, i, j, numRows, k);
            goingDown = false;
        } else {
            up(s, matrix, i, j, numRows, k);
            goingDown = true;
        }
    }
    
   
    string result = "";
    for(int a = 0; a < numRows; a++) {
        for(int p = 0; p < numCols; p++) {
            if(matrix[a][p] != '0') {
                result += matrix[a][p];
            }
        }
    }
    return result;
}
};
