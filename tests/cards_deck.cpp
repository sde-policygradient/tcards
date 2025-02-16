#include"../include/tests.hpp"
#include"../include/cards.hpp"

std::vector<bool> test_deck(){
    std::vector<bool> tests_passed;
    cards::deck test_deck;

    tests_passed.push_back(test_deck.deck_size() == 52);

    cards::card drawn_card = test_deck.draw();
    tests_passed.push_back(test_deck.deck_size() == 51);
    tests_passed.push_back(drawn_card.suit_str() == "spades" && drawn_card.value_str() == "ace");

    test_deck.clear();
    tests_passed.push_back(!test_deck.deck_size());

    return tests_passed;
}

int main(int argc, char **argv){
    tests::test deck_test(test_deck);

    deck_test.run_test();
    exit(EXIT_SUCCESS);
}