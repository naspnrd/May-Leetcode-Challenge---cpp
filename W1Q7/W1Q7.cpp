Cousins in Binary Tree - 993

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

 

Constraints:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.

   code:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//DFS solution
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int px=0;
        int py=0;
        int dx=-1;
        int dy=-1;
        
        depth(root,x,y,0,dx,dy,px,py);
        return ((dx == dy) && (px != py));
        
    }
    void depth(TreeNode* root,int x,int y,int d,int &dx,int &dy,int &px,int &py)
    {
        if(!root) return;
        
        //traverse left part
        
        if(root->left)
        {
            if(root->left->val ==x)
            {
            dx=d+1;
            px=root->val;
            }
            else if(root->left->val ==y)
            {
                py=root->val;
                dy = d+1;
            }
        }
        //traverse right part
        
        if(root->right)
        {
            if(root->right->val ==x)
            {
            dx=d+1;
            px=root->val;
            }
            else if(root->right->val ==y)
            {
                py=root->val;
                dy = d+1;
            }
        }
        //if both values we can got we no need to go further
        if(dx!=-1 && dy!=-1)
            return;
        //d=d+1 becuse we are traversing its children now
         depth(root->left,x,y,d+1,dx,dy,px,py);
         depth(root->right,x,y,d+1,dx,dy,px,py);
    }
};