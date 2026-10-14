class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 || sum > (9 * num)){
            return "";
        }
        string ans = "";
        while(ans.size() != num){
            if(sum <= 9){
                ans += to_string(sum);
                sum = 0;
            }
            else{
                ans += '9';
                sum -= 9;
            }
        }
        return ans;
    }
};