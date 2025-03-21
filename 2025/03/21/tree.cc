#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
   TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode *root) {
   if (root == nullptr) {
      return;
   }
   stack<pair<TreeNode*, bool>> stk;
   stk.push({root, false});

   while (!stk.empty()) {
      auto [curr, isvisited] = stk.top();
      stk.pop();

      if (curr == nullptr) continue;
      if (!isvisited) {
         // root, left, right
         stk.push({curr->right, false});
         stk.push({curr->left, false});
         stk.push({curr, true});
      } else {
         cout << curr->val << " ";
      }
   }
}

unordered_map<int, int> umap; // inorder_elem, index

struct TreeNode* helper(vector<int> &pre, int plow, int phigh, vector<int> &in, int ilow, int ihigh) {
   if (plow > phigh || ilow > ihigh) {
      return nullptr;
   }
   int rootVal = pre[plow];
   int rootPos = umap[rootVal];
   struct TreeNode *root = new TreeNode(rootVal);
   root->left = helper(pre, plow+1, plow+rootPos-ilow, in, ilow, rootPos-1);
   root->right = helper(pre, plow+rootPos-ilow+1, phigh, in, rootPos+1, ihigh);
   return root;
}

struct TreeNode* makeTree(vector<int> preOrder, vector<int> inOrder) {
   for (int i = 0; i < inOrder.size(); i++) {
      umap[inOrder[i]] = i;
   }
   return helper(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
}

int main() {
   struct TreeNode *root = makeTree({1,2,4,5,3,6}, {4,2,5,1,6,3});
   preOrder(root);
   return 0;
}
