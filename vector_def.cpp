#include "vector.h"

Vector::Vector()
{
	m_arr_len = 10;
	m_arr = new int [m_arr_len];
	m_size = 0;
};

Vector::~Vector()
{
	delete [] m_arr;
	m_arr = nullptr;
};

Vector::Vector(Vector const & src)
{
	m_arr_len = src.m_arr_len;
	m_size = src.m_size;
	m_arr = new int [m_arr_len];
	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = src.m_arr[i];
	};
};

void Vector::push_back(int elem)
{
	if (m_size == m_arr_len)
	{
		m_arr_len += 10;
		int * new_arr = new int [m_arr_len];
		for (int i = 0; i < m_size; ++i)
		{
			new_arr[i] = m_arr[i];
		};
		delete [] m_arr;
		m_arr = new_arr;
	};
	m_arr[m_size] = elem;
	++m_size;
};

void Vector::insert_at(int index, int elem)
{
	if (m_size == m_arr_len)
	{
		m_arr_len += 10;
		int * new_arr = new int [m_arr_len];
		for (int i = 0; i < index; ++i)
		{
			new_arr[i] = m_arr[i];
		};
		new_arr[index] = elem;
		for (int i = index + 1; i <= m_size; ++i)
		{
			new_arr[i] = m_arr[i - 1];
		};
		delete [] m_arr;
		m_arr = new_arr;
	}
	else
	{
		for (int i = m_size; i > index; --i)
		{
			m_arr[i] = m_arr[i - 1];
		};
		m_arr[index] = elem;
	};
	++m_size;
};


int Vector::get_at(int index)
{
	return m_arr[index];
};

int Vector::get_size()
{
	return m_size;
};
