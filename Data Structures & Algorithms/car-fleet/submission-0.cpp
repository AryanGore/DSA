class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({
                position[i],
                (double)(target - position[i]) / speed[i]
            });
        }

        sort(cars.begin(), cars.end(), greater<>());

        int fleets = 0;
        double maxTime = 0;

        for (auto& car : cars) {
            if (car.second > maxTime) {
                fleets++;
                maxTime = car.second;
            }
        }

        return fleets;
    }
};
