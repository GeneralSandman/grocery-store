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

        if(leftNode < num && data[leftNode]->val < data[index]->val) {
            swap(data[leftNode], data[index]);
            sinkDown(leftNode);
        }

        if(rightNode < num && data[rightNode]->val < data[index]->val) {
            swap(data[rightNode], data[index]);
            sinkDown(rightNode);
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }

        for(auto list: lists) {
            ListNode* tmp = list;
            while(tmp != nullptr) {
                insert(tmp);

                tmp = tmp->next;
            }
        }

        // for(auto i: data) {
        //     cout << "debug " << i->val << endl;
        // }


        ListNode* head = new ListNode(-1);
        ListNode* pre = head;

        while(hasNext()) {
            ListNode* top = topNode();
            pre->next = top;
            top->next = nullptr;
            pre = top;
        }

        return head->next;
    }
};

int main() {
    Solution s;

    ListNode* l0_0 = new ListNode(1);
    ListNode* l0_1 = new ListNode(4);
    ListNode* l0_2 = new ListNode(5);
    l0_0->next = l0_1;
    l0_1->next = l0_2;

    ListNode* l1_0 = new ListNode(1);
    ListNode* l1_1 = new ListNode(3);
    ListNode* l1_2 = new ListNode(4);
    l1_0->next = l1_1;
    l1_1->next = l1_2;

    ListNode* l2_0 = new ListNode(2);
    ListNode* l2_1 = new ListNode(6);
    l2_0->next = l2_1;

    vector<ListNode*> nums;
    nums.push_back(l0_0);
    nums.push_back(l1_0);
    nums.push_back(l2_0);

    


    ListNode* result = s.mergeKLists(nums);
    while(result != nullptr) {
        cout << result->val << ",";
        result = result->next;
    }

    return 0;
}
