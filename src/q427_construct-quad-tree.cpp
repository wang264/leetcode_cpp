
#include<vector>

using std::vector;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
    
    bool sameValue(vector<vector<int>>& grid, int x, int y, int size) {
      for (int i=x; i<x+size; i++) {
        for (int j=y; j<y+size; j++) {
          if (grid[x][y]!=grid[i][j]) {
            return false;
          }
        }
      }
      return true;
    }

    Node* helper(vector<vector<int>>& grid, int x, int y, int size) {
      if (sameValue(grid, x, y, size)) {
        return new Node(grid[x][y], true);
      } else {
        Node* node = new Node(false, false);

        node->topLeft = helper(grid, x, y, size/2);
        node->topRight = helper(grid, x, y+size/2, size/2);
        node->bottomLeft = helper(grid, x+size/2, y, size/2);
        node->bottomRight = helper(grid, x+size/2, y+size/2, size/2);
        return node;
      }
    }
};