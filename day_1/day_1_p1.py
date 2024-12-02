''' Cy Dixon 
    Advent of Code 2024 Day 1
'''

def main():
    group1 = []
    group2 = []

    distances = []
    final_distance = 0

    with open('input.txt', 'r') as file:
        # read the file line by line
        for line in file:
            group1.append(line.split()[0])
            group2.append(line.split()[1])
        # sort the groups
        group1.sort()
        group2.sort()
        # calculate the distances
        for i in range(len(group1)):
            distances.append(abs(int(group1[i]) - int(group2[i])))
            final_distance += distances[i]
        # print the final distance
    print(final_distance)

if __name__ == '__main__':
    main()