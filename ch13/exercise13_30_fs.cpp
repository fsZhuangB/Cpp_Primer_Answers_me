#include <string>
#include <iostream>

using namespace std;

/* value like version of HasPtr */
class HasPtr {
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const string& s, int i) : ps(new string(s)), i(i) {}
	HasPtr(const HasPtr& hpr) :
		ps(new string(*hpr.ps)), i(hpr.i) {}

	HasPtr& operator=(const HasPtr& hpr)
	{
		string* new_ps = ps;
		delete ps;
		ps = new string(*hpr.ps);
		i = hpr.i;
		return *this;
	}

	void print()
	{
		cout << *ps << endl;
		cout << i << endl;
	}
	~HasPtr()
	{
		delete ps;
	}

	friend void swap(HasPtr&, HasPtr&);
	
private:
	string* ps;
	int     i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	cout << "call the inner function swap().\n";
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);

}

int main()
{
	HasPtr a("string");
	HasPtr b("string2", 2);
	cout << "a is:";
	a.print();
	cout << endl;
	cout << "b is:";
	b.print();

	swap(a, b);
	cout << "a is:";
	a.print();
	cout << endl;
	cout << "b is:";
	b.print();

	return 0;
}