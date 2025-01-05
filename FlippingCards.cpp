#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution {
public:
    static int flipgame(std::vector<int>& fronts, std::vector<int>& backs) {
        std::vector<int> bad_cards; // Store integers that appear on both sides
        std::vector<int> all_cards; // Store all integers seen (front or back)

        // Iterate over each card
        for (int i = 0; i < fronts.size(); i++) {
            // If the front and back have the same number, it's a bad card
            if (fronts[i] == backs[i]) {
                bad_cards.push_back(fronts[i]);
            }

            // Add both the front and back numbers to the all_cards set
            all_cards.push_back(fronts[i]);
            all_cards.push_back(backs[i]);
        }

        // Now, we will find the smallest number that is not in bad_cards and is in all_cards
        int min_good = INT_MAX;
        for (int card : all_cards) {
            // Check if card is not in bad_cards
            if (std::find(bad_cards.begin(), bad_cards.end(), card) == bad_cards.end()) {
                min_good = std::min(min_good, card);
            }
        }

        // If we found a good number, return it, otherwise return 0
        return min_good == INT_MAX ? 0 : min_good;
    }
};
int main()
{
    vector<int> vc = {1,1};
    vector<int> vc2 = {2,2};
    int res = Solution::flipgame(vc, vc2);
}