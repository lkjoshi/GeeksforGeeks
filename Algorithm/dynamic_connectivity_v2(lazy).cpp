//The index denote the object and their value denote the Parent
//Lazy Approach
//Union - O(N) -- faster than previous version -- only one element is affected
//Find - O(N)-- tree can grow very tall 

// ** Quick Union

# include<iostream>
using namespace std;

void print(int *arr,int size) {
	cout<<"\nObject : ";
	for(int i=0;i<size;i++) {
		cout<<i<<"\t";
	}
	cout<<"\nParent : ";
	for(int i=0;i<size;i++) {
		cout<<arr[i]<<"\t";
	}
}

void initialize(int *arr,int size) {
	for(int i=0;i<size;i++) {
		arr[i] = i;
	}
}

int findRoot(int *arr,int size,int child) {

	while( arr[child] != child )
	 {
	 	child = arr[child];
	 }
	return child;
}

void quickunion(int *arr,int n,int p,int q) {

	int p_parent = findRoot(arr,n,p);
	int q_parent = findRoot(arr,n,q);

	arr[q] = p_parent;
}

bool isConnected(int *arr,int n,int p,int q) {
	if(findRoot(arr,n,p) == findRoot(arr,n,q))
		return true;
	else
		return false;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	int *arr = new int[n];

	initialize(arr,n);

	quickunion(arr,n,3,4);

	quickunion(arr,n,5,6);

	quickunion(arr,n,3,5);

	cout<<"\n"<<isConnected(arr,n,5,4);

	print(arr,n);
	return 0;
}
