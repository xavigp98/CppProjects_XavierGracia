#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <vector>

std::priority_queue<int> superMergeP(std::priority_queue<int> uno, std::priority_queue<int> dos) {
	std::priority_queue<int> result(uno);
	for (int i = dos.size(); i != 0; i--) {
		result.push(dos.top());
		dos.pop();
	}
	return result;
}

std::queue<std::string> concatQueue(std::queue<std::string> uno, std::queue<std::string> dos) {
	std::queue<std::string> result(uno);
	for (auto it = dos.size(); it != 0; it--) {
		result.push(dos.front());
		dos.pop();
	}
	return result;
}

std::queue<int> shiftRight(std::queue<int> uno) { //Arreglar
	std::queue<int> resultado;
	resultado.push(rand());
	for (int i = 0; i != (uno.size());i++) {
		resultado.push(uno.front());
		uno.pop();
	}
	return resultado;
}

void rotateLeft(std::queue<int>& uno){ 
	int ultimo = uno.front();
	uno.pop();
	uno.push(ultimo);
}

void eraseElements(std::deque<int>& uno, int value) {
	int k = 0;
	for (int i = 0; i != uno.size(); i++) {
		if (uno[i] == value)
			k += 1;
	}

	for (int i = 0; i < k; i++) {
		bool elimi = false;
		int j = 0;
		while (elimi == false) {
			if (uno[j] == value) {
				uno.erase(uno.begin() + j);
				elimi = true;
			}
			j++;
		}
	}
} //Arreglar

int main() {
	// 1)
	std::deque<float> prices(10, 10.50);
	prices[9] = 32.43;
	prices.pop_front();
	std::deque<float> segunda(prices);
	segunda.push_front(5.64);
	segunda.push_front(30.31);
	segunda.insert(segunda.begin() + 1, 10);

	for (auto it = prices.rbegin(); it != prices.rend(); it++)
		std::cout << *it <<std::endl;
	std::cout << std::endl;
	for (auto it = segunda.begin(); it != segunda.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	//2)
	std::vector<float> pricesV(10, 10.5);
	pricesV[9] = 32.43;
	pricesV.erase(pricesV.begin());
	std::vector<float> segundaV(pricesV);
	segundaV.insert(segundaV.begin(), 5.64);
	segundaV.insert(segundaV.begin(), 30.31);
	segundaV.insert(segundaV.begin()+1, 10);

	for (auto it = pricesV.rbegin(); it != pricesV.rend(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	for (auto it = segundaV.begin(); it != segundaV.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	// 3)

	std::priority_queue<int> uno;
	uno.push(5);
	uno.push(6);
	std::priority_queue<int> dos;
	dos.push(7);
	dos.push(8);

	std::priority_queue<int> resultado = superMergeP(uno, dos);

	std::queue<std::string> unoQ;
	unoQ.push("Hola");

	std::queue<std::string> dosQ;
	dosQ.push("Adios");

	std::queue<std::string> resultadoQ = concatQueue(unoQ, dosQ);

	std::queue<int> uno3;
	uno3.push(1);
	uno3.push(2);

	std::queue<int> resultado3 = shiftRight(uno3);

	rotateLeft(uno3);

	std::deque<int> uno4;
	uno4[0] = 1;
	uno4[1] = 2;


	eraseElements(uno4, 2);

	return 0;
}