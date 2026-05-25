#include <iostream>
#include <vector>
#include <string>

using namespace std;

string triangleType(int a, int b, int c){
    if (a < 1 || a > 100 || b < 1 || b > 100 || c < 1 || c > 100){
        return "Invalid Input";
    }

    if (!(a + b > c && a + c > b && b + c > a)){
        return "Not a Triangle";
    }

    if (a == b && b == c){
        return "Equilateral";
    }

    if (a == b || b == c || a == c){
        return "Isosceles";
    }

    return "Scalene";
}

struct TestCase {
    int a, b, c;
    string expected;
};

int main(){
    vector<TestCase> testSuite = {
        {0, 5, 5, "Invalid Input"},
        {101, 5, 5, "Invalid Input"},
        {5, -1, 5, "Invalid Input"},
        {5, 5, 101, "Invalid Input"},

        {1, 1, 1, "Equilateral"},
        {100, 100, 100, "Equilateral"},
        {1, 2, 3, "Not a Triangle"},
        {99, 100, 100, "Isosceles"},

        {3, 3, 3, "Equilateral"},
        {5, 5, 3, "Isosceles"},
        {5, 3, 5, "Isosceles"},
        {3, 5, 5, "Isosceles"},
        {4, 5, 6, "Scalene"},
        {1, 2, 10, "Not a Triangle"},
        {7, 3, 3, "Not a Triangle"}
    };

    int passed = 0;

    for (int i = 0; i < testSuite.size(); i++){
        string actual = triangleType(
            testSuite[i].a,
            testSuite[i].b,
            testSuite[i].c
        );

        cout << "TestCase " << i + 1 << ": ("
             << testSuite[i].a << ", "
             << testSuite[i].b << ", "
             << testSuite[i].c << ")"
             << endl;

        cout << "Expected: " << testSuite[i].expected << endl;

        cout << "Actual:   " << actual << endl;

        if (actual == testSuite[i].expected){
            cout << "Result: PASSED" << endl;
            passed++;
        }
        else{
            cout << "Result: FAILED" << endl;
        }
        
        cout << "------------------------" << endl;
    }

    cout << "Passed: " << passed << "/" << testSuite.size() << endl;
    return 0;
}