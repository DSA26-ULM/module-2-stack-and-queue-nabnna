#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = peek(&s); 
            pop(&s);
            int a = peek(&s); 
            pop(&s);

            int hasil = 0;
            if (token == "+")      hasil = a + b;
            else if (token == "-") hasil = a - b;
            else if (token == "*") hasil = a * b;
            else if (token == "/") {
                if (b != 0) hasil = a / b;
            }
            
            push(&s, hasil);
        } 
        else {
            int angka = stoi(token);
            push(&s, angka);
        }
    }

    if (!isEmpty(&s)) {
        cout << peek(&s) << endl;
    }

    return 0;
}
