#include <iostream>

using namespace std;

const int MAX_VALUE = 100;
const int MAX_SIZE = 1000;
typedef int ARRAY1D[MAX_SIZE];

void create(ARRAY1D array, int numItems);
void print(ARRAY1D array, int numItems);
void sort(ARRAY1D array, int numItems);

void swap(int &left, int &right)
{
    int temp = left;
    left = right;
    right = temp;
}


int main()
{
    ARRAY1D array;
    int count;

    cout << "Enter number of items: ";
    cin >> count;

    create(array, count);
    cout << "Initial array: ";
    print(array, count);

    sort(array, count);
    cout << "Sorted array: ";
    print(array, count);

    cout << endl;
}

void sort(ARRAY1D array, int numItems)
{
    for (int i = 1; i < numItems; i++)
    {
        int j = i;
        while ((j > 0) && (array[j-1] > array[j]))
        {
            swap(array[j-1], array[j]);
            --j;
        }
    }
}

void create(ARRAY1D array, int numItems)
{
    srand(time(NULL));
    for (int i=0; i < numItems; i++)
    {
        array[i] = rand() % MAX_VALUE;
    }
}

void print(ARRAY1D array, int numItems)
{
    for (int i=0; i < numItems; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}
