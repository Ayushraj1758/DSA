class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        // Zeller's Congruence algorithm
        if (month < 3) {
            month += 12;
            year -= 1;
        }

        int K = year % 100;   // year within century
        int J = year / 100;   // zero-based century

        int h = (day + (13*(month + 1))/5 + K + K/4 + J/4 + 5*J) % 7;

        // h = 0 -> Saturday, 1 -> Sunday, 2 -> Monday, ...
        // We shift to start from Sunday
        return week[(h + 6) % 7];
    }
};
