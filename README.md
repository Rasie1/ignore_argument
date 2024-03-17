# Ignore Argument

A useful C++ tool for ignoring return arguments when dealing with old C++ code.

- Provides extra safety tools when arguments change (prevents changing between input and output arguments, prevents implicit casts)

- Generates less instructions on modern compilers

- Looks much cleaner and doesn't require additional identifiers

- Optionally typed

## Example Usage

```c++
#include "ignore_argument.h"

void myFunctionA(int& t) { t = 3; }
void myFunctionB(int t) { t = 3; }
void myFunctionC(bool& t) { t = 3; }

int main()
{
    printf("Hello World");
    myFunctionA(ignore_argument{});
    myFunctionA(ignore_argument<int>{});
    // myFunctionB(ignore_argument<int>{}); // error
    // myFunctionC(ignore_argument<int>{}); // error

    return 0;
}
```