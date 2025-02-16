#include"../../include/cards.hpp"

#include<list>
#include<vector>
#include<random>

std::string string_lookup(const size_t index, const std::vector<std::string> lookup_table){
    try{
        return lookup_table.at(index);
    }catch(...){
        return "";
    }
}

std::string cards::card::suit_str(){
    const std::vector<std::string> suit_lookup = {"clubs", "diamonds", "hearts", "spades"};

    return string_lookup(this->suit, suit_lookup);
}

std::string cards::card::value_str(){
    const std::vector<std::string> value_lookup = {"two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};

    return string_lookup(this->value, value_lookup);
}

cards::card::card(const enum cards::suits &&suit, const enum cards::values &&value){
    this->suit = suit;
    this->value = value;
}

size_t cards::deck::deck_size(){
    return this->cards.size();
}

void cards::deck::clear(){
    this->cards.clear();
}

void cards::deck::shuffle(){
    size_t deck_size = this->cards.size();
    std::list<cards::card> shuffled_deck;

    for(size_t i = 0; i < deck_size; ++i){
        size_t pop_position = std::rand() % this->cards.size();
        auto pop_iterator = this->cards.begin();

        std::advance(pop_iterator, pop_position);

        shuffled_deck.push_back(*pop_iterator);
        this->cards.erase(pop_iterator);
    }

    this->cards.swap(shuffled_deck);
}

cards::card cards::deck::draw(){
    cards::card drawn_card = this->cards.back();

    this->cards.pop_back();
    return drawn_card;
}

void cards::deck::insert(cards::card &card){
    this->cards.push_front(card);
}

cards::deck::deck(){
    for(size_t i = 0; i <= SPADES; ++i){
        for(size_t j = 0; j <= ACE; ++j){
            this->cards.push_back(cards::card(static_cast<enum cards::suits>(i), static_cast<enum cards::values>(j)));
        }
    }
}