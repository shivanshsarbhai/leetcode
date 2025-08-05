class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int noOfFruits = fruits.size();
        int noOfBaskets = baskets.size();
        vector<bool> basketUsed(noOfBaskets, false);
        int unplaced = 0;

        for (int i = 0; i < noOfFruits; ++i) {
            bool placed = false;
            for (int j = 0; j < noOfBaskets; ++j) {
                if (!basketUsed[j] && fruits[i] <= baskets[j]) {
                    basketUsed[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }
        return unplaced;
    }
};
