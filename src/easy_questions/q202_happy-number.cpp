#include <unordered_set>

#using std::unordered_set;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n!=1 && visited.count(n)==0) {
            visited.insert(n);
            n = getNextInt(n);
        }
        return n==1;
    }

    int getNextInt(int n) {
        int sum = 0;
        while (n>0) {
            int digit = n%10;
            n = n/10;
            sum += digit*digit;
        }
        return sum;

    }   

};

class Solution2 {
    //Floyd's Cycle-Finding Algorithm
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNextInt(n);

        while (fast!=1 && slow!=fast) {
            slow = getNextInt(slow);
            fast = getNextInt(getNextInt(fast));
        }
        return fast==1;
    }

    int getNextInt(int n) {
        int sum = 0;
        while (n>0) {
            int digit = n%10;
            n = n/10;
            sum += digit*digit;
        }
        return sum;

    }   

};