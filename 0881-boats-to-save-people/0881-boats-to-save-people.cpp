class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0;
        int j = n - 1;
        int boats = 0;
        while(i <= j){
            if(i == j){
                boats++;
                break;
            }
            int sum = people[i] + people[j];
            if(sum <= limit){
                boats++;
                i++;
                j--;
            }
            else{
                boats++;
                j--;
            }
        }
        return boats;
    }
};