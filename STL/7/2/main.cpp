#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


//  13 ranks: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
//  4 suits: clubs, diamonds, hearts, spades
enum Rank { A = 1, _2, _3, _4, _5, _6, _7, _8, _9, _10, J, Q, K };
enum Suit { clubs = 1, diamonds, hearts, spades };
string rankToString(Rank rank){
    string strings[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    return strings[rank-1];
}
string suitToString(Suit suit) {
    string strings[4] = { "clubs", "diamonds", "hearts", "spades" };
    return strings[suit-1];
}
Rank operator+(const Rank o1, const int o2) {
    int value = (int)o1 + o2; value = value % 13; value ++;
    return static_cast<Rank>(value);
}
Rank operator+=(Rank o1, const int o2) {
    o1 = o1 + o2;
    return o1;
}
Suit operator+(const Suit o1, const int o2) {
    int value = (int)o1 + o2; value = value % 4; value++;
    return static_cast<Suit>(value);
}
Suit operator+=(Suit o1, const int o2) {
    o1 = o1 + o2;
    return o1;
}
class PlayingCard {
private:
    Rank rank;
    Suit suit;
    int player;     //  id of the player that this card has been delt. 0 if it is not dealt
public:
    PlayingCard(Rank _rank, Suit _suit) {
        rank = _rank;
        suit = _suit;
        player = 0;
    }
    PlayingCard(const int index) {
        suit = static_cast<Suit>(index % 4); suit += 1;
        rank = static_cast<Rank>(index % 13); rank += 1;
        player = 0;
    }
    static PlayingCard indexToCard(const int index) {
        Suit _suit = static_cast<Suit>(index % 4); _suit += 1;
        Rank _rank = static_cast<Rank>(index % 13); _rank += 1;
        return PlayingCard(_rank, _suit);
    }
    const int index() const {
        int ret = (rank-1) * (suit) + (suit-1);
        return ret;
    }
    void dealCardToPlayer(const int player) { this->player = player; }
    const int isDealtTo() const { return player; }
    const int points() const {
        int ret = 0;
        ret = this->rank;
        if (this->suit == Suit::hearts) { ret*=2; }
        return ret;
    }
    friend ostream& operator<<(ostream& os, const PlayingCard& card) {
        os << rankToString(card.rank) << " of " << suitToString(card.suit);
        return os;
    }
};
class Deck {
private:
    vector<PlayingCard> cards;
public:
    Deck(){
        for (int i=0; i<52; i++) {
            cards.push_back(PlayingCard(i));
        }
    }
    PlayingCard& getCard(const int index) { return cards.at(index); }
    void dealCard(const int index, const int player) {
        cards.at(index).dealCardToPlayer(player);
    }
    const int undealtCardsInDeck() const {
        int counter = 0;
        for (int i=0; i<52; i++) {
            if (!cards.at(i).isDealtTo()) { counter++; }
        }
        return counter;
    }
};
class PlayingCardsGame {
private:
    Deck deck;
    int numberOfPlayers;
    vector<int> pointsPerPlayer;
public:
    PlayingCardsGame(const int numberOfPlayers) {
        deck = Deck();
        this->numberOfPlayers = numberOfPlayers;
        pointsPerPlayer = vector<int>(numberOfPlayers+1);
        dealCards();
    }
    const int getNumberOfPlayers() const { return numberOfPlayers; }
    void calculatePoints() {
        for (int i=0; i<52; i++) {
            PlayingCard& card = deck.getCard(i);
            if (!card.isDealtTo()) { throw runtime_error("Card not delt yet"); }
            pointsPerPlayer.at(card.isDealtTo()) += card.points();
        }
    }
    void dealCards() {
        vector<int> cardIndexes(52);
        int start = 0;
        iota(cardIndexes.begin(), cardIndexes.end(), start);
        random_shuffle(cardIndexes.begin(), cardIndexes.end());
        for (int i=0; i<52; i++) {
            deck.dealCard(cardIndexes[i], ((i%numberOfPlayers)+1));
        }
        calculatePoints();
    }
    const int getPointsForPlayer(const int player) {
        return pointsPerPlayer[player];
    }
    const int getWinnerPlayer() {
        calculatePoints();
        auto max_points = max_element(pointsPerPlayer.begin(), pointsPerPlayer.end());
        int winner = distance(pointsPerPlayer.begin(), max_points);
        return winner;
    }
};

int main()
{
    int numberOfPlayers;
    cout << "How many players are playing the game? "; cin >> numberOfPlayers;
    PlayingCardsGame game = PlayingCardsGame(numberOfPlayers);
    game.dealCards();
    int winner = game.getWinnerPlayer();
    cout << "The winner is player " << winner << " with " << game.getPointsForPlayer(winner) << " points" << endl;
    return 0;
}
