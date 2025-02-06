# Plan
# Set up our 3 main classes - Snake, Apple, and Game
# Render an empty board
# Initialize a snake and render it in the board
# Let the player pilot their snake
# Work out when the player has died
# Add apples to the board and let the player eat them
class Game():
    # initialising the size of the board
    def initialise (self, height, width):
        self.height = height
        self.width = width

    # returns an empty matrix of size height and width
    def board(self):
        return [[self.EMPTY for _ in range(self.height)] for _ in range(self.width)]

    # rendering the board on the terminal
    def render(self):
        matrix = self.board()
        # print matrix out
        for row in range(self.height):
            for col in range(self.width):
                print(matrix[row][col], end=" ")

game = Game()
game.initialise(10, 10)
game.board()
game.render()