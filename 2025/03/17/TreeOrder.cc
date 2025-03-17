/**
  Definition for a binary tree node.
  */
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**********    风格统一的迭代遍历    **********/

// 第一遍先入栈（定义顺序），第二遍访问才真正处理（visited = true）
// 利用栈后进先出的特点，自定义遍历顺序, 而整体框架不变

vector<int> preorderTraversal(TreeNode* root) {
   if (root == nullptr) {
      return {};
   }

   vector<int> res;
   stack<pair<TreeNode*, bool>> stk;
   stk.emplace(root, false);

   while (!stk.empty()) {
      auto [node, visited] = stk.top();
      stk.pop();

      if (!node) continue;
      if (visited) {
         res.push_back(node->val);
      } else {
         // **前序遍历顺序：根 -> 左 -> 右**
         stk.emplace(node->right, false);
         stk.emplace(node->left, false);
         stk.emplace(node, true);  // 访问根节点
      }
   }
   return res;
}

vector<int> inorderTraversal(TreeNode* root) {
   if (root == nullptr) {
      return {};
   }

   vector<int> res;
   stack<pair<TreeNode*, bool>> stk;
   stk.emplace(root, false);

   while (!stk.empty()) {
      auto [node, visited] = stk.top();
      stk.pop();

      if (!node) continue;
      if (visited) {
         res.push_back(node->val);
      } else {
         // **中序遍历顺序：左 -> 根 -> 右**
         stk.emplace(node->right, false);
         stk.emplace(node, true);  // 访问根节点
         stk.emplace(node->left, false);
      }
   }
   return res;
}

vector<int> postorderTraversal(TreeNode* root) {
   if (root == nullptr) {
      return {};
   }

   vector<int> res;
   stack<pair<TreeNode*, bool>> stk;
   stk.emplace(root, false);

   while (!stk.empty()) {
      auto [node, visited] = stk.top();
      stk.pop();

      if (!node) continue;
      if (visited) {
         res.push_back(node->val);
      } else {
         // **后序遍历顺序：左 -> 右 -> 根**
         stk.emplace(node, true);  // 访问根节点
         stk.emplace(node->right, false);
         stk.emplace(node->left, false);
      }
   }
   return res;
}

/**********    目前比较熟悉的遍历方式，没有后序迭代   **********/

vector<int> preorderTraversal(TreeNode *root) {
   if (root == nullptr) {
      return {};
   }

   vector<int> ret;
   stack<TreeNode*> stk;
   while (root || !stk.empty()) {
      while (root) { // 深入左子树
         ret.emplace_back(root->val); // 第一次遇到就访问
         stk.emplace(root);
         root = root->left;
      }
      root = stk.top();
      stk.pop();
      root = root->right;
   }
   return ret;
}

vector<int> inorderTraversal(TreeNode *root) {
   if (root == nullptr) {
      return {};
   }

   vector<int> ret;
   stack<TreeNode*> stk;
   while (root || !stk.empty()) {
      while (root) { // 深入左子树，但不访问
         stk.emplace(root);
         root = root->left;
      }
      root = stk.top();
      stk.pop();
      ret.emplace_back(root->val); // 这里才访问
      root = root->right;
   }
   return ret;
}
