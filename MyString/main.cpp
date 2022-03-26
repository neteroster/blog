#include <iostream>
#include <string> // 仅用作构造函数
#include <cassert>

using namespace std;

class MyString
{
	friend ostream& operator<<(ostream& out, const MyString& str_input);
public:
	MyString(); // construct an empty string.
	MyString(int len); // construct an string with `len` space.
	MyString(const char* str_input, int a, int b); // construct a string from [a, b) of a const char*;
	MyString(const char* str_input);
	MyString(const string str_input, int a, int b);  // construct a string from [a, b) of a string.
	MyString(const string str_input);

	MyString(const MyString& str_input, int a, int b); // construct a string from [a, b) of a MyString.
	MyString(const MyString& str_input);

	~MyString() { delete[] str; }

	MyString operator+(const MyString& str_to_add);
	MyString& operator=(MyString& str_input);
	MyString& operator+=(MyString& str_to_add);
	bool operator==(const MyString& str_to_compare);
	char operator[](int index);

	int get_size() const { return size; }
	bool empty() const { return size == 0; }


private:
	char* str;
	int size;
};

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	
	size = 0;
}

MyString::MyString(int len)
{
	str = new char[len + 1];
	size = len;

	for (int p = 0; p < len; str[p] = ' ', p++);
	str[size] = '\0';
}

MyString::MyString(const char* str_input, int a, int b)
{
	str = new char[b - a + 1];
	size = b - a;

	for (int p = a, x = 0; p < b; str[x] = str_input[p], p++, x++);
	str[size] = '\0';
}

MyString::MyString(const char* str_input)
{
	int input_len = 0;
	for (; str_input[input_len] != '\0'; input_len++);

	new (this) MyString(str_input, 0, input_len);
}

MyString::MyString(const string str_input, int a, int b)
{
	str = new char[b - a + 1];
	size = b - a;

	for (int p = a, x = 0; p < b; str[x] = str_input[p], p++, x++);
	str[size] = '\0';
}

MyString::MyString(const string str_input) : MyString(str_input, 0, str_input.size())
{
}

MyString::MyString(const MyString& str_input, int a, int b)
{
	str = new char[b - a + 1];
	size = b - a;

	for (int p = a; p < b; str[p] = str_input.str[p], p++);
	str[size] = '\0';
}

MyString::MyString(const MyString& str_input) : MyString(str_input, 0, str_input.size)
{
}

MyString MyString::operator+(const MyString& str_to_add)
{
	MyString result(size + str_to_add.size);

	int p = 0;
	for (; p < size; result.str[p] = str[p], p++);
	for (int x = 0; x < str_to_add.size; result.str[p + x] = str_to_add.str[x], x++);
	
	return result;
}

MyString& MyString::operator=(MyString& str_input)
{
	delete[] str;

	size = str_input.size;
	for (int p = 0; p < size; str[p] == str_input.str[p], p++);

	str[size] = '\0';

	return *this;
}

MyString& MyString::operator+=(MyString& str_to_add)
{
	MyString this_backup(*this);

	size += str_to_add.size;

	delete[] str;
	str = new char[size + 1];
	
	int p = 0;
	for (; p < this_backup.size; str[p] = this_backup[p], p++);
	for (int x = 0; x < str_to_add.size; str[p + x] = str_to_add[x], x++);
	str[size] = '\0';

	return *this;
}

bool MyString::operator==(const MyString& str_to_compare)
{
	if (size != str_to_compare.size) return false;
	for (int p = 0; p < size; p++)
		if (str[p] != str_to_compare.str[p]) return false;
	return true;
}

char MyString::operator[](int index)
{
	return str[index];
}




ostream& operator<<(ostream& out, const MyString& str_input)
{
	out << str_input.str;
	return out;
}

int main()
{
	MyString test_str_a("Hello");
	cout << test_str_a << endl;

	MyString test_str_b(" World");
	cout << test_str_a + test_str_b << endl;

	test_str_a += test_str_b;
	cout << test_str_a << endl;

	cout << (test_str_a == MyString("Hello World") ? "true" : "false") << endl;
	cout << (test_str_a == MyString("-Hello World-") ? "true" : "false") << endl;


	string test_a = "This is a test.";
	MyString test_str_c(test_a, 0, 4);
	cout << test_str_c << endl;
	cout << test_str_c[0] << endl;
	cout << MyString("Hello World!", 6, 12) << endl;
	cout << MyString(string("Hello World!"), 6, 12) << endl;

	cout << test_str_a.get_size() << " " << endl;
	cout << (MyString().empty() ? "empty" : "!empty") << endl;
	cout << (MyString("2333").empty() ? "empty" : "!empty") << endl;


}
