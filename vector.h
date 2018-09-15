#ifndef VECTOR_H_
#define VECTOR_H_

class Vector
{
	public:
		Vector();
		~Vector();
		Vector(Vector const & src);
		void push_back(int elem);
		void insert_at(int index, int elem);
		int get_at(int index);
		int get_size();
	private:
		int m_arr_len;
		int* m_arr;
		int m_size;
};

#endif
