class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int maxUnits = 0;

        for (auto& box : boxTypes) {
            int numBoxes = box[0];
            int unitsPerBox = box[1];

            if (numBoxes <= truckSize) {
                maxUnits += numBoxes * unitsPerBox;
                truckSize -= numBoxes;
            } else {
                maxUnits += truckSize * unitsPerBox;
                break;
            }
            
        }

        return maxUnits;
    }
};
