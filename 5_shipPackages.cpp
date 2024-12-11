#include <vector>
#include <numeric>  // for accumulate
#include <algorithm>  // for max_element
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to check if we can ship all packages within the given number of days
    // with the current ship capacity.
    bool canShipWithinDays(const vector<int>& weights, int days, int capacity) {
        int currentWeight = 0;  // Current total weight on the ship for the current day
        int requiredDays = 1;   // Start counting days from 1
        
        // Iterate through each package weight
        for (int weight : weights) {
            // If adding the current package exceeds the capacity, we need an additional day
            if (currentWeight + weight > capacity) {
                requiredDays++;  // Increment the number of days needed
                currentWeight = 0;  // Reset the current weight for the new day
            }
            currentWeight += weight;  // Add the current package weight to the ship
        }

        // Return true if the required days are within the allowed days
        return requiredDays <= days;
    }

    // Function to find the minimum ship capacity to ship all packages within the given days
    int shipWithinDays(vector<int>& weights, int days) {
        // The minimum capacity must be at least the weight of the heaviest package
        int left = *max_element(weights.begin(), weights.end());
        // The maximum capacity would be the sum of all package weights
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Perform binary search between the minimum and maximum capacity
        while (left < right) {
            int mid = left + (right - left) / 2;  // Calculate the midpoint capacity
            // Check if it's possible to ship all packages with the current mid capacity
            if (canShipWithinDays(weights, days, mid)) {
                right = mid;  // Try to find a smaller valid capacity
            } else {
                left = mid + 1;  // Increase the capacity since mid is not sufficient
            }
        }

        // The left will point to the minimum capacity required
        return left;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Package weights
    int days = 5;  // Number of days to ship all packages
    // Find the minimum capacity required
    int result = solution.shipWithinDays(weights, days);
    // Output the result
    cout << "The minimum capacity required to ship all packages within " << days << " days is " << result << "." << endl;
    return 0;
}
