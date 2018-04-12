# TreeExercise
# How to use this program.
1. Compile it first (using Visual Studio 2017).
2. Once you run exe, the program will request user input to define the depth of tree in which you want it to generate.
3. Enter an integer then program will generate tree structure then save it as result.txt at the relative location.

# High Level Program Structure.
There are three main steps in the program.
1. Generate the tree sequence
2. Generate position(position in which these elements need to be printed onto the result.txt file) of each element in the tree. 
3. Create/save the result as a result.txt file.

#include <iostream> is used for general purpose of using the console application.
#include <fstream> is used for creating and saving the text file.
#include <list> is used for handling the tree data
#include <stack> is used for handling the data of positions of the tree in which the tree's elements need to be printed onto the tree.

# Interesting optimization.
Program doesn't create "a node". It prints the result as "tree format". Instead of generating the tree pattern based on the "nodes" it creates a list of integer for each generation.
As the result, first and second generation of the tree are given as a seed for this program to work.
First generation of the tree is {1}
Second generation of the tree is {1,1}
From there, third and so on generations are created by the program by looking at the patterns in which the numbers are generated based on the previous generation.
However the user demands the format to be displayed as the "tree", so it prints out the result into a tree format.