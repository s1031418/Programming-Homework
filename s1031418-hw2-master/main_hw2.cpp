#include <conio.h> //getch()
#include <iostream>
using namespace std;
#include "HugeUInteger_hw2.h" //< CORRECT this file name

int main() //< Do NOT modified this functiuon
{
  unsigned int seed;
  cout << "Enter seed: ";
  cin >> seed;
  srand( seed );

  unsigned int length1, length2, length3;
  cout << "Enter the lengths of three huge integers: ";
  cin >> length1 >> length2 >> length3;
  
  HugeUInteger n1, n2, n3;
  n1 = HugeUInteger::random(length1);
  cout << "N1: " << n1 << endl;
  n2 = HugeUInteger::random(length2);
  cout << "N2: " << n2 << endl;
  n3 = HugeUInteger::random(length3);
  cout << "N3: " << n3 << endl;
  HugeUInteger n4 = HugeUInteger::zero();
  cout << "N4: " << n4 << endl;

  cout << "N1 + N3 = " << n1 + n3 << endl;
  cout << "N2 - N3 = " << n2 - n3 << endl;
  cout << "N1 * N4 = " << n1 * n4 << endl;
  cout << "N4 = N2 + N3 * N1 = " << (n4 = n2 + n3 * n1) << endl;

  cout << endl << "Let N2 = N1, then..." << endl;
  n1 = n2;
  if (n1 == n2)
	  cout << "N1 is equal to N2" << endl;
  
  if (n1 > n3)
	  cout << "N1 is larger than N3" << endl;

  if (n1 < n3)
	  cout << "N1 is smaller than N3" << endl;

  cout << "N4 / N2 = " << n4 / n2 << endl;
  HugeUInteger n5;
  cout << "N5 = N4 % N2 = " << (n6 = n4 % n2) << endl;
  
  cout << endl;
  cout << "N1: " << n1 << endl;
  cout << "N2: " << n2 << endl;
  cout << "N3: " << n3 << endl;
  cout << "N4: " << n4 << endl;
  cout << "N5: " << n5 << endl;

  getch();
  return 0;
}
