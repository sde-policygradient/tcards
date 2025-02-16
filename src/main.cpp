#include<iostream>
#include<functional>

#include"../include/cards.hpp"

class test{
    private:
        std::string test_name;
        std::function<std::vector<bool>()> test_method;
    public:
        void run_tests(){
            std::vector<bool> tests_passed = test_method();

            for(size_t i = 0; i < tests_passed.size(); ++i){
                bool test_passed = tests_passed[i];

                std::cout << (test_passed ? "\x1b[92m" : "\x1b[91;1m");
                std::cout << test_name + "-" << i << (test_passed ? ": passed" : ": failed") << "\x1b[0m\n";
            }
        }

        test(std::string test_name, std::function<std::vector<bool>()> test_method){
            this->test_name = test_name;
            this->test_method = test_method;
        }
};

std::vector<bool> test_card(){
    std::vector<bool> out;
    cards::card test_card = cards::card(cards::DIAMONDS, cards::JACK);

    out.push_back(test_card.suit_str() == "diamonds");
    out.push_back(test_card.value_str() == "jack");

    return out;
}

int main(int argc, char **argv){
    test card("Card class", test_card);

    card.run_tests();
    exit(EXIT_SUCCESS);
}