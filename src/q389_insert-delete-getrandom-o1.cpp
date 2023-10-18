#include<unordered_map>
#include<vector>
#include <stdlib.h>     /* srand, rand */

class RandomizedSet {

private:
    std::unordered_map<int, int> mymap;
    std::vector<int> list;

public:
    RandomizedSet() {
        // no need         
    }
    
    bool insert(int val) {
        std::unordered_map<int, int>::const_iterator got = mymap.find (val);
        // if value already exist
        if (got != mymap.end())
        {
            return false;
        }
        else{ // if value does not exist
            mymap[val] = list.size();
            list.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        std::unordered_map<int, int>::const_iterator got = mymap.find (val);
        if (got == mymap.end()){ // if val does not exist
            return false;
        }
        else{
            // *Get the index of the value in the list*
            int index = mymap[val];
            // *Swap the value to be removed with the last value in the list*
            int last_value = list.back();
            //* Replace the value at the given index with the last value*   
            list[index] = last_value;
            //* Remove the last element from the list*
            list.pop_back();
            // *Update the index of the last value in the map to reflect its new position*
            mymap[last_value] = index;
            //* Remove the value from the map*
            mymap.erase(val);
            return true;
        }
        
    }
    
    int getRandom() {
        int randomIndex = std::rand() % list.size();
        return list[randomIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    return 0;
}

//// g++ -std=c++11 -o q389_insert-delete-getrandom-o1.tsk q389_insert-delete-getrandom-o1.cpp