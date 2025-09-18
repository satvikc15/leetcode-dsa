class TaskManager {
public:
    struct Comp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first == b.first) return a.second < b.second;          
            return a.first < b.first; 
        }
    };

    map<int,int> mpp1;
    map<int,int> mpp2; 
    priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &it : tasks) {
            mpp1[it[1]] = it[0];      
            mpp2[it[1]] = it[2];      
            pq.push({it[2], it[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mpp1[taskId] = userId;
        mpp2[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        mpp2[taskId] = newPriority;
        pq.push({newPriority, taskId}); 
    }
    
    void rmv(int taskId) {
        mpp1.erase(taskId);
        mpp2.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            if (mpp2.count(taskId) && mpp2[taskId] == priority) {
                int temp=mpp1[taskId];
                mpp1.erase(taskId);
                mpp2.erase(taskId);
                return temp; 
            } else {
                pq.pop(); 
            }
        }
        return -1; 
    }
};
