// diamonds (♦), clubs (♣), hearts (♥) and spades (♠)

// High Card: Highest value card.
// One Pair: Two cards of the same value.
// Two Pairs: Two different pairs.
// Three of a Kind: Three cards of the same value.
// Straight: All cards are consecutive values.
// Flush: All cards of the same suit.
// Full House: Three of a kind and a pair.
// Four of a Kind: Four cards of the same value.
// Straight Flush: All cards are consecutive values of same suit.
// Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

// The cards are valued in the order:
// 2, 3, 4, 5, 6, 7, 8, 9, 10(T), Jack, Queen, King, Ace.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream poker_hands_file("p054_poker.txt");

int val2num(int c)
{
    switch (c)
    {
    case 84: //T
        return 10;
    case 74: //J
        return 11;
    case 81: //Q
        return 12;
    case 75: //K
        return 13;
    case 65: // A
        return 14;
    default:
        return c - 48;
    }
}

bool compare_values(char a, char b)
{
    return val2num(a) > val2num(b);
}

string getSuits(string h)
{
    return string({h[1], h[4], h[7], h[10], h[13]});
}

string getValues(string h)
{
    return string({h[0], h[3], h[6], h[9], h[12]});
}

bool isFlush(string h) //6
{
    string suits = getSuits(h);
    return adjacent_find(suits.begin(), suits.end(), not_equal_to<char>()) == suits.end();
}

// найти первые две карты которые номиналы которых отличаются не на 1
bool isStraight(string h) //5
{
    string vals = getValues(h);
    sort(vals.begin(), vals.end(), compare_values);
    return adjacent_find(vals.begin(), vals.end(), [](char a, char b) {
        return val2num(a) != val2num(b) + 1;
    }) == vals.end();
}

bool isStraightFlush(string h) //9
{
    return isFlush(h) && isStraight(h);
}

char highCard(string h) {
    string vals = getValues(h);
    sort(vals.begin(), vals.end(), compare_values);
    return vals[0];
}

bool isRoyalFlush(string h) //10
{
    return isStraight(h) && isFlush(h) && highCard(h) == 'A';
}

bool isFourOfAKind(string h) //8
{
    string vals = getValues(h);
    sort(vals.begin(), vals.end(), compare_values);
    auto i = adjacent_find(vals.begin(), vals.end(), equal_to<char>());
    auto j = adjacent_find(i, vals.end(), not_equal_to<char>());
    return distance(i,j) == 4;
}


string isFullHouse(string h) //7
{   
    string vals = getValues(h);
    sort(vals.begin(), vals.end());
    if (!isFourOfAKind(h) && distance(vals.begin(), unique(vals.begin(),vals.end())) == 2)
    {
        auto i = adjacent_find(vals.begin(), vals.end(), not_equal_to<char>());
        return string({vals[0]}) + string(i + 1, i + 2);
    }
    else 
        return "";
}

string isThreeOfAKind(string h) //4
{
    string vals = getValues(h);
    sort(vals.begin(), vals.end(), compare_values);
    auto i = adjacent_find(vals.begin(), vals.end(), equal_to<char>());
    auto j = adjacent_find(i, vals.end(), not_equal_to<char>());
    return distance(i,j) == 2 && isFullHouse(h) == "" 
        ? string(i, i+1) 
        : "";
}

string isTwoPairs(string h) //8
{
    string vals = getValues(h);
    sort(vals.begin(), vals.end());
    auto i = adjacent_find(vals.begin(), vals.end());
    if (i == vals.end()) return "";
    auto j = adjacent_find(i + 1, vals.end());
    if (j == vals.end()) return "";
    return isThreeOfAKind(h) == "" && !isFourOfAKind(h) && isFullHouse(h) == "" 
        ? string(i, i + 1) + string(j, j + 1)
        : ""; 
}

string isPair(string h) //9
{
    string vals = getValues(h);
    sort(vals.begin(), vals.end());
    auto i = adjacent_find(vals.begin(), vals.end());
    return isTwoPairs(h) == "" && isThreeOfAKind(h) == "" && isFullHouse(h) == "" && i != vals.end()
     ? string(i, i+1)
     : "";
}



