class DinnerPlates {
    int cap;
    vector<stack<int>> stacks;
    set<int> available; // stores indices of stacks that are not full

public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }

    void push(int val) {
        // If no stack available, create one
        if (available.empty()) {
            stacks.push_back(stack<int>());
            available.insert(stacks.size() - 1);
        }

        int idx = *available.begin();
        stacks[idx].push(val);

        // If stack becomes full, remove it from available
        if (stacks[idx].size() == cap)
            available.erase(idx);
    }

    int pop() {
        // Remove empty stacks from the end
        while (!stacks.empty() && stacks.back().empty()) {
            available.erase(stacks.size() - 1);
            stacks.pop_back();
        }

        if (stacks.empty())
            return -1;

        int idx = stacks.size() - 1;
        int val = stacks[idx].top();
        stacks[idx].pop();

        // Add index back to available if it has space now
        available.insert(idx);

        // Remove trailing empty stacks again if needed
        while (!stacks.empty() && stacks.back().empty()) {
            available.erase(stacks.size() - 1);
            stacks.pop_back();
        }

        return val;
    }

    int popAtStack(int index) {
        if (index < 0 || index >= (int)stacks.size() || stacks[index].empty())
            return -1;

        int val = stacks[index].top();
        stacks[index].pop();

        // Add index to available if it has space now
        available.insert(index);

        return val;
    }
};
