#include <string>

using namespace std;

int returnID(string word)
{
    int len = word.length();
    int noOfAnimals = 4;
    string animals[4] = {"dog", "cat", "mouse", "pass"};
    int counter;
    int counterTwo = 1;
    for (int k = 0; k < noOfAnimals; k++)
    {
        counter = 0;
        if (len == animals[k].length())
        {
            for (int i = 0; i < len; i++)
            {
                //if any letter in the word entered is uppercase, change it to lowercase
                if (isupper(word[i]))
                {
                    word[i] = tolower(word[i]);
                }
                if (word[i] != animals[k][i])
                {
                    counter++;
                }
            }
            if (counter == 0)
            {
                return counterTwo;
            }
        }
        counterTwo++;
    }
    return 99;
}