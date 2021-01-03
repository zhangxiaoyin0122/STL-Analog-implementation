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
	//容器元素个数
	size_t size()const {
		return _finsh - _start;
	}
	//容器容量
	size_t capacity()const {
		return _eos - _start;
	}
	//尾插
	void pushBack(const T& val) {
		//判断容器是否已满
		if (_finsh == _eos) {
			//增容
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			Reserve(newC);
		}
		*_finsh = val;
		_finsh++;
	}
	//增容
	void Reserve(size_t n) {
		//大于当前容量才需要增容
		if (n > capacity()) {
			size_t oldsize = size();
			//开空间
			T* tmp = new T[n];
			//深拷贝
			for (int i = 0; i < size(); ++i) {
				tmp[i] = _start[i];
			}
			//释放原有空间
			delete _start;
			//更新指针
			_start = tmp;
			_finsh = _start + oldsize();
			_eos = _start + n;
		}
	}

	//operator[]可读可写
	T& operator[](size_t pos) {
		if (pos < size()) {
			return _start
		}
	}
	//只读
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
			//先增容
			Reserve(n);
		}
		if (n > size()) {
			//填充
			while (_finsh != _start + n) {
				*_finsh++ = val;
			}
		}
		//更新_size
		_finsh = start + n;
	}
	void Insert(iterator pos ,const T& val) {
		if (pos >= _start && pos <= _finsh) {

			size_t len = size();
			//检查容量
			if (_finsh == _eos) {
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				Reserve(newC);
				pos = _start + len;
			}
			//移动元素
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
		//先判断删除
		if (pos >= _start && pos < _finsh) {
			iterator begin = pos + 1;
			while (begin < pos + 1) {
				*(begin - 1) = *begin;
				++begin;
			}
			//更新_size
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
	//拷贝构造
	Vector(const Vector& v)
		:_start(new T[v.capacity()]);
	{
		//深拷贝
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
	//赋值运算符重载
	Vector<T>& operator=(const Vector<T> v) {
		Swap(v);
		return *this;
	}
private:
	T* _start; //起始地址
	T* _finsh; //元素结束地址
	T* _eos; //容量结束地址
};

void test() {

}

int main() {
	test();
	return 0;
}