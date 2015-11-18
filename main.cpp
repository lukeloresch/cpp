//#include "LinkedList.h"
#include <iostream>
#include "CLL.h"
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	CLL a;

	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);
	a.add(7);
	a.addAtBeg(128);
	a.del();
	cout << "\nList Data:\n";
	a.display();

	CLL b = a;
	if (b!=a)
		cout << endl << "Not Equal\n";
	else
		cout << endl << "Equal\n";
	
	return 0;
}
	/*
	LinkedList list1;
	LinkedList list2;
	LinkedList combined;


	list1.appendNode(7);
	list1.appendNode(1);
	list1.appendNode(6);

	list2.appendNode(5);
	list2.appendNode(9);
	list2.appendNode(2);

	int size1 = list1.listSize();
	int size2 = list2.listSize();
	
	vector<int> res1;
	vector<int> res2;

	res1 = list1.getSum();
	res2 = list2.getSum();
	
	int sum1 = res1[0];
	int sum2 = res2[0];
	int total = sum1 + sum2;
	
	combined.addCombined(total);
	combined.reverse();
	combined.display();

	
	return 0;
}
*/
