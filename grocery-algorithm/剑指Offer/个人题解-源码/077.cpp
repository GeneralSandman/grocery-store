#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    vector<ListNode*> data;
    int num = 0;

    void floatUp(int index) {
        int parent = (index - 1) / 2;
        if (parent < 0) {
            return;
        }

        if(data[parent]->val > data[index]->val) {
            swap(data[parent], data[index]);
            floatUp(parent);
        }
    }

    void sinkDown(int index) {
        int leftNode = index * 2 + 1;
        int rightNode = index * 2 + 2;


        int sonNode;

        if(leftNode >= num) {
            return;
        }

        sonNode = leftNode;

        // 选一个子节点递归就可以，没必要两个子节点都要递归
        if(rightNode < num && data[leftNode]->val > data[rightNode]->val) {
            sonNode = rightNode;
        }


        if(data[sonNode]->val < data[index]->val) {
            swap(data[sonNode], data[index]);
            sinkDown(sonNode);
        }

    }

    void insert(ListNode* node) {
        data.push_back(node);
        num += 1;
        floatUp(data.size()-1);
    }

    bool hasNext() {
        return num > 0;
    }

    ListNode* topNode() {
        ListNode* tmp = data[0];
        swap(data[0], data[num-1]);
        num -= 1;

        sinkDown(0);
        return tmp;
    }

public:
    // 使用堆来排序
    // 最小堆
    // 升序
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }

        while(head != nullptr) {
            insert(head);
            head = head->next;
        }

        ListNode* result = new ListNode(-1);
        ListNode* pre = result;

        while(hasNext()) {
            ListNode* top = topNode();
            pre->next = top;
            top->next = nullptr;
            pre = top;
        }

        return result->next;
    }
};

int main() {
    Solution s;

    ListNode* l0_0 = new ListNode(5);
    ListNode* l0_1 = new ListNode(4);
    ListNode* l0_2 = new ListNode(1);
    l0_0->next = l0_1;
    l0_1->next = l0_2;

    

    ListNode* result = s.sortList(l0_0);
    while(result != nullptr) {
        cout << result->val << ",";
        result = result->next;
    }

    return 0;
}
