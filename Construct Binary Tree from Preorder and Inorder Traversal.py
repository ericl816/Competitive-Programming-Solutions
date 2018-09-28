# Definition for a binary tree node.
"""class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""

# Definition for Preorder, Inorder, and Postorder.
"""
Consider a binary tree with 1 as the root: 1 2 4 5 3
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
"""

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Tree
        """
        if len(preorder) == 0: return None
        root_node = TreeNode(preorder[0])
        j = inorder.index(preorder[0])
        root_node.left = self.buildTree(preorder[1:j+1], inorder[0:j])
        root_node.right = self.buildTree(preorder[j+1:], inorder[j+1:])
        return root_node