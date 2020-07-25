#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool _VerifySquenceOfBST(vector<int> sequence, int start, int end) {
		if (start > end)
			return true;
		int root = sequence[end];
		int i = start;
		while (i <= end && sequence[i] < root) {
			i++;
		}
		for (int j = i; j < end; j++) {
			if (sequence[j] < root)
				return false;
		}
		return _VerifySquenceOfBST(sequence, start, i - 1) && _VerifySquenceOfBST(sequence, i + 1, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
	}
};

class Solution {
public:
	void FindPathDfs(TreeNode* root, int expectNumber, vector<vector<int>>& result, vector<int>& list) {
		if (root == nullptr)
			return;
		list.push_back(root->val);
		expectNumber -= root->val;
		if (root->left == nullptr && root->right == nullptr && expectNumber == 0) {
			result.push_back(list);
		}
		FindPathDfs(root->left, expectNumber, result, list);
		FindPathDfs(root->right, expectNumber, result, list);
		list.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> result;
		vector<int> list;
		FindPathDfs(root, expectNumber, result, list);
		return result;
	}
};
