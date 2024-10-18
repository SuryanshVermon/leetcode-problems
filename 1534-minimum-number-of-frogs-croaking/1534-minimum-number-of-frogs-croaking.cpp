class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count[5] = {0};
        int frogs = 0, maxFrogs = 0;
        string croak = "croak";

        for (char ch : croakOfFrogs) {
            int index = croak.find(ch);
            if (index == string::npos)
                return -1;

            count[index]++;
            if (index > 0 && count[index] > count[index - 1])
                return -1;

            if (index == 4) {
                frogs--;
                for (int i = 0; i < 5; i++)
                    count[i]--;
            } else if (index == 0) {
                frogs++;
                maxFrogs = max(maxFrogs, frogs);
            }
        }

        return frogs == 0 ? maxFrogs : -1;
    }
};
