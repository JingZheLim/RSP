from random import choice # Chooses a Random Word
import string

# State how many wrong guessed before losing 
MAXWRONGGUESS = 6

# Function to select a random word from the words file
def selectWord():
    # mode="r" is for reading
    with open("words.txt", mode="r") as words:
        wordList = words.readlines() # read each line of words and put into the word list
    return choice(wordList).strip() # returns a random word from the word list and strip - removes multiple occurrences of a character 

# Function to validate the player's input
def validateInput(input, guessed):
    # Return true if all are true
    # 1. Exactly one character is entered.
    # 2. The input is a lowercase letter between a and z, inclusive.
    # 3. The input isn’t a letter that the player has already guessed.
    return (
        len(input) == 1
        and input in string.ascii_lowercase
        and input not in guessed
    )

# Function to get player's input (their guessed letters)
def getPlayerInput(guessedLetters):
    # Making sure the player's inputs are valid
    while True:
        playerInput = input("Guess a Letter: ").lower() # Make all letters lowercase
        if validateInput(playerInput, guessedLetters): 
            return playerInput

# builds a single string consisting of the members of the guessedLetters set
def buildGuessedLetter(guessed_letters):
    return " ".join(sorted(guessed_letters))

# Function to return letters that the player has guessed correctly
def buildGuessedWord(correctWord, guessedLetters):
    currentLetters = []
    # for each letter in correct word
    for letter in correctWord:
        # if the letter is part of the correct word is in guessed letters
        if letter in guessedLetters:
            # Add the correct letter to currentLetters
            currentLetters.append(letter)
        # else it isn't part of the word and add _
        else:
            currentLetters.append("_")
    # .join() will include correct letters in their corresponding spots
    return " ".join(currentLetters)

# Function to find out if player loses
def gameOver(wrongGuesses, correctWord, guessedLetters):
    if wrongGuesses == 6:
        return True
    if set(correctWord) <= guessedLetters:
        return True
    return False

# set(correctWord) converts correctWord into a set of unique letters

# def game_over(guesses_taken, target_word, letters_guessed): (this also words)
#     return (
#         guesses_taken == MAX_INCORRECT_GUESSES
#         or set(target_word) <= letters_guessed
#     )

# Draws the man hanging in this order
# Head, Torso, Right Arm, Left Arm, Right Leg, Left Leg,
def hangMan(wrongGuess):
    hanged_man = [
        r"""
  -----
  |   |
      |
      |
      |
      |
      |
      |
      |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
      |
      |
      |
      |
      |
      |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
 ---  |
  |   |
  |   |
      |
      |
      |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
 ---  |
/ |   |
  |   |
      |
      |
      |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
 ---  |
/ | \ |
  |   |
      |
      |
      |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
 ---  |
/ | \ |
  |   |
 ---  |
/     |
|     |
      |
-------
""",
        r"""
  -----
  |   |
  O   |
 ---  |
/ | \ |
  |   |
 ---  |
/   \ |
|   | |
      |
-------
""",
    ]

    print(hanged_man[wrongGuess])


if __name__ == "__main__":
    # Initial Setup
    correctWord = selectWord()
    guessedLetters = set()
    guessedWord = buildGuessedWord(correctWord, guessedLetters)
    wrongGuesses = 0
    print("Welcome to Hangman! ")
    
    # Game loop
    while not gameOver(wrongGuesses, correctWord, guessedLetters):
        # Show the hanging man
        hangMan(wrongGuesses)
        print(f"Your word is: {guessedWord}")
        print(f"Current guessed letters: "
              f"{buildGuessedLetter(guessedLetters)} \n")
        # Get and process player input
        playerGuess = getPlayerInput(guessedLetters)
        if playerGuess in correctWord:
            print("Nice Guess!")
        else:
            print("Wrong Guess, not in the word!")
            wrongGuesses += 1
            
        guessedLetters.add(playerGuess) # Adds the player's guessed letter into the set
        
        # Show the word with unguessed letters as _
        guessedWord = buildGuessedWord(correctWord, guessedLetters)
    
    # Game Over
    hangMan(wrongGuesses)
    if wrongGuesses == MAXWRONGGUESS:
        print("The person has been hung!")
    else:
        print("You Win!")
    print(f"The word was: {correctWord}")