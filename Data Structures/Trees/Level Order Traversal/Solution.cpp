    
	void levelOrder(Node * root)
    {
        queue<Node*> q;

               if(root != nullptr)
         q.push(root);
             
        while(!q.empty())
        {
            Node* node = q.front();
            std::cout << node->data << " ";
            q.pop();
            if(node->left != nullptr)
                q.push(node->left);
            if(node->right != nullptr)
                q.push(node->right);
                
        }
    }