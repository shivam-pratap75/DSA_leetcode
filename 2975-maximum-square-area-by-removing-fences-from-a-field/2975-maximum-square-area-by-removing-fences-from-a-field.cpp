class Solution {
public:
int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    hFences.push_back(1); hFences.push_back(m);

    vector <bool> arr1(m, 0);
    for(int i = 0; i < hFences.size(); i++){
        for(int j = i + 1; j < hFences.size(); j++){
            arr1[abs(hFences[i] - hFences[j])] = 1;
        }
    }

    vFences.push_back(1); vFences.push_back(n);

    vector <bool> arr2(n, 0);
    for(int i = 0; i < vFences.size(); i++){
        for(int j = i + 1; j < vFences.size(); j++){
            arr2[abs(vFences[i] - vFences[j])] = 1;
        }
    }
    const int MOD = 1e9 + 7;
    int min_val = min(m, n);
    for(int i = min_val - 1; i > 0; i--){
    if (arr1[i] && arr2[i]) return ((long long)i * i) % MOD;
    }
    return -1;
}
};