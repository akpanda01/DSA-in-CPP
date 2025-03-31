class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return NULL;
        
        vector<vector<Node*>> nodes(n, vector<Node*>(n, NULL));
        
        // Create nodes for each cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodes[i][j] = new Node(mat[i][j]);
            }
        }
        
        // Link nodes to their right and down neighbors
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    nodes[i][j]->right = nodes[i][j + 1];
                }
                if (i + 1 < n) {
                    nodes[i][j]->down = nodes[i + 1][j];
                }
            }
        }
        
        // Return the head (top-left corner)
        return nodes[0][0];
    }
};
