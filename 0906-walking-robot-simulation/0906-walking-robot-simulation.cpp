class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
   
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<string> obstaclesSet;
    for (const auto& obstacle : obstacles) {
        obstaclesSet.insert(to_string(obstacle[0]) + " " + to_string(obstacle[1]));
    }

    int x = 0, y = 0, direction = 0, maxDistSquare = 0;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == -2) {
            direction = (direction + 3) % 4;
        } else if (commands[i] == -1) {
            direction = (direction + 1) % 4;
        } else {
            int step = 0;
            while (step < commands[i] 
                   && (!obstaclesSet.count(
                       to_string(x + directions[direction][0]) + " " + to_string(y + directions[direction][1]))
                   )
                  ) {
                x += directions[direction][0];
                y += directions[direction][1];
                step++;
            }
        }
        maxDistSquare = max(maxDistSquare, x * x + y * y);
    }

    return maxDistSquare;
}   
};