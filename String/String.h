#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(char* str)
		:_str(new char [strlen(str)+1])
	{
		strcpy(_str, str);
	}
	String(const char* str="")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);  //while(*dst++.*src++)
	}

	/*String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}*/

	//s1=s2
	//传统写法
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		//strcpy(_str, s._str);
	//	}
	//	for (size_t i = 0; i < (strlen(s._str) + 1); ++i)
	//	{
	//		_str[i] = s._str[i];
	//	}
	//	return *this;
	//}
	//现代写法
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	friend ostream& operator<<(ostream& _cout,const String& s)
	{
		_cout << s._str ;
		return _cout;
	}
	String(const char* str = "")
	{

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

	}
	~String();

	void PushBack(char ch);
	void Append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	size_t Find(char ch, size_t pos = 0);
	size_t Find(const char* str, size_t pos = 0);
	void Insert(size_t pos);
	void Insert(size_t pos,const char* str);
	void Insert(size_t pos,size_t len=npos);
	char& operator[](size_t pos);
	const char& operator[](size_t pos)const;
	size_t Size()const;
	size_t Capacity()const;
	void Swap(String s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;  //实际存数数据的空间
	static const size_t npos;
};
