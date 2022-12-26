#include <gtest/gtest.h>
#include <vector>
#include "algo.hpp"

class GreaterZero {
public:
    bool operator()(int a) {
        return a > 0;
    }
};

TEST(TestAlgo, all_of) {
    std::vector <int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    ASSERT_TRUE(cust_all_of(a.begin(), a.end(), GreaterZero()));
    a[0] = -1;
    ASSERT_FALSE(cust_all_of(a.begin(), a.end(), GreaterZero()));
}

TEST(TestAlgo, any_of) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = 2;
    a[2] = 3;
    ASSERT_TRUE(cust_any_of(a.begin(), a.end(), GreaterZero()));
    a[1] = -1;
    a[2] = -1;
    ASSERT_FALSE(cust_any_of(a.begin(), a.end(), GreaterZero()));
}


TEST(TestAlgo, none_of) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = -2;
    a[2] = -3;
    ASSERT_TRUE(cust_none_of(a.begin(), a.end(), GreaterZero()));
    a[0] = 1;
    ASSERT_FALSE(cust_none_of(a.begin(), a.end(), GreaterZero()));
}

TEST(TestAlgo, count) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = -2;
    a[2] = -3;
    ASSERT_EQ(cust_count(a.begin(), a.end(), 1), 0);
    a[0] = 1;
    a[2] = 1;
    ASSERT_EQ(cust_count(a.begin(), a.end(), 1), 2);
}

TEST(TestAlgo, count_if) {
    std::vector <int> a(3);
    a[0] = -1;
    a[1] = -2;
    a[2] = -3;
    ASSERT_EQ(cust_count_if(a.begin(), a.end(), GreaterZero()), 0);
    a[0] = 1;
    a[2] = 1;
    ASSERT_EQ(cust_count_if(a.begin(), a.end(), GreaterZero()), 2);
}

TEST(TestAlgo, mismatch) {
    std::vector <int> a{-1, -2, -3}, b{-1, -2, -4};

    ASSERT_EQ(cust_mismatch(a.begin(), a.end(), b.begin(), b.end()), 
              std::make_pair(a.begin() + 2, b.begin() + 2));
    b[2] = -3;
    ASSERT_EQ(cust_mismatch(a.begin(), a.end(), b.begin(), b.end()), 
              std::make_pair(a.end(), b.end()));
    a[0] = 1;
    ASSERT_EQ(cust_mismatch(a.begin(), a.end(), b.begin(), b.end()), 
              std::make_pair(a.begin(), b.begin()));
}

TEST(TestAlgo, find) {
    std::vector <int> a{-1, -2, -3};

    ASSERT_EQ(cust_find(a.begin(), a.end(), -1), a.begin());
    ASSERT_EQ(cust_find(a.begin(), a.end(), -2), a.begin() + 1);
    ASSERT_EQ(cust_find(a.begin(), a.end(), 0), a.end());
    
}