bool compareHands(string h1, string h2)
{
    if (isRoyalFlush(h1)) return true;
    if (isRoyalFlush(h2)) return false;

    if (isStraightFlush(h1) && !isStraightFlush(h2)) return true;
    else if (!isStraightFlush(h1) && isStraightFlush(h2)) return false;
    else if (isStraightFlush(h1) && isStraightFlush(h2)) return val2num(highCard(h1)) > val2num(highCard(h2));

    if (isFourOfAKind(h1) && !isFourOfAKind(h2)) return true;
    else if (!isFourOfAKind(h1) && isFourOfAKind(h2)) return false;
    else if (isFourOfAKind(h1) && isFourOfAKind(h2)) return val2num(highCard(h1)) > val2num(highCard(h2));

    if (isFullHouse(h1) != "" && isFullHouse(h2) == "") return true;
    else if (isFullHouse(h1) == "" && isFullHouse(h2) != "") return false;
    else if (isFullHouse(h1) != "" && isFullHouse(h2) != "") {
        if (val2num(isFullHouse(h1)[0]) > val2num(isFullHouse(h2)[0])) return true;
        else if (val2num(isFullHouse(h1)[0]) < val2num(isFullHouse(h2)[0])) return false;
        else if (val2num(isFullHouse(h1)[0]) == val2num(isFullHouse(h2)[0]))  
            return val2num(isFullHouse(h1)[1]) > val2num(isFullHouse(h2)[1]);
    }

    if (isFlush(h1) && !isFlush(h2)) return true;
    else if (!isFlush(h1) && isFlush(h2)) return true;
    else if (isFlush(h1) && isFlush(h2)) return val2num(highCard(h1)) > val2num(highCard(h2));

    if (isStraight(h1) && !isStraight(h2)) return true;
    else if (!isStraight(h1) && isStraight(h2)) return true;
    else if (isStraight(h1) && isStraight(h2)) return val2num(highCard(h1)) > val2num(highCard(h2));

    if (isThreeOfAKind(h1) != "" && isThreeOfAKind(h2) == "") return true;
    else if (isThreeOfAKind(h1) == "" && isThreeOfAKind(h2) != "") return false;
    else if (isThreeOfAKind(h1) != "" && isThreeOfAKind(h2) != "") return val2num(isThreeOfAKind(h1)[0]) > val2num(isThreeOfAKind(h2)[0]);
    
    if (isTwoPairs(h1) != "" && isTwoPairs(h2) == "") return true;
    else if (isTwoPairs(h1) == "" && isTwoPairs(h2) != "") return false;
    else if (isTwoPairs(h1) != "" && isTwoPairs(h2) != "") {
        if (val2num(isTwoPairs(h1)[0]) > val2num(isTwoPairs(h2)[0])) return true;
        else if (val2num(isTwoPairs(h1)[0]) < val2num(isTwoPairs(h2)[0])) return false;
        else if (val2num(isTwoPairs(h1)[0]) == val2num(isTwoPairs(h2)[0])) {
            if (val2num(isTwoPairs(h1)[1]) > val2num(isTwoPairs(h2)[1])) return true;
            else if (val2num(isTwoPairs(h1)[1]) < val2num(isTwoPairs(h2)[1])) return false;
            else if (val2num(isTwoPairs(h1)[1]) == val2num(isTwoPairs(h2)[1])) return val2num(highCard(h1)) > val2num(highCard(h2));
        }
    }

    if (isPair(h1) != "" &&  isPair(h2) == "") return true;
    else if (isPair(h1) == "" && isPair(h2) != "") return false;
    else if (isPair(h1) != "" && isPair(h2) != "") return val2num(highCard(h1)) > val2num(highCard(h2));

    return val2num(highCard(h1)) > val2num(highCard(h2));
}

int main()
{

    int result = 0;
    string hand;
    while (getline(poker_hands_file, hand))
    {

        string hand1 = string(hand, 0, 14);
        string hand2 = string(hand, 15, 26);
        if (compareHands(hand1, hand2))
           result++;
    }

    cout << result << endl;
    cin.get();
    return 0; // 376!!!
}
