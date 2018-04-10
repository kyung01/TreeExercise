/*
2018/4/10 
KyungHwan Chang 
iopzxz@gmail.com
This program will take an input defining level of tree sequence, then
save the result of generated tree as a txt file.
*/

#include <iostream>
#include <list>
#include <fstream>

//Debugging purpose method print the collection of sequence
void print(std::list<std::list<int>> seqCollection) {
	for (auto it = seqCollection.begin(); it != seqCollection.end(); it++) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;
	}
}

void iterate(std::list<std::list<int>> & collection, std::list<int> sequence, int const maxIteraetion, int currentIteration) {
	if (currentIteration == maxIteraetion) return;
 	std::list<int> nextSequence;
	int numLeft = 0;
	int numRight = 0;
	for (auto it = sequence.begin(); it != sequence.end(); it++) {
		numLeft = (it == sequence.begin()) ? 0 :  *std::prev(it);
		numRight = (std::next(it) == sequence.end()) ? 0 : *std::next(it);
		nextSequence.push_back(*it + numLeft);
		nextSequence.push_back(*it + numRight);
	}
	collection.push_back(nextSequence);
	iterate(collection, nextSequence, maxIteraetion, ++currentIteration);
}
int main() {
	std::cout << "This program will generate a tree sequence. You will be providing an input that defines the level of depth for the sequence." << std::endl;
	std::cout << "Provide an integer that defines the depth of sequence: ";
	int depth;
	std::cin >> depth;
	std::cout << "sequence: " << depth <<std::endl; //delete it later perhaps
	std::list<std::list<int>> sequenceCollection;
	if(depth == 1){
		//exceptional case in which the program cannot handle
		sequenceCollection.push_back({ 1 });
	}
	else if (depth == 2) {
		//exceptional case in which the program cannot handle
		sequenceCollection.push_back({ 1 });
		sequenceCollection.push_back({ 1,1 });
	}
	else {
		//Do normal sequence stuff
		sequenceCollection.push_back({ 1 });
		sequenceCollection.push_back({ 1,1 });
		iterate(sequenceCollection,sequenceCollection.back(), depth , 2);
		//expand the sequence iteratively
	}
	print(sequenceCollection);
	//
	std::list<std::list<int>> sequencePositions;
	system("pause");
	return 0;
}