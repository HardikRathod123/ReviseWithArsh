/*

You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

*/


class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> guessed(10, 0);
        vector<int> secretKeys(10, 0);
        int cows = 0, bulls = 0; 
        for(int i = 0; i < guess.size(); i++){
            if(guess[i] == secret[i]) cows++;
            else{
                int currentGuess = guess[i] - '0';
                int currentSecret = secret[i] - '0';
                guessed[currentSecret]++;
                secretKeys[currentGuess]++;
            }
        }
        
        for(int i = 0; i < 10; i++) bulls += min(guessed[i], secretKeys[i]);
            
        return to_string(cows) + "A" + to_string(bulls) +"B";    
    }
};
