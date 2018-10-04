void PreOrder(Node *root)
{
	std::cout << root->data << " ";
	
	if(root->left != NULL)
		inOrder(root->left);
	
	if(root->right != NULL)
		inOrder(root->right);
}