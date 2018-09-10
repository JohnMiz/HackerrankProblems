node* RotateRR(node* root)
{
     node* temp = root->right;
     root->right = temp->left;
     temp->left = root;
     return temp;
}

node* RotateLL(node* root)
{
     node* temp = root->left;
     root->left = temp->right;
     temp->right = root;
     return temp;
}

node* RotateLR(node* root)
{
     root->left = RotateRR(root->left);
     return RotateLL(root);
}

node* RotateRL(node* root)
{
     node* temp = root->right;
     root->right = RotateLL(root->right);
     return RotateRR(root);
}

int TreeHeight(node* root)
{
     if (root == nullptr)
          return -1;

     int height = 1 + std::max(TreeHeight(root->left), TreeHeight(root->right));
     root->ht = height;
     return height;

}

int BalanceFactor(node* root)
{
     return TreeHeight(root->left) - TreeHeight(root->right);
}

node* BalanceTree(node* root)
{
     int balanceFactor = BalanceFactor(root);
     if (balanceFactor > 1)
     {
          int leftFactor = BalanceFactor(root->left);

          if (leftFactor > 0)
          {
               root = RotateLL(root);
          }
          else
          {
               root = RotateLR(root);
          }

     }
     else if (balanceFactor < -1)
     {
          int rightFactor = BalanceFactor(root->right);

          if (rightFactor > 0)
          {
               root = RotateRL(root);
          }
          else
          {
               root = RotateRR(root);
          }
     }

     return root;
}


node* insert(node* root, int val)
{
    if (root == nullptr)
    {
         node* pNode = new node();
        pNode->val = val;
        pNode->left = nullptr;
        pNode->right = nullptr;
        pNode->ht = TreeHeight(root);
         return pNode;
     }

     if (root->val > val)
     {
          root->left = insert(root->left, val);
          root = BalanceTree(root);
     }

     else if (root->val < val)
     {
          root->right = insert(root->right, val);
          root = BalanceTree(root);
     }

     return root;
}