#include <iostream>
#include <string>
using namespace std;

template<class T>
class Vector {
public:
	Vector()
		:_start(nullptr)
		,_finsh(nullptr)
		,_eos(nullptr)
	{}
	//����Ԫ�ظ���
	size_t size()const {
		return _finsh - _start;
	}
	//��������
	size_t capacity()const {
		return _eos - _start;
	}
	//β��
	void pushBack(const T& val) {
		//�ж������Ƿ�����
		if (_finsh == _eos) {
			//����
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			Reserve(newC);
		}
		*_finsh = val;
		_finsh++;
	}
	//����
	void Reserve(size_t n) {
		//���ڵ�ǰ��������Ҫ����
		if (n > capacity()) {
			size_t oldsize = size();
			//���ռ�
			T* tmp = new T[n];
			//���
			for (int i = 0; i < size(); ++i) {
				tmp[i] = _start[i];
			}
			//�ͷ�ԭ�пռ�
			delete _start;
			//����ָ��
			_start = tmp;
			_finsh = _start + oldsize();
			_eos = _start + n;
		}
	}

	//operator[]�ɶ���д
	T& operator[](size_t pos) {
		if (pos < size()) {
			return _start
		}
	}
	//ֻ��
	const T& operator[](size_t pos)const {
		if (pos < size()) {
			return _start[pos];
		}
	}

	typedef T* iterator;
	typedef const T* const_iterator;
	iterator begin() {
		return _start;
	}
	iterator end() {
		return _eos;
	}
	const_iterator begin()const {
		return _start;
	}
	const_iterator end()const {
		return _eos;
	}
	void  Resize(size_t n, const T& val = T()) {
		if (n > capacity()) {
			//������
			Reserve(n);
		}
		if (n > size()) {
			//���
			while (_finsh != _start + n) {
				*_finsh++ = val;
			}
		}
		//����_size
		_finsh = start + n;
	}
	void Insert(iterator pos ,const T& val) {
		if (pos >= _start && pos <= _finsh) {

			size_t len = size();
			//�������
			if (_finsh == _eos) {
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				Reserve(newC);
				pos = _start + len;
			}
			//�ƶ�Ԫ��
			iterator end = _finsh;
			while (end > pos) {
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finsh;
		}
	}
	iterator Erase(iterator pos) {
		//���ж�ɾ��
		if (pos >= _start && pos < _finsh) {
			iterator begin = pos + 1;
			while (begin < pos + 1) {
				*(begin - 1) = *begin;
				++begin;
			}
			//����_size
			--_finsh;
			return pos;
		}
	}
	~Vector() {
		if (_start) {
			delete[] _start;
			_start = _finsh = _eos = nullptr;
		}
	}
	//��������
	Vector(const Vector& v)
		:_start(new T[v.capacity()]);
	{
		//���
		for (auto& e : v) {
			_start[i] = v[i];
		}
		_finsh = _start + v.size();
		_eos = _start + v.capacity();
	}
	void Swap(const Vector<T>& v) {
		swap(_start, v._start);
		swap(_finsh, v._finsh);
		swap(_eos, v._eos);
	}
	//��ֵ���������
	Vector<T>& operator=(const Vector<T> v) {
		Swap(v);
		return *this;
	}
private:
	T* _start; //��ʼ��ַ
	T* _finsh; //Ԫ�ؽ�����ַ
	T* _eos; //����������ַ
};

void test() {

}

int main() {
	test();
	return 0;
}