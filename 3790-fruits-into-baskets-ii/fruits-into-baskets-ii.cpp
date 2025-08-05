class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        int noOfFruits = fruits.size();
        int noOfBaskets = baskets.size();
        vector<bool>basketVisited(noOfBaskets, false);

        for(int i=0;i<noOfFruits;i++){
            for(int j=0;j<noOfBaskets;j++){
                if(!basketVisited[j]){
                    if(fruits[i]<=baskets[j]){
                        basketVisited[j] = true;
                        break;
                    }
                }
            }
        }

        int count = 0;
        for(int i=0;i<noOfBaskets;i++){
            if(basketVisited[i])
                count++;
        }

        return noOfFruits-count;
    }
};