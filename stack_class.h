#ifndef STACK_H_
#define STACK_H_

class Stack
{
	private:
		int * arr;
		int size;
		int top;
	public:
		Stack();
		~Stack();
		void push(int num);
		void pop();
};

#endif
