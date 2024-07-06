#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Player {
public:
    string name;
    int score;

    Player(const string& n) : name(n), score(0) {}
};

class BadmintonMatch {
public:
    BadmintonMatch(const string& player1Name, const string& player2Name)
        : player1(player1Name), player2(player2Name) {}

    void displayMenu() {
        cout << endl<<"Badminton Score Tracker Menu:"<<endl;
        cout << "1. Add Point"<<endl;
        cout << "2. Display Score"<<endl;
        cout << "3. Display Match Statistics"<<endl;
        cout << "4. Exit"<<endl;
    }

    void playMatch() {
        int choice;
        while (true) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPoint();
                    break;
                case 2:
                    displayScore();
                    break;
                case 3:
                    displayMatchStatistics();
                    break;
                case 4:
                    cout << "Exiting the program."<<endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again."<<endl;
            }

            if (isMatchOver()) {
                displayWinner();
                return;
            }
        }
    }

private:
    Player player1;
    Player player2;
    int totalPointsPlayer1 = 0;
    int totalPointsPlayer2 = 0;

    void addPoint() {
        string scorer;
        cout << "Enter the name of the player who scored: ";
        cin >> scorer;

        if (scorer == player1.name) {
            player1.score++;
            totalPointsPlayer1++;
        } else if (scorer == player2.name) {
            player2.score++;
            totalPointsPlayer2++;
        } else {
            cout << "Invalid player name. Please try again."<<endl;
            return;
        }

        cout << "Point added to " << scorer << "."<<endl;
        displayScore();
    }

    void displayScore() {
        cout << "\nCurrent Score:\n";
        cout << player1.name << ": " << player1.score << endl;
        cout << player2.name << ": " << player2.score << endl;
    }

    bool isMatchOver() {
        return (player1.score >= 21 && player1.score - player2.score >= 2) ||
               (player2.score >= 21 && player2.score - player1.score >= 2);
    }

    void displayWinner() {
        if (player1.score > player2.score) {
            cout << endl<< player1.name << " wins the match with a score of "
                      << player1.score << " - " << player2.score << "!"<<endl;
        } else {
            cout << endl << player2.name << " wins the match with a score of "
                      << player2.score << " - " << player1.score << "!"<<endl;
        }
    }

    void displayMatchStatistics() {
        cout <<endl<< "Match Statistics:"<<endl;
        cout << player1.name << " - Total Points: " << totalPointsPlayer1 << endl;
        cout << player2.name << " - Total Points: " << totalPointsPlayer2 << endl;
        cout << "Points Difference: " << abs(totalPointsPlayer1 - totalPointsPlayer2) << endl;
    }
};


int main() {
    string player1Name, player2Name;

    cout << "Enter the name of Player 1: ";
    cin >> player1Name;
    cout << "Enter the name of Player 2: ";
    cin >> player2Name;

    BadmintonMatch match(player1Name, player2Name);
    match.playMatch();

    return 0;
}
