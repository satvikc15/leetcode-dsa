class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        }
    };

    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, cmp>> mpp; 
    unordered_map<string,string> mpp2; 
    unordered_map<string,int> rating;  

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < cuisines.size(); i++) {
            mpp[cuisines[i]].push({ratings[i], foods[i]});
            mpp2[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = mpp2[food];
        rating[food] = newRating;
        mpp[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
       auto &pq = mpp[cuisine];
        while (!pq.empty()) {
            auto [r, f] = pq.top();
            if (rating[f] == r) return f; 
            pq.pop(); 
        }
        return ""; 
    }
};
