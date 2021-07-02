#include <iostream>
using namespace std;
int main()
{	cout << "char length:        " << sizeof( char ) << endl;
	cout << "int length:         " << sizeof( int ) << endl;
	cout << "long length:        " << sizeof( long ) << endl;
	cout << "float length:       " << sizeof( float ) << endl;
	cout << "double length:      " << sizeof( double ) << endl;
	cout << "long double length: " << sizeof( long double ) << endl;
	cout << "char* length:       " << sizeof( char* ) << endl;
	cout << "int* length:        " << sizeof( int* ) << endl;
	cout << "long* length:       " << sizeof( long* ) << endl;
	cout << "float* length:      " << sizeof( float* ) << endl;
	cout << "double* length:     " << sizeof( double* ) << endl;
	cout << "long double* length:" << sizeof( long double* ) << endl;
	cout << "void* length:       " << sizeof( void* ) << endl;
	return 0;    
}
