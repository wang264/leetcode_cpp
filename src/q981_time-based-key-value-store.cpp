#include<unordered_map>
#include<map>
#include<string>

using std::string;
class TimeMap {
public:
    std::unordered_map<string, std::map<int, string>> keyTimeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // If the key does not exist in the map we will return empty string
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        // So, we will find the upper_bound of the given timestamp, upper_bound function 
        // returns an iterator pointing to the first element that is greater than the searched value.
        //  Thus, the left element of the iterator will be equal to or just smaller than the 
        // searched value.
        auto iter = keyTimeMap[key].upper_bound(timestamp);
        // If iterator points to first element it means, no time <= timestamp exists.
        if (iter==keyTimeMap[key].begin()) {
            return "";
        } 
        // Return value stored at previous position of current iterator.
        return std::prev(iter)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */