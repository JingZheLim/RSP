# Simple Rock Paper Scissors Game in Python
import random # simulates computer 
from enum import IntEnum # Instead of user inputing strings, they input

class Action(IntEnum):
    Rock = 0
    Paper = 1
    Scissors = 2
    Lizard = 3
    Spock = 4
    
def userSelection():
    # Using a list comprehension to generate a portion of the input
    choices = [f"{action.name} [{action.value}]" for action in Action]
    choicesStr = ", ".join(choices)
    selection = int(input(f"Enter Choice ({choicesStr}): "))
    action = Action(selection)
    return action    
    
def compSelection():
    # len(Action) = 3, but we start at 0
    selection = random.randint(0, len(Action) - 1) 
    action = Action(selection)
    return action

def determineWinner(userAction, computerAction):
    # Using a Dictionary Instead of brute forcing all available options 
    victories = {
        Action.Rock: [Action.Scissors],  # Rock beats scissors
        Action.Paper: [Action.Rock],  # Paper beats rock
        Action.Scissors: [Action.Paper],  # Scissors beats paper
        Action.Lizard: [Action.Spock, Action.Paper],
        Action.Spock: [Action.Scissors, Action.Rock]
    }
    
    defeats = victories[userAction]
    
    if userAction == computerAction: # draw
        print(f"Both players selected {userAction.name}. It's a tie!")
    elif computerAction in defeats: # user beats computer 
        print(f"{userAction.name} beats {computerAction.name}! You win!")
    else: # computer beats user
        print(f"{computerAction.name} beats {userAction.name}! You lose.")
        
    
    # if userAction == computerAction:
    #     print(f"Both players selected {userAction.name}. It's a tie!")
    # elif userAction == Action.Rock:
    #     if computerAction == Action.Scissors:
    #         print("Rock smashes scissors! You win!")
    #     else:
    #         print("Paper covers rock! You lose.")
    # elif userAction == Action.Paper:
    #     if computerAction == Action.Rock:
    #         print("Paper covers rock! You win!")
    #     else:
    #         print("Scissors cuts paper! You lose.")
    # elif userAction == Action.Scissors:
    #     if computerAction == Action.Paper:
    #         print("Scissors cuts paper! You win!")
    #     else:
    #         print("Rock smashes scissors! You lose.")
            
            
while True:
    try:
        user = userSelection()
    except ValueError as e:
        rangeStr = f"[0, {len(Action) - 1}]"
        print(f"Invalid selection. Enter a value in range {rangeStr}")
        continue
    
    computer = compSelection()
    determineWinner(user, computer)
    
    play_again = input("Play again? (y/n): ")
    if play_again.lower() != "y":
        break
            
# Below is the rough code without making it neater

# while True:
#     userAction = input("Enter Choice (Rock [0], Paper [1], Scissors [2]): ")

#     possibleActions = ["Rock", "Paper", "Scissors"]

#     # Getting user Input (if not a possible action then ask for user input again)
#     while(userAction not in Action):
#         print("Invalid action, try again.")
#         userAction = input("Enter Choice (Rock [0], Paper [1], Scissors [2]): ")


#     # Simulates computer actions by choosing random chose from possible actions
#     computerAction = random.choice(possibleActions)

#     # Determine who wins
#     if (userAction == computerAction):
#         print(f"Both players selected {userAction}. It's a tie!")
#     elif userAction == "Rock":
#         if (computerAction == "Scissors"):
#             print("Rock smashes Scissors! You win!")
#         else:
#             print("Paper covers rock! You lose.")
#     elif userAction == "Paper":
#         if (computerAction == "Rock"):
#             print("Paper covers Rock! You win!")
#         else:
#             print("Scissors cuts Paper! You lose.")
#     elif userAction == "Scissors":
#         if (computerAction == "Paper"):
#             print("Scissors cuts Paper! You win!")
#         else:
#             print("Rock smashes Scissors! You lose.")
            
#     again = input("Play Again? (y/n): ")
#     # Makes the chracter lowercase if it was entered as upper case
#     if (again.lower() != "y"):
#         break