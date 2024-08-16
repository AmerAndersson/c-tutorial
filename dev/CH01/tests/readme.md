# Tests


## Manual Testing Approach
Create a Test File:
Create a separate C file for your tests, usually named something like test_<module>.c.

## Include Your Header File:
Include the header file of the module you're testing.

## Write Test Functions:
Write functions that test specific functionalities. Each function should set up the necessary conditions, call the function being tested, and then check the result.

## Check Results:
Use assert or custom macros to check if the results are as expected.

## Main Function:
Create a main function that calls all your test functions.

## Using a Testing Framework
Using a testing framework like CUnit, Unity, or Check can make your tests more organized and easier to run. Here's an example using Unity:

## Install Unity:
Download Unity from the Unity GitHub repository.

## Create Test File:
Create a test file, e.g., test_mymodule.c.

## Include Unity and Your Header File:
Include the Unity framework and the header file of the module you're testing.

## Write Test Functions:
Use the Unity macros for setting up and tearing down tests, and for checking results.

## Main Function:
Use Unity's test runner to run all your test functions.

## Manual Testing:
gcc -o test_mymodule test_mymodule.c mymodule.c
./test_mymodule

## With Unity:
gcc -o test_mymodule test_mymodule.c mymodule.c unity.c
./test_mymodule