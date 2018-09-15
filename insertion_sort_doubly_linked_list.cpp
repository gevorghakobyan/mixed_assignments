/* the program defines doubly linked list class using struct containing an
 *  integer value and two pointers to the previous and next list elements.
 *   the class has a function that sorts the values contained in the nodes
 *    using insertion sort.*/

#include <iostream>

struct Node
{
	int value;
	Node* prev;
	Node* next;
};

class doubleLL
{
private:
	Node* head;
	void push_back(Node* cur, int & input);
public:
	doubleLL();
	~doubleLL();
	void push(int input, int index = -1);
	void display();
	void sort();
};


//main function ================================================

int main()
{
	int a = -9;
	doubleLL dl;
	dl.push(5);
	dl.push(3);
	dl.push(-9);
	dl.push(4);
	dl.push(13);
	dl.push(0);
	dl.push(4, 1);
	dl.display();
	dl.sort();
	dl.display();
	return 0;
};


// implementations =================================================

doubleLL::doubleLL()
{
	head = nullptr;
};

doubleLL::~doubleLL()
{
	if (head != nullptr)
	{
		while (head->next != nullptr)
		{
			delete head->prev;
			head = head->next;
			delete head->prev->next;
		};
		delete head->prev;
		delete head;
	};
};

void doubleLL::push(int input, int index)
{
	if (head == nullptr)
	{
		head = new Node;
		head->value = input;
		head->next = nullptr;
		head->prev = nullptr;
	}
	else if (index < 0)
	{
		
			Node* cur = head;
			while (cur->next != nullptr)
			{
				cur = cur->next;
			};
			push_back(cur, input);
	}
	else
	{
		if (index == 0)
		{
			head->prev = new Node;
			head->prev->next = head;
			head = head->prev;
			head->prev = nullptr;
			head->value = input;
		}
		else
		{
			Node* cur = head;
			while (index > 1)
			{
				if (cur->next != nullptr)
				{
					cur = cur->next;
					--index;
				}
					else
				{
					break;
				};
			};
			if (cur->next == nullptr)
			{
				push_back(cur, input);
			}
			else
			{
				cur->next->prev = new Node;
				cur->next->prev->next = cur->next;
				cur->next = cur->next->prev;
				cur->next->prev = cur;
				cur->next->value = input;
			};
		};
	};
};

void doubleLL::push_back(Node* cur, int & input)
{
	cur->next = new Node;
	cur->next->value = input;
	cur->next->next = nullptr;
	cur->next->prev = cur;
};

void doubleLL::display()
{
	if (head != nullptr)
	{
		Node* cur = head;
		while (cur != nullptr)
		{
			std::cout << cur->value << " ";
			cur = cur->next;
		};
		std::cout << std::endl;
	};
};

void doubleLL::sort()
{
	if (head != nullptr)
	{
		Node* cur = head;
		Node* runner;
		int temp = 0;
		while (cur->next != nullptr)
		{
			cur = cur->next;
			runner = cur->prev;
			temp = cur->value;
			if (temp < runner->value)
			{
				while (temp < runner->value)
				{
					runner->next->value = runner->value;
					if (runner->prev == nullptr)
					{
						runner->value = temp;
						break;
					};
					runner = runner->prev;
					runner->next->value = temp;
				};
			};
			display();
		};
	};
};
