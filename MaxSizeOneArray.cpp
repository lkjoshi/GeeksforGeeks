# include<iostream>
using namespace std;

void printArray(int arr[6][5],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void printArrayOne(int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<1<<"\t";
		}
		cout<<"\n";
	}
}

int findMaxOneArray(int arr[6][5],int row,int col)
{
	int temp[row][col];

	for(int i=0;i<row;i++)
		temp[i][0]=arr[i][0];

	for(int i=0;i<col;i++)
		temp[0][i]=arr[0][i];

	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{	
			if(arr[i][j] == 1)
				arr[i][j] = min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1])) + 1;
			else
				arr[i][j] = 0;
		}
	}

int max = arr[0][0];

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(arr[i][j]>max)
				max = arr[i][j];
		}
	}

	return max;
}

int main()
{
	int arr[6][5]={{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

    // printArray(arr,6,5);
    int size = findMaxOneArray(arr,6,5);
    printArrayOne(size);
	return 0;
}
