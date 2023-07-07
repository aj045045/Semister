/*
5)  Define two array A and B. and merge both array in array C (Both array 1st
    element will be 1st and 2nd of C, Both array 2nd element will be 3nd and 4rd of
    C, so on�).
*/

#include <iostream>
using namespace std;

int main()
{
    int array_a[10], val_a, array_b[10], val_b, array_c[20];
    cout << "Enter the element for the first list " << endl;
    cin >> val_a;
    cout << "Enter " << val_a << " element" << endl;
    for (int i = 0; i < val_a; i++)
        cin >> array_a[i];
    cout << "Enter the element for the second list " << endl;
    cin >> val_b;
    cout << "Enter " << val_b << " element" << endl;
    for (int i = 0; i < val_b; i++)
        cin >> array_b[i];
    int a = 0;
    for (int i = 0; i < val_a + val_b; i += 2)
    {
        array_c[i] = array_a[a];
        array_c[i + 1] = array_b[a];
        a++;
    }
    cout << "=========[ PRINTING THE VALUES ]=============" << endl;
    for (int i = 0; i < val_a + val_b; i++)
        cout << array_c[i] << ", ";

    return 0;
}
