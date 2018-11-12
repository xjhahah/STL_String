#include "String.h"

void String::Reserve(size_t n)
{
	if (n>_capacity)
	{
		char* NewCapacity = new char(n+1);
		strcpy(NewCapacity, _str);
		delete[] _str;
		_str = NewCapacity;
		_capacity = n;
	}
}

void String::PushBack(char ch)
{
	if (_size == _capacity)
	{
		Reserve(_capacity * 2);
	}
	_str[_size] = ch;
	++_size;
	_str[_size] = '\0';
	cout << *this << endl;
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
size_t String::Find(char ch, size_t pos)
{
	for (; pos < _size; ++pos)
	{
		if (_str[pos] == ch)
		{
			cout << pos << " ";
			break;
		}
	}
	return  pos;
}
size_t String::Find(const char* str, size_t pos)
{
	size_t len = strlen(str);
	size_t flag = 0;
	if (len > _capacity)
	{
		Reserve(_capacity + len);
	}
	for (size_t i = 0; i < len; i++)
	{
		flag = 0;
		while(_str[pos] != str[i])
		{
			++pos;
			if (_str[pos] == str[i])
			{
				flag = 1;
			}
		}
	}
	if (flag)
		return pos;
	else
		printf("该字符串中没有所查的子串。");
		return -1;
	
}
void String::Insert(size_t pos, char ch)
{
	if (_size == _capacity)
	{
		Reserve(_capacity * 2);
	}
	for (size_t i = 0; i < _size; ++i)
	{
		if (i == pos)
		{
			_str[pos] = ch;
			++_size;
			_str[_size] = '\0';
			cout << *this << endl;
			break;
		}
	}
}
void String::Insert(size_t pos, const char* str)
{

}
void String::Erase(size_t pos, size_t len)
{

}