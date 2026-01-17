#include "game.h"
#include <iostream>
using namespace std;
Game::Game(int i)
{
    maxNumber = i;
    srand(time(nullptr));
    randomNumber = rand() % i + 1;
    cout << "GAME CONSTRUCTOR: OBJECT INITIALIZED WITH " << i << " AS A MAXIMUM VALUE" <<endl;
    return;
}
void Game::play()
{
    cout << "Anna numero arvaus 1-" << maxNumber <<":" <<endl;
    cin >> playerGuess;
    while(playerGuess!=randomNumber)
    {
        if(playerGuess<randomNumber)
        {
            cout << "Arvaus on liian pieni, anna uusi arvaus" << endl;
            cin >> playerGuess;
            numOfGuesses++;
        }
        else if(playerGuess>randomNumber)
        {
            cout << "Arvaus on liian iso, anna uusi arvaus" << endl;
            cin >> playerGuess;
            numOfGuesses++;
        }
    }
    printGameResult();
    return;
}
void Game::printGameResult()
{
    if(playerGuess==randomNumber)
    {
        cout << "Oikein!!" << endl;
        cout << "Vastaus = " << playerGuess << endl;
        cout << "arvausten maara = " << numOfGuesses << endl;
    }
    return;
}
Game::~Game()
{
    cout << "GAME DESTRUCTOR: OBJECT CLEARED FROM STACK MEMORY" << endl;
    getchar();
}
