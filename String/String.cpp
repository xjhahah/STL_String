#include "String.h"

void String::Reserve(size_t n)
{
	if (n>_capacity)
	{
		char* NewCapacity = new char(n+1);
		strcpy(_str, NewCapacity);
		delete[] _str;
		_str = NewCapacity;
		_size = n;
	}
}

String& String::PushBack(char ch)
{
	if (_size == _capacity)
	{
		Reserve(_capacity * 2);
	}
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
	return *this;
}
void String::Append(const char* str)
{
	size_t len = strlen(str);
	if (_size + len>_capacity)
	{
		Reserve(_size+len);
	}
	strcpy(_str+_size, str);
	_size += len;
}
String& String::operator+=(char ch)
{
	PushBack(ch);
	return *this;
}
String& String::operator+=(const char* str)
{
	Append(str);
	return *this;
}

void String::Resize(size_t n, char ch)
{
	if (n <= _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		size_t pos = _size;
		while (pos < n)
		{
			_str[pos] = ch;
			++pos;
		}
		_str[n] = '\0';
		_size = n;
	}
}
size_t String::Find(char ch, size_t pos = 0)
{
	String::iterator it = begin();
	for(;it!=end();++it)
	{
		if (_str[*it] == ch)
		{
			pos = *it;
			cout << pos;
		}
	}
	return pos;
}
//size_t String::Find(const char* str, size_t pos = 0)
//{
//
//}
//void String::Insert(size_t pos, char ch)
//{
//
//}
//void String::Insert(size_t pos, const char* str)
//{
//
//}
//void String::Erase(size_t pos, size_t len = npos)
//{
//
//}