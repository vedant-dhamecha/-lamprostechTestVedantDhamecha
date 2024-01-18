//Vedant Dhamecha-BVM 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm> //reverse function k liye

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // unordered_map use kiya each element kitni baar aa rha hai
    unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // min heap me repetation store kiya
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Iterate kiya the frequencyMap and elements add kiye min heap me
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        minHeap.push({it->second, it->first});
        //size of the heap <= k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // top k frequent elements ko min heap se nikala
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    //Reverse kiya result ko descending order k liye
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> nums = {5, 2, 5, 3, 5, 3, 1};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
