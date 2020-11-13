#include <iostream>
#include <string>
using namespace std;

class String {
	//�޲ι��캯��
	String()
		:_str(new char[15])
		, _size(0)
		, _capacity(0)
	{
		_str[0] = '\0';
	}
	//���ι��캯��
	String(const char* str) {
		_size = strlen(str);
		_str = new char[_size];
		strcpy(_str, str);
		_capacity = _size;
	}
	//�������캯��
	String(const String& str)
		:_str(new char[str._capacity+1])
		,_size(str._size)
		,_capacity(str._capacity)
	{
		//���
		strcpy(_str, str._str);
	}
	void Swap(String& str) {
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	//�������캯�����ִ�д��
	String(const String& str)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}
	//��ֵ���������
	String& operator=(const String& str) {
		if (this != &str) {
			//���ռ�
			char* tmp = new char[str._capacity + 1];
			//���ݿ���
			strcpy(tmp, str._str);
			//ԭ�пռ��ͷ�
			delete[] _str;
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
		return *this;
	}
	//��������غ����ִ�д��
	String& operator=(String str) {
		Swap(str);
		return *this;
	}
	//����C���Է���ַ���
	const char* c_str()const {
		return _str;
	}
	//��������
	~String() {
		if (_str) {
			delete[]_str;
			_size = _capacity = 0;
			_str = nullptr;
		}
	}
	//����[]�����
	char& operator[](size_t pos) {
		if (pos < _size)
			return _str[pos];
	}
	const char& operator[](size_t pos)const {
		if (pos < _size)
			return _str[pos];
	}
	size_t size()const {
		return _size;
	}
	void pushback(const char& ch) {
		//�ж��Ƿ���Ҫ����
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 1 : 2 * _capacity;
			reverse(newC);
		}
		//β�����ַ�
		_str[_size] = ch;
		//����_size
		++_size;
		//��Ҫ���Ǹ���'\0'
		_str[_size] = '\0';
		//insert(_size,ch);
	}
	void reverse(size_t n) {
		if (n > _capacity) {
			//���ռ� : +1 �������'\0'
			char* tmp = new char[n + 1];
			//��������
			strcpy(tmp, _str);
			//�ͷ�ԭ�пռ�
			delete[] _str;
			_str = tmp;
			//��������
			_capacity = n;
		}
	}

	void Append(const char* str) {
		//�������
		int len = strlen(str);
		if (_size + len > _capacity) {
			reverse(_size + len);
		}
		//��������
		strcpy(_str + _size, str);
		//����_size
		_size += len;
		//insert(_size,str)
	}

	String& operator+=(const char& ch) {
		pushback(ch);
		return *this;
	}
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}

	void insert(size_t pos, const char& ch) {
		if (pos > _size)
			return;
		//�ж��Ƿ���Ҫ����  
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 1 : 2 * _capacity;
			reverse(newC);
		}
		size_t end = _size + 1;
		//Ԫ������ƶ�
		while (end > pos) {
			_str[end] = _str[end - 1];
			--end;
		}
		//����Ԫ��
		_str[pos] = ch;
		//����
		++_size;
	}

	void insert(size_t pos, const char* str) {
		if (pos > _size)
			return;
		//�ж��Ƿ���Ҫ����
		size_t len = strlen(str);
		if (_size + len > _capacity) {
			reverse(_size + len);
		}

		size_t end = _size + len;
		while (end > pos + len - 1) {
			_str[end] = _str[end - len];
			--end;
		}
		//�����ַ���		
		for (int i = 0; i < len; ++i) {
			_str[pos + i] = str[i];
		}
		//����_size
		_size += len;
	}
	//����_size
	void resize(size_t n, const char ch = '\0') {
		if (n > _capacity) {
			//����
			reverse(n);
		}
		if (n > _size) {
			memset(_str + _size, ch, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}
	void popback() {
		earse(_size - 1, 1);
	}

	void earse(size_t pos, size_t len) {
		if (pos < _size) {
			if (pos + len >= _size) {
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				//�ƶ�Ԫ��[pos+len,_size] --> [pos,_size-len]
				for (int i = pos + len; i > pos; --i) {
					_str[pos++] = _str[i];
				}
				_size -= len;
			}
		}
	}
	//�ַ�������,��������
	size_t find(const char* str) {
		char* ptr = strstr(_str, str);  //strstr�ҵ��Ӵ��᷵��ָ��
		if (ptr) {
			return ptr - _str;
		}
		else
			return npos;
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};