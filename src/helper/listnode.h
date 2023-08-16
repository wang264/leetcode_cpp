
#include <vector>
#include <iostream>
#include <ostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    static ListNode* buildList(std::vector<int> vec)
    {   
        ListNode dummy = ListNode(-1);
        ListNode *prev_ptr = &dummy;
        for (const int& x : vec)
        {
            ListNode *node = new ListNode(x);
            prev_ptr->next = node;
            prev_ptr = prev_ptr->next;

        }

        return dummy.next;
    }
    static void print( ListNode *node ) {
        auto *curr_ptr = node; 
        std::cout<<"[ ";
        while (curr_ptr!=nullptr)
        {
            std::cout<<curr_ptr->val<<", ";
            curr_ptr = curr_ptr->next;
        }
        std::cout << " ]"<<std::endl;
    }

};

