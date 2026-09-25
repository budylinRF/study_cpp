//
// Created by Ruslan on 25.09.2026.
//

#include <iostream>

class Error {
public:
    virtual void show() = 0;

    ~Error() {}
};

class DivZero : public Error {
    int error_code;

public:
    DivZero(int error_code) : error_code(error_code) {}



    void show() {
        std::cout << "error code: " <<error_code << std::endl;
    }
};

class NegativeValue: public Error {
int b;
public:
    NegativeValue(int b) : b(b) {}
    void show() override{
        std::cout << "Negative value" <<  b << std::endl;
    }
};

int div_val(int a, int b) {
    if (b == 0 ) throw new DivZero(-1);
    if (b < 0) throw new NegativeValue(b);
    return a / b;
}

int main() {

    int a, b;
    a = 10;
    b = -6;

    try {
        std::cout << "res:" << div_val(a, b);
    }

    catch (Error * err) {
        err->show();
    }

    catch (int ierr) {
        std::cout << "error code: " << ierr << std::endl;
    }
    catch (const char *str_err) {
        std::cout << "error: " << str_err << std::endl;
    }
    catch (...) {
            std::cout << "undef_error" << std::endl;
        }

    return 0;
}