#pragma once
#include "Game.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>   // NEW
using namespace std;

class HangmanGame : public Game
{
private:
    string word;
    string guessed;
    int attempts;

public:
    vector<string> loadWords()
    {
        vector<string> words;
        ifstream file("words.txt");

        string temp;

        if (file.is_open())
        {
            while (getline(file, temp))
            {
                if (!temp.empty())
                    words.push_back(temp);
            }
            file.close();
        }

        if (words.empty())
        {
            words = {"apple", "banana", "computer", "science"};
        }

        return words;
    }

    HangmanGame() : Game("Hangman")
    {
        vector<string> words = loadWords();

        word = words[rand() % words.size()];
        guessed = string(word.length(), '_');
        attempts = word.length() -1;
    }

    void display()
    {
        cout << "Word: " << guessed << endl;
        cout << "Attempts left: " << attempts << endl;
    }

    void play() override
    {
        char ch;

        while (attempts > 0 && guessed != word)
        {
            display();
            cout << "Enter a letter: ";
            cin >> ch;

            bool found = false;

            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == ch)
                {
                    guessed[i] = ch;
                    found = true;
                }
            }

            if (!found)
            {
                attempts--;
                cout << "Wrong guess!\n";
            }
        }

        if (guessed == word)
            cout << "You won GG's dude! You Guessed the word: " << word << endl;
        else
            cout << "Game Over Noob! Word was: " << word << endl;
    }
};