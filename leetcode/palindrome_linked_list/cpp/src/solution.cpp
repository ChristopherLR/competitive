#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    std::vector<int> toVec(ListNode* head){

        std::vector<int> vals;

        ListNode *tmp = head;
        while(tmp != nullptr){
            vals.push_back(tmp->val);
            tmp = tmp->next;
        }

        return vals;
    }
    // Vector Implementation
    // Runtime 271ms, Memory 130MB
    bool isPalindrome(ListNode* head){
        std::vector<int> vals = toVec(head);
        return isPalindrome(vals);
    }

    bool isPalindrome(std::vector<int> vals){
        int size = vals.size();
        if (size == 0) return false;
        if (size == 1) return true;
        for(int i = 0; i < size/2; i++){
            if (vals[i] != vals[size - 1 - i]) return false;
        }
        return true;
    }
};

    // Linked List Implementation
    // Runtime 600ms, Memory 150MB
    // bool isPalindrome(ListNode* head) {
    //     if (head == nullptr) return false;
    //     if (head->next == nullptr) return true;

    //     int length = 1;
    //     ListNode *tmp = head;
    //     ListNode *tail= new ListNode(head->val);
    //     ListNode *new_head = nullptr;

            
    //     tmp = head->next;
    //     while(tmp != nullptr){
    //         length++;
    //         new_head = new ListNode(tmp->val, tail);
    //         tail = new_head;
    //         tmp = tmp->next;
    //     }

    //     tmp = tail;

    //     bool result = true;
    //     for (int i = 0; i < length/2; i++){
    //         if (head->val != tail->val) {
    //             result = false;
    //             break;
    //         }
    //         head = head->next;
    //         tail = tail->next;
    //     }

    //     while(tmp != nullptr){
    //         tail = tmp;
    //         tmp = tmp->next;
    //         delete tail;
    //     }

    //     return result;
    // }