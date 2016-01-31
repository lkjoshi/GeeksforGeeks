# include<iostream>
using namespace std;

void initialize(int *arr,int size) {
	for(int i=0;i<size;i++)
	{
		arr[i] = i;
	}
}

void initializeSize(int *arr,int size) {
	for(int i=0;i<size;i++)
	{
		arr[i] = 1;
	}
}

void print(int *arr,int size) {
	cout<<"\nObjects :";
	for(int i=0;i<size;i++)
		cout<<i<<"\t";
	cout<<"\nParents :";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"\t";
}

int findParent(int *arr,int size,int child)
{
	while(arr[child] != child)
	{
		arr[child] = arr[arr[child]];  // Path minimization
		child = arr[child];
	}
	return child;
}

int sizeOfParent(int *arr,int node)
{
	return arr[node];
}

void quickUnion(int *arr,int *treesize,int size,int p,int q) {

	int p_parent = findParent(arr,size,p);
	int q_parent = findParent(arr,size,q);

	if(p_parent == q_parent)
		return;

	if(treesize[p_parent] < treesize[q_parent])
	{
		arr[p_parent] = q_parent;
		treesize[q_parent] += treesize[p_parent];
	}
	else
	{
		arr[q_parent] = p_parent;
		treesize[p_parent] += treesize[q_parent];
	}
}

int main(int argc, char const *argv[])
{
	int n = 10;
	int *arr = new int[n];
	int *treesize = new int[n];

	initializeSize(treesize,n);
	initialize(arr,n);
	
	quickUnion(arr,treesize,n,4,3);
	quickUnion(arr,treesize,n,3,8);
	quickUnion(arr,treesize,n,9,4);
	quickUnion(arr,treesize,n,6,5);
	quickUnion(arr,treesize,n,2,1);
	quickUnion(arr,treesize,n,5,0);
	print(arr,n);
	print(treesize,n);
	return 0;
}