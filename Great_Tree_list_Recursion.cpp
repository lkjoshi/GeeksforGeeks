# include<iostream>
using namespace std;
class Tree{
		public:
			int value;
			Tree* left;
			Tree* right;
			Tree(int n)
			{
				value=n;
				left=NULL;
				right=NULL;
			}
};
Tree* Append(Tree** start1,Tree** start2);

void Print_as_List(Tree* start)
{
	Tree* ptr=start;
	do{
		cout<<ptr->value<<"\t";
		ptr=ptr->right;
	}while(start!=ptr);
	cout<<"\n";
}
void Inorder(Tree* root)
{
	if(root==NULL)
		return;
	else
	{
		Inorder(root->left);
		cout<<root->value<<"\t";
		Inorder(root->right);
	}
}
Tree* Tree_to_List(Tree* root)
{
	if(root==NULL)
		return NULL;
	Tree* left_half=Tree_to_List(root->left);
	Tree* right_half=Tree_to_List(root->right);
	root->left=root;
	root->right=root;
	left_half=Append(&left_half,&root);
	left_half=Append(&left_half,&right_half);

	return left_half;
}
Tree* Append(Tree** start1,Tree** start2)
{
	if(*start1==NULL)
		return *start2;
	if(*start2==NULL)
		return *start1;

	Tree* ptr1=(*start1)->left;
	Tree* ptr2=(*start2)->left;

	(*start1)->left=ptr2;
	ptr2->right=*start1;
	ptr1->right=*start2;
	(*start2)->left=ptr1;
	return *start1;
}
int main()
{
	/*	1
	  /   \
	 2 	   3
   /  \   /
  4    5 6 */
	Tree* n1=new Tree(1);
	Tree* n2=new Tree(2);
	Tree* n3=new Tree(3);
	Tree* n4=new Tree(4);
	Tree* n5=new Tree(5);
	Tree* n6=new Tree(6);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;

	Inorder(n1);
	Tree_to_List(n1);
	cout<<"\n";
	Print_as_List(n1);
	return 0;
}