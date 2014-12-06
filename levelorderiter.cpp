void levelorder(node* root)
{
	if(root==NULL)
		return;
	queue <node*> q;
	node *temp;
	q.push(root);
	int count;
	while(1)
	{
		count=q.size();
		if(count==0)
			break;
		while(count>0)
		{
			temp = q.front();
			cout<< temp->data<<" ";
			q.pop();
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
			count--;
		}
		cout<<endl;
	}
}
