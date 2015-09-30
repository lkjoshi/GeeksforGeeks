# include<iostream>
using namespace std;
struct info{
    int a;
    int b;
    int sum;
};
void Print(int A[],int size);
info Find_Max_SubArray(int A[],int low,int high);
info Find_Max_CrossSubArray(int A[],int low,int mid,int high);

info Find_Max_CrossSubArray(int A[],int low,int mid,int high)
{
    info ob;
    int left_sum=-100;
    int right_sum=-100;
    int sum=0;
    int max_left,max_right;
    for(int i=mid;i>=0;i--)
    {
        sum=sum+A[i];
        if(sum>left_sum)
        {
          left_sum=sum;
            max_left=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum=sum+A[i];
        if(sum>right_sum)
        {
            right_sum=sum;
            max_right=i;
        }
    }
    
    ob.a=max_left;
    ob.b=max_right;
    ob.sum=left_sum+right_sum;
    return ob;
}

info Find_Max_SubArray(int A[],int low,int high)
{
    if(low==high)
    {
        info ob1;
        ob1.a=low;
        ob1.b=high;
        ob1.sum=A[low];
        return ob1;
    }

    else
    {
        info left,right,cross;
        int mid=(low+high)/2;
        left=Find_Max_SubArray(A,low,mid);
        right=Find_Max_SubArray(A,mid+1,high);
        cross=Find_Max_CrossSubArray(A,low,mid,high);
        
        if(left.sum>=right.sum&&left.sum>=cross.sum)
            return left;
        else if(right.sum>=left.sum&&right.sum>=cross.sum)
            return right;
        else
            return cross;
    }
    
}


void Print(int A[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<"\n";
}
int main()
{
    int A[20],n;
    cout<<"\n Enter the size of array : ";
    cin>>n;
    cout<<"\n Enter the elements";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    Print(A,n);
    info ob=Find_Max_SubArray(A,0,n-1);
    cout<<"\nMax sum subarray starts from "<<ob.a<<" and ends at "<<ob.b<<" with sum "<<ob.sum<<"\n";
    return 0;
}