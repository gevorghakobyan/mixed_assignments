//the program makes a singly linked list of template type T using struct Node 
// and template class list


#include <iostream>


//struct node template consisting from a T template value and Node* pointer to the next node
template <typename T>
struct Node
{
	T m_value;
	Node<T>* m_next;
};


//list class template which has private members -- initial Node* pointer to
// the first node and current size of the list as an integer
// public members -- default constructor, destructor,
//  methods for inserting T values into the specified position of the list
//  current list value displaying method
//  list value remover at the specified position
//  and a T value finder
template <typename T>
class List
{
private:
	Node<T>* m_head;
	int m_list_size;
public:
	List();
	~List();
	void insert(int position, const T& value);
	void display();
	void remove(int position);
	void find(const T& value);
};


// main function
int main()
{

	List<int> l;
	l.insert(0, 1);
	l.insert(0, 2);
	l.display();	

	std::cout << "Change the code inside main() to get desired result." << std::endl;

	return 0;
};


//list class default constructor that sets starting pointer to nullptr and list size to 0
template <typename T>
List<T>::List()
{
	m_head = nullptr;
	m_list_size = 0;
};


//list class destructor that deletes all the pointers inside all the Nodes beginning from the head pointer
template <typename T>
List<T>::~List()
{
//deletes the head pointer if list size is 0
	if (m_list_size == 0)
	{
		delete m_head;
	}
//creates a pair of Node<T>* pointers which delete all the pointers inside the 
//nodes alternately adopting the value of the pointer of the struct pointed by the other pair
	else
	{
		Node<T>* del1 = m_head;
		Node<T>* del2 = del1->m_next;
		while (del1 && del2)
		{
			delete del1;
			del1 = del2->m_next;
			if (del1)
			{
				delete del2;
				del2 = del1->m_next;
			};
		};
		delete del1;
		delete del2;
	};
};


//inserts the given T value at the specified position in the list
template <typename T>
void List<T>::insert(int position, const T& value)
{
	if (position > m_list_size)
	{
		std::cout << "Irrelevant position.";
	}
	else if (position == 0)
	{
		Node<T>* tmp = new Node<T>;
		tmp->m_next = m_head;
		m_head = tmp;
		m_head->m_value = value;
		++m_list_size;
	}
	else 	
	{
		Node<T>* tmp = new Node<T>;
		Node<T>* current = m_head;
		for ( ; position > 1; --position)
		{
			current = current->m_next;
		};
		tmp->m_next = current->m_next;
		current->m_next = tmp;
		current->m_next->m_value = value;
		++m_list_size;
	};
};


//displays all the T values inside the list
template <typename T>
void List<T>::display()
{
	Node<T>* current = m_head;
	while (current)
	{
		std::cout << current->m_value << " ";
		current = current->m_next;
	};
	std::cout << std::endl;
};


//removes the node at the specified position
template <typename T>
void List<T>::remove(int position)
{
	if (position >= m_list_size)
	{
		std::cout << "Irrelevant position." << std::endl;
	}
	else if (position == 0)
	{
		Node<T>* tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
		--m_list_size;
	}
	else
	{
		Node<T>* current = m_head;
		for ( ; position > 1; --position)
		{
			current = current->m_next;
		}
		Node<T>* tmp = current->m_next;
		current->m_next = current->m_next->m_next;
		delete tmp;
		--m_list_size;
	};
};


//finds the node with the specified T value and prints the nodes index
template <typename T>
void List<T>::find(const T& value)
{	
	int position = 0;
	Node<T>* current = m_head;
	while (current != nullptr)
	{
		if (current->m_value == value)
		{
			std::cout << position << std::endl;
			return;
		}
		else
		{
			current = current->m_next;
			++position;
		};
	};
	std::cout << "No such element in the list." << std::endl;
};
