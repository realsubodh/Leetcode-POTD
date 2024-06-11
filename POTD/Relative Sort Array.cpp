class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  unordered_map<int, int> indexMap;
    for (int i = 0; i < arr2.size(); ++i) {
        indexMap[arr2[i]] = i;
    }

    // Partition arr1 into two parts
    vector<int> part1;
    vector<int> part2;
    
    for (int num : arr1) {
        if (indexMap.find(num) != indexMap.end()) {
            part1.push_back(num);
        } else {
            part2.push_back(num);
        }
    }

    // Sort part1 based on their order in arr2 using indexMap
    sort(part1.begin(), part1.end(), [&indexMap](int a, int b) {
        return indexMap[a] < indexMap[b];
    });

    // Sort part2 in ascending order
    sort(part2.begin(), part2.end());

    // Combine the sorted parts
    part1.insert(part1.end(), part2.begin(), part2.end());
    
    return part1;
}
};
