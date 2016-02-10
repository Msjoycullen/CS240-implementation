#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

template <typename T>
class Heap {
	std::vector<T> _content;
	void _up(size_t v) {
		int parent = (v - 1) / 2;
		while (parent >= 0 && _content[v] > _content[parent])
		{
			std::swap(_content[parent], _content[v]);
			v = parent;
		}
	}

	void _down(size_t v) {
		int left = 2 * v + 1;
		int right = 2 * v + 2;
		int size = this->size();
		while (left < size || right < size)
		{
			int u = _content[left] > _content[right] ? left : right;
			if (_content[u] > _content[v])
			{
				std::swap(_content[u], _content[v]);				
				v = u;
				left = 2 * v + 1;
				right = 2 * v + 2;
			}
			else return;
		}
	}

	public:
	void push(const T &element) {
		_content.push_back(element);
		_up(size() - 1);
	}

	void pop() {
		T temp = _content[0];
		int size = this->size();
		_content[0] = _content[size - 1];
		_content[size - 1] = temp;
		_content.pop_back();
		_down(0);
	}

	T top() {return _content[0];}

	size_t size() {return _content.size();}
};

/* For testing
int main() {
	for (int j = 0; j < 20; j++)
	{
		Heap<int> h;
		for (int i = 0; i < 1000000; i++)
			h.push(rand());
		for (int i = 0; i < 1000000; i++)
			h.pop();
	}
	return 0;
}
*/
