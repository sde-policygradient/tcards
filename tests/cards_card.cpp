#include"../include/tests.hpp"
#include"../include/cards.hpp"

std::vector<bool> test_card(){
    std::vector<bool> tests_passed;
    cards::card test_card(cards::DIAMONDS, cards::JACK);

    tests_passed.push_back(test_card.suit_str() == "diamonds");
    tests_passed.push_back(test_card.value_str() == "jack");

    return tests_passed;
}

int main(int argc, char **argv){
    tests::test card_test(test_card);

    card_test.run_test();
    exit(EXIT_SUCCESS);
}