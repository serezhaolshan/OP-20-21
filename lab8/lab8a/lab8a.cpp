#include <iostream>

using namespace std;

int main()
{

    string a[10]{};

    for (int i = 0; i < 10; i++) {
        string answ = "";
        cout << "КУРИТЕ???";
        cin >> answ;
        if (answ == "ДА" || answ == "Да" || answ == "дА" || answ == "да") {
            a[i] = "B";
        }
        else {
            
        }
    }
}


