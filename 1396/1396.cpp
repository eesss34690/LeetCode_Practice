class UndergroundSystem {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1,T2> &p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    unordered_map<int, pair<string, int>> in;
    unordered_map<pair<string, string>, pair<int, int>, pair_hash> avg;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, string> dist = make_pair(in[id].first, stationName);
        auto temp = avg.find(dist);
        if (temp == avg.end()) avg[dist] = make_pair(1, t - in[id].second);
        else
        {
            (temp->second).first += 1;
            (temp->second).second += t - in[id].second;
        }
    }

    double getAverageTime(string startStation, string endStation) {
        auto temp = avg.find(make_pair(startStation, endStation));
        return double((temp->second).second) / double((temp->second).first);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
