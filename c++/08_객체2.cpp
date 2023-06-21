#include<iostream>

using namespace std;

class Complex {
public:
    Complex () : real(0), image(0) {}

    Complex (int real, int image) : real(real), image(image) {}

    int getReal() {
        return real;
    }
    int getImage() {
        return image;
    }


private:
    int real;
    int image;
};


int main() {
    Complex c1;
    Complex c2 = Complex(2,3);
    Complex c3(5,3);

    cout << "c1 : " << c1.getReal() << ',' << c1.getImage() << endl;
    cout << "c2 : " << c2.getReal() << ',' << c2.getImage() << endl;
    cout << "c3 : " << c3.getReal() << ',' << c3.getImage() << endl;
}