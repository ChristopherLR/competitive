#include <catch2/catch_test_macros.hpp>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    // Runtime: 0ms, Memory: 7.1MB
    ListNode* middleNode(ListNode* head){
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* slow = head->next;
        ListNode* fast = slow->next;

        while (fast != nullptr){
            if (fast->next){
                slow = slow->next;
                fast = fast->next->next;
            } else {
                fast = nullptr;
            }
        }

        return slow;
    }
};

TEST_CASE("T1"){

    ListNode _1, _2, _3, _4;

    _1 = { 1, &_2 };
    _2 = { 2, &_3 };
    _3 = { 3, &_4 };
    _4 = { 4, nullptr };

    Solution sol;
    REQUIRE(sol.middleNode(&_1) == &_3);
};

TEST_CASE("T2"){

    ListNode _1, _2, _3, _4, _5;

    _1 = { 1, &_2 };
    _2 = { 2, &_3 };
    _3 = { 3, &_4 };
    _4 = { 4, &_5 }; 
    _5 = { 4, nullptr };

    Solution sol;
    REQUIRE(sol.middleNode(&_1) == &_3);
};
