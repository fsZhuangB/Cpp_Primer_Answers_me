
#include <string>
using namespace std;

class HasPtr {
public:
	// constructor allocates a new string
	// and a new counter, which sets to 1
	HasPtr(const string &s = string()) : 
		ps(new string(s)), i(0), use(new std::size_t(1)) {}

	HasPtr(const HasPtr& hpr) :
		ps(hpr.ps), i(hpr.i), use(hpr.use) {
		++*use;
	}
	HasPtr& operator=(const HasPtr& hpr)
	{
		++* hpr.use;
		string* new_ps = ps;
		// decrement this object's counter
		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
		ps = hpr.ps;
		i = hpr.i;
		use = hpr.use;
		return *this;
	}

	~HasPtr()
	{
		if (-- * use == 0)
		{
			delete use;
			delete ps;
		}
	}

private:
	string* ps;
	int i;
	std::size_t* use;    // store the reference into the dynamic memory
};
