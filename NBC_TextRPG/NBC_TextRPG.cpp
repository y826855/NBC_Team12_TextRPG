#include <iostream>
#include "MultiConsole/TestConsole.h"

int main(int argc, char* argv[])
{

    TestConsole* newConsole = new TestConsole();
    newConsole->TestOpenConsole(argc, argv);
    
    return 0;
}
