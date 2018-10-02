    int height(Node* root)
	{
        // Write your code here.
        
        if(root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        
        int heightLeft = 0;
        if(root->left != nullptr)
        {
            heightLeft = height(root->left);    
        }
        
        int heightRight = 0;
        if(root->right != nullptr)
        {
            heightRight = height(root->right);    
        }
        
        return std::max(heightLeft, heightRight) + 1;
    }