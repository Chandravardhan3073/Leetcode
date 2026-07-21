class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i =0;i< n;i++){
            int st = 0,end = n-1;
            while(st<end){
                swap(image[i][st],image[i][end]);
                st++;
                end--;
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j <n;j++){
                image[i][j] = image[i][j] ^ 1;
            }
        }
        return image;
    }
};