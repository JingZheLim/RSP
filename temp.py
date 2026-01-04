# Read file input
def calcAvg(filename):
    
    # Read file and put into contents
    with open(filename, 'r') as file:
        content = file.read()
        
    # Split into a list
    numStrings = content.split()
        
    # Convert each string number to float number
    numbers = [float(num) for num in numStrings]
    
    # If theres nothing in numbers list
    if not numbers:
        return 0
    
    # Calculate Avg
    avg = sum(numbers) / len(numbers)
    return avg
        
        