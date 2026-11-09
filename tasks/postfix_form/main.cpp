
#include <iostream>
#include <stack>
#include "string"

using namespace std;

double EvaluatePostfix(string &s1) {
    stack<double> postStack;

    if (s1.empty()) {
        cout << "ошибка! пустая строка" << endl;
        return 0;
    }

    for (size_t i = 0; i < s1.size(); i++) {
        char c = s1[i];

        if (c == ' ') continue;

        // isdigit - проверка на нахождение в диапазоне 0-9
        if (isdigit(c) || c == '.') {
            size_t start = i;
            bool dot = false;
            while (i < s1.size() && (isdigit(s1[i]) || s1[i] == '.')) {
                if (s1[i] == '.') {
                    if (dot) { cout << "ошибка! две точки в числе" << endl;
                        return 0;
                    }
                    dot = true;
                }
                ++i;
            }
            postStack.push(stod(s1.substr(start, i - start)));
            --i;
            continue;
        }

        if (c == '~') {
            if (postStack.empty()) {
                cout << "ошибка! неверная запись: ~ без операнда" << endl;
                return 0;
            }
            double temp = postStack.top();
            postStack.pop();
            postStack.push(-temp);
            continue;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (postStack.size() < 2) {
                cout << "ошибка! не хватает операндов для " << c << endl;
                return 0;
            }
            double b = postStack.top();
            postStack.pop();
            double a = postStack.top();
            postStack.pop();
            switch (c) {
                case '+': postStack.push(a + b);
                    break;
                case '-': postStack.push(a - b);
                    break;
                case '*': postStack.push(a * b);
                    break;
                case '/':
                    if (b == 0.0) {
                        cout << "ошибка! деление на ноль" << endl;
                        return 0;
                    }
                    postStack.push(a / b);
                    break;
            }
            continue;
        }

        cout << "ошибка! неизвестный символ: " << c << endl;
        return 0;
    }

    if (postStack.size() != 1) {
        cout << "ошибка! неверная запись: в стеке " << postStack.size() << " значений" << endl;
        return 0;
    }

    return postStack.top();
}

int main() {

    string str = "73.45 ~ 51.093 ~ 27 - ~ ~ ~ + ";
    // -73.45 + ---(-51.093 - 27)
    cout << EvaluatePostfix(str);

    return 0;
}
