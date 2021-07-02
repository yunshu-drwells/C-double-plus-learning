#include <iostream>
using namespace std;
class complex{
public:
    complex();
    complex(double real, double imag);
public:
    complex operator+(const complex &A) const;
    void display() const;
private:
    double m_real;double m_imag;
};
complex::complex(): m_real(0.0), m_imag(0.0){ }
complex::complex(double real, double imag): m_real(real), m_imag(imag){ }
complex complex::operator+(const complex &A)const{
    return complex(this->m_real + A.m_real, this->m_imag + A.m_imag);
}
void complex::display() const{
    cout<<m_real<<" + "<<m_imag<<"i"<<endl;
}
int main(){
    complex c1(4.3, 5.8); complex c2(2.4, 3.7);
    complex c3;    c3 = c1 + c2;  //c3 = c1.operator+(c2); 
	c3.display();
    return 0;
}

