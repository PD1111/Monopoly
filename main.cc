#include "controller.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    Controller c;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i],"-testing") == 0) c.setTesting();
            if (strcmp(argv[i],"-load") == 0) {
            c.setInput(argv[i+1]);
            }
        }

    }
    c.play();
}
