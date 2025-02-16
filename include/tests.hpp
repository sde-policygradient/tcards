#include<iostream>
#include<cassert>
#include<vector>
#include<functional>

namespace tests{

class test{
    private:
        std::function<std::vector<bool>()> test_method;
    public:
        void run_test();

        test(std::function<std::vector<bool>()> test_method);
};

}