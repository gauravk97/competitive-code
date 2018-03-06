a =["############",
    "#...#......#",
    "..#.#.####.#",
    "###.#....#.#",
    "#....###.#.X",
    "####.#.#.#.#",
    "#..#.#.#.#.#",
    "##.#.#.#.#.#",
    "#........#.#",
    "######.###.#",
    "#......#...#",
    "############"]



size = 12
import sys

def print_maze(a):
	for i in a:

	# 	sys.stdout.write(i + "\n")
	# sys.stdout.flush()
		print(i, end='\r')
		print("aaa")


def access_maze(tup):
	return a[tup[0]][tup[1]]

def valid_places_from_current(tup):
	a, b = 	tup[0], tup[1]
	result = []
	if a<0 | a>size | b<0 | b>size:
		print("Out of bounds")
	if b-1 != -1 and access_maze((a, b-1))==".":
		result.append((a, b-1))
	if b+1 != size and access_maze((a, b+1))==".":
		result.append((a, b+1))
	if a-1 != -1 and access_maze((a-1, b))==".":
		result.append((a-1, b))
	if a+1 != size and access_maze((a+1, b))==".":
		result.append((a+1, b))

	return result

# print(a[0][1])

valid_spaces_to_move = []

for i in range(len(a)):
	for j in range(len(a[0])):
		if a[i][j] != "#":
			valid_spaces_to_move.append((i,j))

# print(valid_spaces_to_move)

import random
start = random.sample(valid_spaces_to_move, 1)
start = [(1,1)]
# print((start[0]))
# print(valid_places_from_current(start[0]))
# for i, j in valid_places_from_current(start[0]):
# 	print(access_maze((i,j)))
# print(a)
for i in range(10):
	print_maze(a)
