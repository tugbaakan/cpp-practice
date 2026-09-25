
#include <iostream>

using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double _real = 0, double _imag = 0) {
        real = _real;
        imag = _imag;
    }

    void bilgiYazdir() {
        cout << real << " " << imag << endl;
    }

};


/*int main()
{

    
    std::cout << "Hello World!\n";

    Complex c1(1, 2);
    Complex c2;

    c1.bilgiYazdir();
    c2.bilgiYazdir();
    


    std::cout << "Bye!\n";


    return 0;
}

*/


