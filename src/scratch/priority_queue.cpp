#include <iostream>
#include <queue>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main() {
    auto cmp = [](ListNode* left, ListNode* right) { 
        return left->val < right->val; };
    
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(0);
    ListNode node3 = ListNode(2);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);
    ListNode node6 = ListNode(3);

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

    pq.push(&node1);
    pq.push(&node2);
    pq.push(&node3);
    pq.push(&node4);
    pq.push(&node5);
    pq.push(&node6);

    while(!pq.empty()) {
        std::cout<< pq.top()->val <<std::endl;
        pq.pop();
    }
}

// g++ -std=c++11 -o q23_merge-k-sorted-lists q23_merge-k-sorted-lists.cpp

