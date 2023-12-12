#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using std::vector;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        std::set<std::pair<int, int>> visited;

        std::priority_queue<std::pair<int, std::pair<int, int>>, vector<std::pair<int, std::pair<int, int>>>,
                       std::greater<std::pair<int, std::pair<int, int>>>> minHeap;
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<vector<int>> rslt; 
       std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        // Priority queue to store pairs with smallest sums, sorted by the sum
        for (int i=0; i<std::min(k,(int)nums1.size());i++) {
            // the sum and the index of the second element in nums2.
            pq.push({nums1[i]+nums2[0], 0}) ;
        }

        // pop the k smallest pairs from the priority queue
        while (k>0 && !pq.empty()) {
            int sum = pq.top().first;
            int idx = pq.top().second;

            rslt.push_back({sum-nums2[idx], nums2[idx]});
            pq.pop(); 

            //if there are more element in the nums2, push the next pair into the pq
            if (idx+1<nums2.size()) {
                pq.push({sum - nums2[idx] + nums2[idx + 1], idx + 1});
            }
            k--;
        }
        return rslt;
    }
};