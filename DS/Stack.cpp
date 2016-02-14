# include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;

	node(int number)
	{
		this->data = number;
		this->next = NULL;
	}
};

class Stack {

	node *top;

	public:
	Stack()
	{
		top = NULL;
	}	

	void push(int number)
	{
		if(top == NULL)
		{
			node *n = new node(number);
			top = n;
		}
		else
		{
			node *n = new node(number);
			n->next = top;
			top = n;
		}
	}

	void pop()
	{
		if(top == NULL)
			cout<<"Underflow\n";
		else
		{
			cout<<"Deleting "<<top->data<<"\n";
			node *n = top;
			top=top->next;
			delete(n);
		}
	}

	void printStack()
	{
		if(top == NULL)
			cout<<"Empty Stack\n";
		else
		{
			node *n = top;
			while(n != NULL)
			{	
				cout<<n->data<<"\t";
				n = n->next;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Stack s;
	s.push(3);
	s.push(5);
	s.push(15);
	s.printStack();
	s.pop();
	s.printStack();
	return 0;
}