#include"../../include/tests.hpp"

#include<iostream>
#include<cassert>
#include<vector>
#include<functional>

void tests::test::run_test(){
    std::vector<bool> tests_passed = test_method();

    for(auto test_passed : tests_passed){
        assert(test_passed);
    }
}

tests::test::test(std::function<std::vector<bool>()> test_method){
    this->test_method = test_method;
}