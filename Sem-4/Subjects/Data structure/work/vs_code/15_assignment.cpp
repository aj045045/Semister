/*
	15) Write a program to solve tower of Hanoi ( Consider three pegs or towers with n
		disks placed one over the other ).
*/
#include <iostream>
using namespace std;

void move(int n, char source, char dest, char spare) {
	if (n == 1)
		cout << " Move from " << source << " to " << dest << endl;
	else {
		move(n - 1, source, spare, dest);
		move(1, source, dest, spare);
		move(n - 1, spare, dest, source);
	}
}

int main()
{
	int n;
	cout << "Enter the number of rings: " << endl;
	cin >> n;
	move(n, 'A', 'C', 'B');
	return 0;
}
