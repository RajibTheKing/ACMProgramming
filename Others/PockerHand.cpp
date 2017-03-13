#include<bits/stdc++.h>

using namespace std;

class Card
{
    char name;
    int value;
    int type;
};


class Player
{
    Card cards[5];
    int handStrength;
};

bool cardSortCriteria(Card a, Card b)
{
    return a.value<b.value;
}
int getHandStrength(Card cards[])
{
    sort(cards, cards+5, cardSortCriteria);
}
int main()
{

}
