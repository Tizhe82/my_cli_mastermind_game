# Welcome to My Mastermind
***

## Task
Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

You must read the player's input from the standard input.

Your program will also receive the following parameters:
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

## Description
Read Secret codes from the stdin and if it's expected piceces (That's between 0-8).
If None is provide, 4 random secret code will be generated against which the user's guess would be compared.
Only 4 digit is expected as a secret codes. if more than four pieces is given only the first 4 will be considered.
The user's guess is taken and compare with the secret code. The number of well placed and misplaced is produced every attempt.
If all the User's input are well placed, the user will get a congratulatory message.

## Installation
No Installation
Clone the repo after cloning the repository follow the rules in the Usage section to play the game 

## Usage
run `make -f makefile ` to generate my_mastermind executable file.

code: can be any 4 digits between 0 - 8

```
./my_mastermind -c "code"
```

Want to play without secret codes?

```
./my_mastermind
```

### The Core Team

Tizhe Paul


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
