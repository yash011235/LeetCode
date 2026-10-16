class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 1 || (i > 0 && flowerbed[i - 1] == 1) || (i + 1 < flowerbed.size() && flowerbed[i + 1] == 1)){
                continue;
            }
            else{
                cnt++;
                i++;
            }
        }
        return (cnt >= n);
    }
};