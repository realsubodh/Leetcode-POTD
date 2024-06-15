class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    // Vector of pairs to store capital and profit together
        vector<pair<int, int>> projects;
        int n = profits.size();
        
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Sort projects by the capital required to start them
        sort(projects.begin(), projects.end());
        
        // Max-heap to keep track of the most profitable projects we can start
        priority_queue<int> maxProfitHeap;
        
        int i = 0;
        while (k--) {
            // Add all projects that can be started with the current capital to the max-heap
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }
            
            // If the max-heap is empty, we can't start any more projects
            if (maxProfitHeap.empty()) {
                break;
            }
            
            // Start the most profitable project
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};
