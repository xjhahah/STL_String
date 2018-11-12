#include "String.h"
const size_t String::npos = -1;
int main()
{
	String s1("hello");
	cout << s1 << endl;
	s1.PushBack(' ');
	/*
	cout << s1.Find('e', 0) << endl;
	s1.Find("ell", 0);

	s1.Insert(2, 'p');*/
	s1.Insert(4, "world");
	s1.Erase(1, 2);
	return 0;
}