#include <iostream>
#include "Timer.h"
using namespace std;

int main(int argc, char* argv[])
{
    Timer t;

    t.Start();
    t.Stop();

    cout << Timer::Resolution().S() << endl;
    cout << t.Duration().NS() << endl;
    cout << t.Duration().S() << endl;

    return 0;
}

