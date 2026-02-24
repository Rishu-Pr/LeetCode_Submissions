class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<int> max_Heap;

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_Heap.push(matrix[i][j]);

                if (max_Heap.size() > k) max_Heap.pop();
            }
        }
        return max_Heap.top();
    }
};