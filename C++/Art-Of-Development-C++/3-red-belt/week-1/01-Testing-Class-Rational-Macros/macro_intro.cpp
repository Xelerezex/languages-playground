#include "test_runner.h"
#include "rational.h"


void TestDefaultConstructor() {
    const Rational defaultConstructed;

    ASSERT_EQUAL(defaultConstructed.Numerator(), 0);
    ASSERT_EQUAL(defaultConstructed.Denominator(), 1);
}


void TestConstruction() {
    const Rational r(3, 12);
    ASSERT_EQUAL(r.Numerator(), 1);
    ASSERT_EQUAL(r.Denominator(), 4);

}


int main () {
    TestRunner tr;
    RUN_TEST(tr, TestDefaultConstructor);
    RUN_TEST(tr, TestConstruction);

    return 0;
}
