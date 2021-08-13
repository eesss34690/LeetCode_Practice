class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        bool onfirstRow = false,onfirstCol = false;
        for(int j=0;j<m;j++){
            if(!matrix[0][j]){
                onfirstRow = true;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(!matrix[i][0]){
                onfirstCol = true;
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!matrix[i][0] or !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        if(onfirstRow){
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;
        }
        if(onfirstCol){
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
        }
    }
};
