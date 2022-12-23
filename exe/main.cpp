#include "algo.hpp"
#include <vector>
#include <iostream>
#include <fstream>

const int max_nums = 3;

class GreaterZero {
public:
    bool operator()(int a) {
        return a > 0;
    }
};

std::vector <int> get_vector(std::istream &fin) {
    unsigned int n = 0;
    fin >> n;
    std::vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
    return std::move(arr);
}

void calculate_mismatch(const std::string& filename) {
    std::ifstream fin;
    fin.open(filename);
    std::vector <int> arr1 = get_vector(fin);
    std::vector <int> arr2 = get_vector(fin);
    std::pair <std::vector<int>::iterator, 
               std::vector<int>::iterator> mismatch_arrs = cust_mismatch(
                    arr1.begin(), arr1.end(), 
                    arr1.begin(), arr2.end());
    std::cout << "Length of equal part is: " << mismatch_arrs.first - arr1.begin() << std::endl;
}

void check_all_of(const std::string& filename) {
    std::ifstream fin;
    fin.open(filename);
    GreaterZero pred;
    std::vector <int> arr = get_vector(fin);
    if (cust_all_of(arr.begin(), arr.end(), pred)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    unsigned int mask = atoi(argv[1]);
    std::string filename = argv[2];
    
    if ((mask & 1)) {
        check_all_of(filename);
    }

    if ((mask & (1 << 1))) {
        calculate_mismatch(filename);
    }
    
    return 0;
}