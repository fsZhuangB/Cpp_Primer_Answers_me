// 下面哪个定义是不合法的？
int ival = 1.01; // good
int &rval1 = 1.01; // bad, reference must be an object
int &rval2 = ival; // good
int &rval3; // bad, must initialize the reference
