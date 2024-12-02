'''
    Cy Dixon
    Advent of Code 2024 Day 1 Part 2
'''

def main():
    # initialize the groups and the sim score
    group1 = []
    group2 = []
    sim_score = 0

    with open('input.txt', 'r') as file:
        for line in file:
            group1.append(line.split()[0])
            group2.append(line.split()[1])

    # loop through group1 and count the occurrences of each number in group2
    for i in range(len(group1)):
        occurrences = 0
        for j in range(len(group2)):
            if int(group1[i]) == int(group2[j]):
                occurrences += 1
        sim_score += occurrences * int(group1[i])

    print(sim_score)

if __name__ == '__main__':
    main()  