#include <iostream>
#include <cstdlib> // For atoi
#include <cstring> // For strcmp
#include "Queue.h"

using namespace std;

int main(int argc, char **argv) {
    Queue q;


    cout << "-- Enqueing and Dequeing --" << endl;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            int x = q.dequeue();
            if (x != -1) {
                cout << "Dequeuing " << x << endl;
            }
        } else {
            q.enqueue(atoi(argv[i]));
            cout << "Enqueuing " << argv[i] << endl;
        }
    }

    return 0;
}
