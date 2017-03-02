#include "DynArray.hh"

DynArray::DynArray() {
	m_data = new int[DYN_ARRAY_DEFAULT_SIZE];
	m_size = DYN_ARRAY_DEFAULT_SIZE;
}

DynArray::DynArray(size_t size, const int &value) {
	m_data = new int[size];
	for (int i = 0; i < size; i++) {
		m_data[i] = value;
	}
	m_size = size;
}

DynArray::~DynArray() {
	delete[]m_data;
	m_data = nullptr;
}

void DynArray::fill(int *first, int *last, int value) {
	int *p = first;
	while (p != last) {
		*p = value;
		p++;
	}
} 

int& DynArray::operator[](size_t n)const {
	return m_data[n];
}

bool operator==(const DynArray& lhs, const DynArray& rhs) {
	if (lhs.m_size != rhs.m_size)
		return false;
	else {
		int i = 0;
		while (i < lhs.m_size) {
			if (lhs[i] != rhs[i])
				return false;
			i++;
		}
	}
}

int* DynArray::begin() const {
	 
	return &m_data[0];
}

int* DynArray::end() const {
	return &m_data[m_size-1];
}


