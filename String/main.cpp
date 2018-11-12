#include "String.h"
const size_t String::npos = -1;
int main()
{
	String s1("hello");
	cout << s1 << endl;
	s1.PushBack('h');
	cout << s1.Find('e', 0) << endl;
	s1.Find("ell", 0);

	s1.Insert(2, 'p');
	return 0;
}