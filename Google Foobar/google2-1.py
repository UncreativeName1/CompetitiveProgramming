salutes = 0
counter = 0

# > adds to counter
# < salute add

userInput = raw_input("string: ")

def solution(str):
    global salutes
    global counter
    for char in str:
        if char == '<':
            salutes += counter
        elif char == '>':
            counter += 2
    return salutes

solution(userInput)
print(salutes)