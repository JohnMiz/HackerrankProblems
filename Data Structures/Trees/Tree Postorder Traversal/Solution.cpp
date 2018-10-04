void PostOrder(Node *root)
{
	
	if(root->left != NULL)
		inOrder(root->left);
	
	if(root->right != NULL)
		inOrder(root->right);
	
	std::cout << root->data << " ";
	
}