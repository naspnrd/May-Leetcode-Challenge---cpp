Construct Binary Search Tree from Preorder Traversal - 1008

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

    1 <= preorder.length <= 100
    1 <= preorder[i] <= 10^8
    The values of preorder are distinct.


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
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return build_Tree(preorder,0,preorder.size()-1);
    }
    
    TreeNode* build_Tree(vector<int>& preorder , int l , int r) {
        if(l > r)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[l]);
        if(l == r)
            return root;
        
        int idx= l+1;
        while(idx <= r && preorder[idx] < preorder[l])
            idx++;
        
        root->left = build_Tree(preorder , l+1 , idx-1) ;
        root->right = build_Tree(preorder , idx , r) ;
        return root;
    }
};