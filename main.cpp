#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getComputerChoice() {
    int randomNum = rand() % 3;
    if (randomNum == 0) return "Rock";
    if (randomNum == 1) return "Paper";
    return "Scissors";
}
int determineWinner(string playerChoice, string computerChoice) {
    if (playerChoice == computerChoice) return 0;
    if ((playerChoice == "Rock" && computerChoice == "Scissors") ||
        (playerChoice == "Scissors" && computerChoice == "Paper") ||
        (playerChoice == "Paper" && computerChoice == "Rock")) {
        return 1;
    }
    return -1;
}
int main() {
    srand(time(0));
    int playerScore = 0, computerScore = 0;
    string playerChoice;
    char playAgain;
    cout << "Welcome to the Rock, Paper, Scissors Tournament!" << endl;
    do {
        cout << "\nEnter Rock, Paper, or Scissors: ";
        cin >> playerChoice;
        for (char &c : playerChoice) c = tolower(c);
        if (playerChoice == "rock") playerChoice = "Rock";
        else if (playerChoice == "paper") playerChoice = "Paper";
        else if (playerChoice == "scissors") playerChoice = "Scissors";
        else {
            cout << "Invalid choice! Please enter Rock, Paper, or Scissors.\n";
            continue; }
        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        int result = determineWinner(playerChoice, computerChoice);
        if (result == 1) {
            cout << "You win this round!" << endl;
            playerScore++;
        } else if (result == -1) {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        } else {
            cout << "This round is a draw!" << endl;
        }
        cout << "Score -> You: " << playerScore << " | Computer: " << computerScore << endl;        
        cout << "Do you want to play another round? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "\nTournament Over!" << endl;
    cout << "Final Score -> You: " << playerScore << " | Computer: " << computerScore << endl;
    if (playerScore > computerScore) {
        cout << "Congratulations! You win the tournament!" << endl;
    } else if (playerScore < computerScore) {
        cout << "Computer wins the tournament! Better luck next time." << endl;
    } else {
        cout << "The tournament ends in a draw!" << endl;
    }
    return 0;
}
