class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        struct Transaction {
            string name;
            int time;
            int amount;
            string city;
            string original;
        };

        int n = transactions.size();
        vector<Transaction> trans;

        // Parse input transactions
        for (auto &t : transactions) {
            stringstream ss(t);
            string name, timeStr, amountStr, city;
            getline(ss, name, ',');
            getline(ss, timeStr, ',');
            getline(ss, amountStr, ',');
            getline(ss, city, ',');
            trans.push_back({name, stoi(timeStr), stoi(amountStr), city, t});
        }

        vector<bool> invalid(n, false);

        // Check conditions
        for (int i = 0; i < n; ++i) {
            if (trans[i].amount > 1000) invalid[i] = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (trans[i].name == trans[j].name &&
                    abs(trans[i].time - trans[j].time) <= 60 &&
                    trans[i].city != trans[j].city) {
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }

        // Collect invalid transactions
        vector<string> result;
        for (int i = 0; i < n; ++i) {
            if (invalid[i]) result.push_back(trans[i].original);
        }

        return result;
    }
};
