//The index denote the object and their value denote the ids
//Agile Approach
//Union - O(N)
//Find - O(1)

# include<iostream>
# include<stdlib>
using namespace std;

void print(int *arr,int n) {

	cout<<"\nIndex : ";
	for(int i=0;i<n;i++) {
		cout<<i<<"\t";
	}
	cout<<"\nValue : ";
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<"\t";
	}
}

void initialize(int *arr,int n) {
	for(int i=0;i<n;i++) {
		arr[i] = i;
	}
}

void quickunion(int *arr,int n,int p,int q) {
	if(p>n || q>n)
	 {
	 	cout<<" Invalid ";
		return;		
	 }

	 int id = arr[q];

	 for(int i=0;i<n;i++)
	  {
	  	 if(arr[i] == id)
	  	  {
	  	  	 arr[i] = arr[p];
	  	  }
	  }

}

bool isConnected(int *arr,int n,int p,int q) {

	if(arr[p] == arr[q])
	{
		return true;
	}
	else
	{
		return false;
	}
}



int main(int argc, char const *argv[])
{
	int n = 10;

	int *arr = new int[n]; // Dynamically creating an array

	initialize(arr,n);

	print(arr,n);

	quickunion(arr,n,3,4);

	cout<<"\n"<<isConnected(arr,n,5,4);
	
	return 0;
}