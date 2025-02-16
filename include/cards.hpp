/**
 * @file cards.hpp
 * 
 * @brief Implements basic functionality for playing cards.
 */

#include<list>
#include<queue>
#include<array>
#include<random>

namespace cards{

/**
 * @brief Card suits.
 */
enum suits{CLUBS, DIAMONDS, HEARTS, SPADES};

/**
 * @brief Card values.
 */
enum values{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING,
    ACE
};

/**
 * @brief Class representing a card.
 */
class card{
    private:
        enum suits suit;
        enum values value;

    public:
        card(const enum suits &&suit, const enum values &&value);

        std::string suit_str();
        std::string value_str();
};

/**
 * @brief Class representing a deck of cards.
 */
class deck{
    private:
        std::list<card> cards;

    public:
        void clear();
        void shuffle();

        card draw();
        void insert(card &card);

        deck();
};

}