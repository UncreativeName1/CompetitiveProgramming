#PLAN
#key point: note that the maximum removals for a maximum int from a valid list is 2. 
#in other words, at least all but 2 numbers must be used
#sort in increasing order
#find modulus of each term and the sum
#   if sum mod is 0, done.
#   if sum mod is 1, search for the lowest possible mod 1 term to remove (loop through sorted list). keep track of mod 2's, if no mod 1's try removing x2 mod 2's
#   opposite to mod 1's for mod 2's 
#   if above possible reverse array done else not possible


def solution(list):
    mod3 = []
    answer = 0
    listMod3 = 0
    valid = False
    possibleToRemove = []

    list.sort()

    for i in list:
        listMod3 += i
        mod3.append(i % 3)
    listMod3 %= 3

    if listMod3 == 0:
        valid = True
    elif listMod3 == 1:
        for i in range(len(mod3)):
            if mod3[i] == 1:
                list.remove(list[i])
                valid = True
                break
            elif mod3[i] == 2:
                possibleToRemove.append(list[i])
    else:
        for i in range(len(mod3)):
            if mod3[i] == 2:
                list.remove(list[i])
                valid = True
                break
            elif mod3[i] == 1:
                possibleToRemove.append(list[i])

    # if removing 0-1 values will result in a possible integer
    if valid:
        list.reverse()
        answer = listToInt(list)
    # if removing 2 values will result in a possible integer
    elif len(possibleToRemove) >= 2:
        list.remove(possibleToRemove[0])
        list.remove(possibleToRemove[1])
        list.reverse()
        answer = listToInt(list)

    return answer
        
            
def listToInt(list):
    if len(list) == 0:
        return 0
    s = ""
    for i in list:
        s += str(i)
    return int(s)


numbers = [3, 3, 3, 3, 3, 3, 2]

temp = solution(numbers)
print(temp)

