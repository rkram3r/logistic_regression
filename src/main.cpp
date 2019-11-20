#include "cute.h"
#include "cute_runner.h"
#include "cute_counting_listener.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "logistic_regression.h"
#include <iostream>

double pow(double euler, double sum)
{
    return sum;
}

void test_intercept()
{
    double coef[1]{0};
    double test[1]{0};
    auto log = logistic_regression{0.5, coef, 0, 0, pow};
    ASSERT_EQUAL(2, log.predict(test));
}

void test_multiplication()
{
    double coef[3]{1, 1, 1};
    double test[3]{1, 1, 1};
    auto log = logistic_regression{0, coef, 3, 0, pow};
    ASSERT_EQUAL(3, log.multiply_and_sum(test));
}

void test_multiplication_char()
{
    double coef[3]{1, 1, 1};
    unsigned char test[3]{1, 1, 1};
    auto log = logistic_regression{0, coef, 3, 0, pow};
    ASSERT_EQUAL(3, log.multiply_and_sum(test));
}

void test_multiplication_unsigned_char()
{
    double coef[3]{1, 1, 1};
    char test[3]{1, 1, 1};
    auto log = logistic_regression{0, coef, 3, 0, pow};
    ASSERT_EQUAL(3, log.multiply_and_sum(test));
}

int main(int argc, char const *argv[])
{
    using namespace std;
    cute::suite s;
    s.push_back(test_intercept);
    s.push_back(test_multiplication);
    s.push_back(test_multiplication_char);
    s.push_back(test_multiplication_unsigned_char);
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::counting_listener<cute::ide_listener<>>> l(xmlfile.out);
    cute::makeRunner(l, argc, argv)(s, "all cute tests");
    cout << flush;
    cerr << flush;
    cerr << l.numberOfTests << " Tests - expect " << s.size() << endl;
    cerr << l.failedTests << " failed - expect 0 failures" << endl;
    cerr << l.errors << " errors - expect 0 errors" << endl;
    return int(l.failedTests); //silence warning
}
