#include <iostream>


//smart pointer class template
template <typename T>
class SmartPointer
{
	public:
		T* _Tp = nullptr;
		SmartPointer();
		~SmartPointer();
		T& operator*();	
		T* operator->();
};


int main()
{
//creates a smart pointer named ssp (Some Smart Pointer)
	SmartPointer<int> ssp;
//sets the value pointed by the pointer to 7
	*ssp = 7;
//prints the value pointed by the pointer
	std::cout << *ssp << std::endl;
	return 0;
}

//smart pointer constructor -- creates a smart pointer of a specified type
template <typename T>
SmartPointer<T>::SmartPointer()
{
	_Tp = new T;
};

//smart pointer destructor -- frees pointers space and sets it to a nullpointer
template <typename T>
SmartPointer<T>::~SmartPointer()
{
	delete _Tp;
	_Tp = nullptr;
};

// * operator overloading for the smart pointer
template <typename T>
T& SmartPointer<T>::operator*()
{
	return *_Tp;
};


// -> operator overloading for the smart pointer
template <typename T>
T* SmartPointer<T>::operator->()
{
	return _Tp;
}	
