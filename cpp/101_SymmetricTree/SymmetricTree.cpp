/*
	[Easy] 101.Symmetric Tree
	---------------------------------------------------------------------------------------------------------------------------------------------
	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
		    1
		   / \
		  2   2
		 / \ / \
		3  4 4  3


	But the following [1,2,2,null,3,null,3] is not:
		    1
		   / \
		  2   2
		   \   \
		   3    3
	---------------------------------------------------------------------------------------------------------------------------------------------
 */


 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

class Solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		else if (!root->left && !root->right)
			return true;
		else if (!root->left)
			return false;
		else if (!root->right)
			return false;

		vector<TreeNode*> leftSubTree;
		vector<TreeNode*> rightSubTree;
		leftSubTree.reserve(400);
		rightSubTree.reserve(400);

		TraversingPreOrder(root->left, leftSubTree);
		TraversingReverseOrder(root->right, rightSubTree);

		auto size = leftSubTree.size();
		if (size != rightSubTree.size())
		{
			return false;
		}

		for (auto i = 0; i != size; ++i)
		{
			if (!leftSubTree[i] && !rightSubTree[i])
			{
				continue;
			}
			else if ((!leftSubTree[i] || !rightSubTree[i]) || (leftSubTree[i]->val != rightSubTree[i]->val))
			{
				return false;
			}
		}

		return true;
	}

	// root-left-right
	void TraversingPreOrder(TreeNode* start, vector<TreeNode*>& leftSubTree)
	{
		if (start)
		{
			leftSubTree.push_back(start);
			TraversingPreOrder(start->left, leftSubTree);
			TraversingPreOrder(start->right, leftSubTree);
		}
		else
		{
			leftSubTree.push_back(nullptr);
		}
	}

	// root-right-left
	void TraversingReverseOrder(TreeNode* start, vector<TreeNode*>& rightSubTree)
	{
		if (start)
		{
			rightSubTree.push_back(start);
			TraversingReverseOrder(start->right, rightSubTree);
			TraversingReverseOrder(start->left, rightSubTree);
		}
		else
		{
			rightSubTree.push_back(nullptr);
		}
	}
};
