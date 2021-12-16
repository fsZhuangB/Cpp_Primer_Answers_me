#include <string>
using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) :
		 ps(new string(s)), i(0) { }

	// the constructor should dynamically allocate a new string
	// and copy the object to which ps points, rather copying ps itself
	HasPtr(const HasPtr& hpr) : ps(new string(*hpr.ps)), i(hpr.i) { }
//    HasPtr(HasPtr& hp) {
        // 拷贝构造函数
        // 为其分配新的空间
//        string* newString = new string(*hp.ps);
//        this->ps = newString;
//        this->i = hp.i;
//    }	

	// Your assignment operator should copy the object to which ps points
	HasPtr& operator=(const HasPtr& hpr)
	{
        // copy the underlying string
        // this is because we have to 
        // handle the self-assignment condition
		string* new_hasptr = new string(*hpr.ps);
		delete ps; // free the old memory
		ps = new_hasptr; // copy data from hpr into this object
		i = hpr.i;
		return *this;    // return this object 
	}


	// remember the synthesized destructor won't 
	// delete a data member that is a pointer
	~HasPtr()
	{
		delete ps;
	}

private:
	string* ps;
	int i;
};

// remember:
// if we use synthesized copy constructor
// this function will delete the same memory position twice
// this may cause undefined behavior
HasPtr f(HasPtr hp)
{
	HasPtr ret = hp;
	return ret;
}
int main()
{
	HasPtr a("hhhh");
	f(a);
	HasPtr q(a);

	return 0;
	
}
