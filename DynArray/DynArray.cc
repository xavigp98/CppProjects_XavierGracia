#include "DynArray.hh"

DynArray::DynArray() :  m_capacity(DYN_ARRAY_DEFAULT_SIZE),m_size(0),m_data(new int[m_capacity])
{
}

DynArray::DynArray(size_t size, const int &value) : m_capacity(size), m_size(size), m_data(new int[size])
{
	for (int i = 0;i <size;i++)
		m_data[i] = value;
}

DynArray::~DynArray() {
	delete[]m_data;
	m_data = nullptr;
}

void DynArray::fill(int *first, int *last, int value) {
	while (first != last) {
		*first = value;
		++first;
	}
} 

int& DynArray::operator[](size_t n)const {
	return m_data[n];
}

bool operator==(const DynArray& lhs, const DynArray& rhs) {
	if (lhs.m_capacity != rhs.m_capacity)
		return false;
	else {
		int i = 0;
		while (i < lhs.m_capacity) {
			if (lhs[i] != rhs[i])
				return false;
			i++;
		}
	}
	return true;
}


int* DynArray::begin() const {
	 
	return &m_data[0];
}

int* DynArray::end() const {
	return &m_data[m_capacity];
}

void DynArray::push(const int &val) {
	if (m_size < m_capacity) {
		m_data[m_size] = val;
		m_size+=1;
	}
	else {
		int *p = new int[m_size + 1];
		for (int i = 0; i < m_size; i++) {
			p[i] = m_data[i];
		}
		p[m_size] = val;
		delete[]m_data;
		m_data = p;
		m_size += 1;
		m_capacity += 1;
	}
}
