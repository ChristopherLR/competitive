// Runtime: 23ms, Memory: 10.4MB
std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
    // m x n matrix
    int mLen = mat.size();
    int nLen = mat[0].size();
    std::vector<int> weakestRows;
    for (int r = 0; r < nLen; r++){
        for (int c = 0; c < mLen; c++){
            if (mat[c][r] == 0 && std::find(weakestRows.begin(), weakestRows.end(), c) == weakestRows.end()){
                weakestRows.push_back(c);
                if (weakestRows.size() >= k) return weakestRows;
            }
        }
    }

    int idx = 0;
    while (weakestRows.size() < k){
        if (std::find(weakestRows.begin(), weakestRows.end(), idx) == weakestRows.end()) {
            weakestRows.push_back(idx);
        }
        idx ++;
    }
    return weakestRows;
}