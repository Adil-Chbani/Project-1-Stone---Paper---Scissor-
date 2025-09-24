#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum EnPlayers { Stone = 1, Paper = 2, Scissors = 3 };

int ReadNumber(string Message) {
    int Number = 0;
    do {
        cout << Message;
        cin >> Number;
    } while (Number < 0 || Number > 10);
    return Number;
}

int GetRandomPlayrs(int from, int to) {
    return (rand() % (to - from + 1) + from);
}

int GetValueComputer() {
    return GetRandomPlayrs(1, 3);
}

int GetValuePlyer(int index) {
    cout << "Round [" << index + 1 << "] begins " << endl;
    int ValuePlayar = ReadNumber("Your Choice : [1]:Stone , [2]:Paper , [3]:Scissors ? ");
    return ValuePlayar;
}

EnPlayers CheckNumberPlaysWithEnum(int NumberChoice) {
    if (NumberChoice == EnPlayers::Stone) return EnPlayers::Stone;
    else if (NumberChoice == EnPlayers::Paper) return EnPlayers::Paper;
    else return EnPlayers::Scissors;
}

string GetPlayarVSComputer(int Number, int &ValuePlayar, int &ValueComputer) {
    string Result = "";
    for (int i = Number; i <= Number; i++) {
        ValueComputer = GetValueComputer();
        ValuePlayar = GetValuePlyer(i);

        cout << "computer : " << ValueComputer << endl;
        cout << "Player : " << ValuePlayar << endl;

        int ResultFinalValueComputer = CheckNumberPlaysWithEnum(ValueComputer);
        int ResultFinalValuePlayer = CheckNumberPlaysWithEnum(ValuePlayar);

        if (ResultFinalValueComputer > ResultFinalValuePlayer) {
            if (ResultFinalValueComputer == EnPlayers::Scissors) {
                if (ResultFinalValuePlayer == EnPlayers::Paper) Result = "Computer";
                else if (ResultFinalValuePlayer == EnPlayers::Stone) Result = "Player";
            } else {
                if (ResultFinalValueComputer > 1) Result = "Computer";
            }
        } else if (ResultFinalValueComputer < ResultFinalValuePlayer) {
            if (ResultFinalValuePlayer == EnPlayers::Scissors) {
                if (ResultFinalValueComputer == EnPlayers::Paper) Result = "Player";
                else Result = "Computer";
            } else {
                if (ResultFinalValuePlayer > EnPlayers::Stone) Result = "Player";
            }
        } else {
            Result = "No Winner";
        }
    }
    return Result;
}

void TracerTableauFinal(int GameRounds, int NumberPlayrsUser, int NumberPlayComputer, int NumberNoWinner, string WhyWinner) {
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t\t\t ________________________________________________________________________________\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t\t +++ G a m e O v e r +++\n";
    cout << "\t\t\t\t\t\t\t\t _________________________________________________________________________________\n\n";
    cout << "\t\t\t\t\t\t\t\t______________________________ [ Game Results ]___________________________________\n";
    cout << "\t\t\t\t\t\t\t\t Game Rounds : " << GameRounds << endl;
    cout << "\t\t\t\t\t\t\t\t Player1 Won times : " << NumberPlayrsUser << endl;
    cout << "\t\t\t\t\t\t\t\t Computer Won times : " << NumberPlayComputer << endl;
    cout << "\t\t\t\t\t\t\t\t Draw time : " << NumberNoWinner << endl;
    cout << "\t\t\t\t\t\t\t\t Final Winner : " << WhyWinner << endl;
    cout << "\t\t\t\t\t\t\t\t ________________________________________________________________________________\n\n";
}

void PlayersAgain();

void TracerTableau(int index, int PlayerPlay, int ComputerPlay, string WhyWinner) {
    if (WhyWinner == "Player") cout << "\033[42;97m";
    else if (WhyWinner == "Computer") cout << "\033[41;97m";
    else cout << "\033[43;97m";

    cout << "__________Round [" << index + 1 << "]__________" << endl;
    
    cout << "Player1 Choice : ";
    if (PlayerPlay == EnPlayers::Paper) cout << "Paper" << endl;
    else if (PlayerPlay == EnPlayers::Stone) cout << "Stone" << endl;
    else cout << "Scissors" << endl;

    cout << "Computer Choice : ";
    if (ComputerPlay == EnPlayers::Paper) cout << "Paper" << endl;
    else if (ComputerPlay == EnPlayers::Stone) cout << "Stone" << endl;
    else cout << "Scissors" << endl;

    cout << "Round Winner : [" << WhyWinner << "]" << endl;
    cout << "___________________________________________" << endl;
    cout << "\033[0m";
}

void ResultFinal(int Number, int &ValuePlayar, int &ValueComputer) {
    int Player = 0, Computer = 0, NoWinner = 0;
    for (int i = 0; i < Number; i++) {
        string WHyWinner = GetPlayarVSComputer(i, ValuePlayar, ValueComputer);
        TracerTableau(i, ValuePlayar, ValueComputer, WHyWinner);
        if (WHyWinner == "Player") Player++;
        else if (WHyWinner == "Computer") Computer++;
        else NoWinner++;
    }

    if (Player > Computer) {
        cout << "\033[42;97m";
        TracerTableauFinal(Number, Player, Computer, NoWinner, "Player");
        cout << "\033[0m";
    } else if (Player < Computer) {
        cout << "\033[41;97m";
        TracerTableauFinal(Number, Player, Computer, NoWinner, "Computer");
        cout << "\033[0m";
    } else {
        cout << "\033[43;97m";
        TracerTableauFinal(Number, Player, Computer, NoWinner, "No Winner");
        cout << "\033[0m";
    }
    PlayersAgain();
}

void StartProject() {
    int Number = ReadNumber("How Many Rounds 1 to 10 ? ");
    int valuePl = 0, ValueCom = 0;
    ResultFinal(Number, valuePl, ValueCom);
}

void PlayersAgain() {
    string Letter = "";
    cout << "\n\t\t\t\t\t\t\t\tDo You want to play again ? Y/N ? ";
    cin >> Letter;
    if (Letter == "y" || Letter == "Y") {
        system("clear");
        StartProject();
    } else {
        cout << "\nGoodBay 🫣 \n";
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    int Number = ReadNumber("How Many Rounds 1 to 10 ? ");
    int valuePl = 0, ValueCom = 0;
    ResultFinal(Number, valuePl, ValueCom);

    //finish
}
