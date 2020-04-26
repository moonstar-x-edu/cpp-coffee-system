#include "utils.h"

int safeIntCin() {
    int value;
    do {
        cin >> value;

        if (!cin.fail()) {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Value must be an integer!" << endl;
    } while (true);
    return value;
}

long safeLongCin() {
    long value;
    do {
        cin >> value;

        if (!cin.fail()) {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Value must be a long integer!" << endl;
    } while (true);
    return value;
}
