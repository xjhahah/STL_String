#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>
#include <cassert>
using namespace std;

class String
{
public:
	friend ostream& operator<<(ostream& _cout,const String& s)
	{
		_cout << s._str ;
		return _cout;
	}
	friend istream& operator>>(istream& _cin,const String& s)
	{
		_cin >> s._str;
		return _cin;
	}

	String(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}
	char& operator[](size_t pos)
	{
		assert(pos<_size);
		return _str[pos];
	}
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	void Reserve(size_t n);
	void Resize(size_t n, char ch);

	void PushBack(char ch);
	void Append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	int Find(char ch, size_t pos = 0);
	int Find(const char* str, size_t pos = 0);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);
	void Erase(size_t pos, size_t len = npos);
	size_t Size()const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		return 0 == _size;
	}
	void Swap(String s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	const char* c_str()
	{
		return _str;
	}
	//定义迭代器
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;  //实际存数数据的空间
	static const size_t npos;
};
