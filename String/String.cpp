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
int String::Find(char ch, size_t pos)
{
	for (; pos < _size; ++pos)
	{
		if (_str[pos] == ch)
		{
			return pos;
		}
	}
	return  -1;
}
int String::Find(const char* str, size_t pos)
{
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		Reserve(_size + len);
	}
	for (; pos < _size; ++pos)
	{
		int n = pos;
		while (*str == _str[n])
		{
			str++;
			n++;
		}
		if (*str == '\0')
		{
			return pos;
		}
		continue;
	}
	return -1;
}
void String::Insert(size_t pos, char ch)
{
	assert(pos <= _size);
	if (_size == _capacity)
	{
		Reserve(_capacity * 2);
	}
	size_t end = _size;
	while (end>=pos)
	{
		_str[end + 1] = _str[end];
		--end;
	}
	_str[pos] = ch;
	++_size;
	_str[_size] = '\0';
	cout << *this;
}
void String::Insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		Reserve(_capacity + len);
	}
	size_t end = _size;
	while (end >= pos)
	{
		_str[end + len] = _str[end];
		--end;
	}
	int i = 0;
	while (len--)
	{
		_str[pos + i] = str[i];
		++i;
		++_size;
	}
	_str[_size] = '\0';
	cout << *this << endl;
}
void String::Erase(size_t pos, size_t len)
{
	assert(!len);
	assert(pos < _size);
	if (pos + len >= _size)
	{
		_size = pos;
		_str[_size] = '\0';
	}
	else
	{
		char* dst = _str + pos + len;
		char* src = _str + pos;
		strcpy(src, dst);
		delete[] src;
		_size -= len;
	}
	cout << *this;
}