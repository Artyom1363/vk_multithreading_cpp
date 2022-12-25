#pragma once
#include <cstddef>
#include <utility>


template <class InputIt, class UnaryPredicate>
bool cust_all_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (!p(*first)) {
            return false;
        }
    }
    return true;
}

template <class InputIt, class UnaryPredicate>
bool cust_any_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (p(*first)) {
            return true;
        }
    }
    return false;
}

template <class InputIt, class UnaryPredicate>
bool cust_none_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (p(*first)) {
            return false;
        }
    }
    return true;
}


template<class InputIt, class T>
size_t cust_count(InputIt first, InputIt last, const T& value) {
   size_t cnt = 0;
    for (; first != last; ++first)
        if (*first == value) {
            ++cnt;
        }
    return cnt;
}


template<class InputIt, class UnaryPredicate>
size_t cust_count_if(InputIt first, InputIt last, UnaryPredicate p) {
    size_t cnt = 0;
    for (; first != last; ++first)
        if (p(*first)) {
            ++cnt;
        }  
    return cnt;
}

template<class InputIt1, class InputIt2>
std::pair<InputIt1, InputIt2> 
cust_mismatch(InputIt1 first1, InputIt1 last1, 
              InputIt2 first2, InputIt2 last2) {
    while (first1 != last1 && first2 != last2 && *first1 == *first2) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

template<class InputIt, class T>
InputIt cust_find(InputIt first, InputIt last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}