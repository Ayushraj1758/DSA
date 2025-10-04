class SnapshotArray {
public:
    int snap_id;
    vector<vector<pair<int,int>>> data; // data[index] = { (snap_id, value) }

    SnapshotArray(int length) {
        snap_id = 0;
        data.resize(length);
        for (int i = 0; i < length; ++i) {
            data[i].push_back({0, 0}); // Initially all 0s at snap_id 0
        }
    }
    
    void set(int index, int val) {
        if (data[index].back().first == snap_id) {
            // Overwrite current snapshot value if already exists
            data[index].back().second = val;
        } else {
            // Record a new (snap_id, value)
            data[index].push_back({snap_id, val});
        }
    }
    
    int snap() {
        return snap_id++; // return current id, then increment
    }
    
    int get(int index, int id) {
        // Binary search for last snap_id <= id
        auto &arr = data[index];
        int l = 0, r = arr.size() - 1;
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= id) {
                res = arr[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
