#include <iostream>
#include "ArrayTests.h"
#include "Custom_Array.h"




int main()
{
    // get test objects
    ArrayTests& arrayTestsObj = ArrayTests::getInstance();
    
    // run tests
    arrayTestsObj.runUnitTests();

    return 0;
}
