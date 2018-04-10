/*
2018/4/10 
KyungHwan Chang 
iopzxz@gmail.com
This program will take an input defining level of tree sequence, then
save the result of generated tree as a txt file.
*/

#include <iostream>
#include <fstream>
#include <list>
#include <stack>

using namespace std;
//Helper function
int hprIntCharCount(int n) {
	int count(0);
	do {
		n /= 10;
		count++;
	} while (n != 0);
	return count;
}

//Debugging purpose method print the collection of sequence
void print(list<list<int>> nestedList) {
	for (auto it = nestedList.begin(); it != nestedList.end(); it++) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
			cout << *it2 << " ";
		}
		cout << endl;
	}
}//Debugging purpose method print the collection of sequence
void print(stack<list<int>> stackList) {
	while (!stackList.empty()) {
		auto l = stackList.top();
		stackList.pop();
		for (auto it = (l).begin(); it != (l).end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
}

void recursive_tree(list<list<int>> & collection,int const maxIteraetion, int currentIteration) {
	if (currentIteration == maxIteraetion) return;
	list<int> sequence = collection.back();
	list<int> nextSequence;
	int numLeft = 0;
	int numRight = 0;
	for (auto it = sequence.begin(); it != sequence.end(); it++) {
		numLeft = (it == sequence.begin()) ? 0 : *prev(it);
		numRight = (next(it) == sequence.end()) ? 0 : *next(it);
		nextSequence.push_back(*it + numLeft);
		nextSequence.push_back(*it + numRight);
	}
	collection.push_back(nextSequence);
	recursive_tree(collection, maxIteraetion, ++currentIteration);
}
void recursive_treePosition(stack<list<int>> & posCollection) {
	list<int> lastPositions = posCollection.top();
	list<int> newPositions;
	for (auto it = lastPositions.begin(); it != lastPositions.end();) {
		newPositions.push_back( (*it + *next(it)) / 2);
		//jump element twice
		it++;
		if (it != lastPositions.end())it++;
	}
	posCollection.push(newPositions);
	if (newPositions.size() >= 2)recursive_treePosition(posCollection);
}
int main() {
	bool debug(true);
	cout << "This program will generate a tree sequence. You will be providing an input that defines the level of depth for the sequence." << std::endl;
	cout << "Provide an integer that defines the depth of sequence: ";
	int depth;
	cin >> depth;
	cout << "sequence: " << depth <<endl; //delete it later perhaps
	list<std::list<int>> sequenceCollection;
	if(depth == 1){
		//exceptional case
		ofstream file;
		file.open("result.txt");
		file << "1";
		file.close();
		return 0;
	}
	else if (depth == 2) {
		//exceptional case
		sequenceCollection.push_back({ 1 });
		sequenceCollection.push_back({ 1,1 });
	}
	else {
		//Do normal sequence process
		sequenceCollection.push_back({ 1 });
		sequenceCollection.push_back({ 1,1 });
		//expand the sequence recursively
		recursive_tree(sequenceCollection, depth , 2);
	}
	if (debug) {
		cout << "debug : Sequence collection" << endl;
		print(sequenceCollection);
	}
	//Generate approrpiate position that each int need to be printed in the txt file format
	stack<list<int>> sequencePositions;
	{
		//generated seed for recursive generation method then add the seed to the stack
		list<int> seed;
		int position = 1;
		int sequenceCount = 0;
		for (auto it = sequenceCollection.back().begin(); it != sequenceCollection.back().end(); it++) {
			seed.push_back(position);
			sequenceCount++;
			if (sequenceCount % 2 == 0) position+=2;
			//position += hprIntCharCount(*it);
			cout << hprIntCharCount(*it) << endl;
			position += 1+ hprIntCharCount(*it);
		}
		sequencePositions.push(seed);
	}
	//expand the sequence recursively
	recursive_treePosition(sequencePositions);
	if (debug) {
		cout << "debug : Sequence collection position" << endl;
		print(sequencePositions);
	}
	//Tree nad approrpiate position that each element of the tree needs to be printed is generated
	//now save the result as the text file
	ofstream file;
	file.open("result.txt");
	for (auto sequence = sequenceCollection.begin(); sequence != sequenceCollection.end(); sequence++) {
		list<int> positions = sequencePositions.top();
		sequencePositions.pop();
		//If it is not the first node, "node connection describing characteres" are needed to be printed first
		if (sequence != sequenceCollection.begin() ) {
			int currentCharLocation = 1;
			auto positionIterator = positions.begin();
			int symbolCounter = 1;
			for (auto element = (*sequence).begin(); element != (*sequence).end(); element++, positionIterator++) {
				for (int i = currentCharLocation; i < *positionIterator; i++) {
					file << " ";
					currentCharLocation++;
				}
				if (symbolCounter++ % 2 == 0) 
					file << "\\";
				else
					file << "/";
				currentCharLocation++;
			}
			file << "\n";
		}
		//print out the elements(numbers) onto the new line
		{
			auto positionIterator = positions.begin();
			int currentCharLocation = 1;
			for (auto element = (*sequence).begin(); element != (*sequence).end(); element++, positionIterator++) {
				for (int i = currentCharLocation; i < *positionIterator; i++) {
					file << " ";
					currentCharLocation++;
				}
				file << *element;
				currentCharLocation+= hprIntCharCount(*element);
			}
			file << "\n";
		}
	}
	file.close();
	system("pause");
	return 0;
}