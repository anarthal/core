//
// Test for BOOST_TEST_WITH
//
// Copyright (c) 2020 Bjorn Reese
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//

#include <cmath>
#include <functional>
#include <vector>
#include <boost/core/lightweight_test.hpp>

template <typename T>
struct with_tolerance
{
    with_tolerance(T tolerance) : tolerance(tolerance) {}
    bool operator()(T lhs, T rhs)
    {
        return (std::abs(lhs - rhs) <= tolerance);
    }

private:
    T tolerance;
};

void test_tolerance_predicate()
{
    BOOST_TEST_WITH( 1.0, 1.0, with_tolerance<double>(1e-5) );
    BOOST_TEST_WITH( 1.0, 1.0 - 1e-6, with_tolerance<double>(1e-5) );
    BOOST_TEST_WITH( 1.0, 1.0 + 1e-6, with_tolerance<double>(1e-5) );
}

int main()
{
    test_tolerance_predicate();

    return boost::report_errors();
}
