#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  string userChoice;
  cout << "Choose rock, paper, or scissors: ";
  getline(cin, userChoice);
  string computerChoice;
  int randomNumber = rand() % 3;
  switch (randomNumber) {
    case 0:
      computerChoice = "rock";
      break;
    case 1:
      computerChoice = "paper";
      break;
    case 2:
      computerChoice = "scissors";
      break;
  }
  cout << "You chose: " << userChoice << endl;
  cout << "The computer chose: " << computerChoice << endl;

  if (userChoice == computerChoice) {
    cout << "It's a tie!" << endl;
  } else if ((userChoice == "rock" && computerChoice == "scissors") || (userChoice == "paper" && computerChoice == "rock") || (userChoice == "scissors" && computerChoice == "paper")) {
    cout << "You win!" << endl;
  } else {
    cout << "The computer wins!" << endl;
  }
  return 0;
}