/*
2018/4/10 
KyungHwan Chang 
iopzxz@gmail.com
This program will take an input defining level of tree sequence, then
save the result of generated tree as a txt file.
*/

#include <iostream>
#include <list>

int main() {
	std::cout << "This program will generate a tree sequence. You will be providing an input that defines the level of depth for the sequence." << std::endl;
	std::cout << "Provide an integer that defines the depth of sequence: ";
	int depth;
	std::cin >> depth;
	std::cout << "sequence: " << depth; //delete it later perhaps
	if(depth == 1){
		//exceptional case in which the program cannot handle
	}
	else if (depth == 2) {
		//exceptional case in which the program cannot handle
	}
	else {
		//Do normal sequence stuff
		std::list<std::list<int>> sequence;
		sequence.push_back({ 1 });
		sequence.push_back({ 1,1 });
	}
	
	return 0;
}