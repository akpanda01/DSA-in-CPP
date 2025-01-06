//Koko Eating Bananas


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, h, mid)) {
                result = mid; // Update the result with a smaller feasible speed
                high = mid - 1; // Search for a smaller speed
            } else {
                low = mid + 1; // Increase speed
            }
        }

        return result;
    }

private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // Equivalent to ceil(pile / k)
            if (hours > h) return false; // Early exit if hours exceed h
        }
        return true;
    }
};
