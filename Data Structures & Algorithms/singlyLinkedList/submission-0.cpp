#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        if (index < 0 || head == nullptr) {
            return -1;
        }
        
        ListNode* curr = head;
        int i = 0;
        
        while (curr != nullptr && i < index) {
            curr = curr->next;
            i++;
        }
        
        if (curr == nullptr) return -1;
        return curr->val;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;  
        
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(int index) {
        if (head == nullptr) return false;
        
        if (index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            
            if (head == nullptr) {
                tail = nullptr;
            }
            
            delete toDelete;
            return true;
        }
        
        ListNode* curr = head;
        int i = 0;
        
        while (curr != nullptr && i < index - 1) {
            curr = curr->next;
            i++;
        }
        
        if (curr == nullptr || curr->next == nullptr) {
            return false;
        }
        
        ListNode* toDelete = curr->next;
        curr->next = toDelete->next;
        
        if (toDelete == tail) {
            tail = curr;
        }
        
        delete toDelete;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head;  
        
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};