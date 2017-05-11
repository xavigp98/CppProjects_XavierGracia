#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <iostream>

std::list<int> superMerge(std::list<int> uno, std::list<int> dos) {
	std::deque<int> mezcla(uno.begin(), uno.end());

	for (auto it = dos.begin(); it != dos.end(); ++it) {
		mezcla.push_back(*it);
	}

	int buffer, size = mezcla.size();
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (size - 1); j++) {
			if (mezcla[j] < mezcla[j + 1]) {
				buffer = mezcla[j];
				mezcla[j] = mezcla[j + 1];
				mezcla[j + 1] = buffer;
			}
		}
	}

	std::list <int> resultado;

	for (auto it = mezcla.begin(); it != mezcla.end(); it++) {
		resultado.push_back(*it);
	}

	return resultado;

}

void change(std::list<int>& in) {
	int front = in.front(), back = in.back();
	in.pop_front();
	in.push_front(back);
	in.pop_back();
	in.push_back(front);
}

int getElementPos(std::list<int> in, int val) {
	int contador = 0;
	int i = 0;
	for (auto it = in.begin(); it != in.end(); it++,i++) {
		if (*it == val)
			contador = i;
	}
	return contador;
}

void removeDuplicates(std::list<int>& in) {
	std::unordered_set<int> buffer;

	for (auto it = in.begin(); it != in.end(); it++) {
		buffer.insert(*it);
	}

	in.erase(in.begin(), in.end());

	for (auto it = buffer.begin(); it != buffer.end(); it++) {
		in.push_back(*it);
	}
}

void removeElement(std::list<int>& in, int value) {
	int conta = 0;
	bool borrado = false;
	auto it = in.begin();

	for (auto it = in.begin(); it != in.end(); it++) {
		if (*it == value)
			conta += 1;
	}
	if (conta > 0) {
		for (int i = 0; i < conta; i++) {
			borrado = false;
			it = in.begin();
			while (!borrado) {
				if (*it == value) {
					borrado = true;
					in.erase(it);
				}
				else {
					it++;
				}
				
			}
		}
	}
}

bool palindrome(std::list<int> in) {
	if (in.size() % 2 != 0) {
		auto it1 = in.begin(), it2 = in.end();
		--it2;
		bool respuesta = true;

		while (it1 != it2) {
			if (*it1 != *it2)
				respuesta = false;
			it1++, it2--;
		}
		return respuesta;
	}
	else {
			auto it1 = in.begin(), it2 = in.end();
			--it2;
			bool respuesta = true;

			for(int i = 0; i< (in.size()/2); i++) {
				if (*it1 != *it2)
					respuesta = false;
				it1++, it2--;
			}
			return respuesta;
	}
}

int main() {

	//a
	std::list<int> a1({ 4,3,2,1,0 });
	std::list<int> a2({ 5,3,1,0 });

	std::list<int> aResultado = superMerge(a1, a2);

	//b
	std::list<int> b1({ 3,2,2,2,2,7 });

	change(b1);

	//c
	std::list<int> c1({ 1,1,1,3,2,2,2 });

	int cResultado = getElementPos(c1, 3);

	//d
	std::list<int> d1({ 1,1,0,0,5,5 });

	removeDuplicates(d1);

	//e
	std::list<int> e1({ 1,6,2,3,6,4,5});

	removeElement(e1, 6);

	//f
	std::list<int> f1({ 1,2,3,2,1 });

	bool fResultado = palindrome(f1);
	return 0;
}