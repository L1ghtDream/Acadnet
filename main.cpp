#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/// Clasa memoreaza un nr complex
class complex {
private:
    int r, i;   // r - partea reala, i - partea imaginara
public:
    complex();  // creeaza numarul imaginar nul
    complex(int pr, int pi); // pr - valoarea termenului real, pi - val. term. imaginar
    string afisare(); // pregateste un sir pentru a fi afisat
    int real();     // returneaza partea reala
    int imaginar(); // returneaza partea imaginara
    void set(int pr, int pi); // stabileste valoarea partii reale si a celei imaginare
};
// aici va fi scris codul tau

complex::complex() {
    this->r = 0;
    this->i = 0;
}

complex::complex(int pr, int pi) {
    this->r = pr;
    this->i = pi;
}

string complex::afisare() {
    string output = "";

    if(this->r!=0) {
        output += std::to_string(this->r);
    }

    if(this->r!=0 && this->i>0) {
        output += "+";
    }

    if(this->i!=0){
        if(this->i!=1){
            output += std::to_string(this->i);
        }
        output += "i";
    }

    return output;
}

int complex::real() {
    return this->r;
}

int complex::imaginar() {
    return this->i;
}

void complex::set(int pr, int pi) {
    this->r = pr;
    this->i = pi;
}

complex operator+(complex c1, complex c2){
    return complex(c1.real()+c2.real(), c1.imaginar()+c2.imaginar());
}

complex operator-(complex c1, complex c2){
    return complex(c1.real()-c2.real(), c1.imaginar()-c2.imaginar());
}

complex operator*(complex c1, complex c2){
    // (a+b)(c+d)
    // ac + ad + bc + bd

    return complex(
            c1.real()*c2.real() - c2.imaginar()*c1.imaginar(),
            c1.real()*c2.imaginar() + c1.imaginar()*c2.real()
    );
}

int main() {
    fstream fin("../date.in", ios::in);
    ofstream fout("../date.out");
    int a, b, c, d;
    while (fin >> a >> b >> c >> d) {
        complex x(a, b), y(c, d), z;
        z = x + y;
        fout << z.afisare() << "\n";
        z = x - y;
        fout << z.afisare() << "\n";
        z = x * y;
        fout << z.afisare() << "\n";
    }
    return 0;
}
