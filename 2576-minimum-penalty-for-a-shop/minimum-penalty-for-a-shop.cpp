class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        
        // Initial penalty: closed all day → count all 'Y'
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Try opening hour by hour
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == 'Y') {
                penalty--;   // good: customer comes while open
            } else {
                penalty++;   // bad: open but no customer
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
