#include <iostream>

using namespace std;

const int MAX_VALUE = 100;
const int MAX_SIZE = 1000;
const int INFINITY = 1000000;
typedef int ARRAY1D[MAX_SIZE];

void create(ARRAY1D array, int numItems);
void print(ARRAY1D array, int start, int numItems);
void sort(ARRAY1D array, int start, int end);

inline void swap(int &left, int &right)
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
    print(array, 0, count);

    sort(array, 0, count - 1);
    cout << "Sorted array: ";
    print(array, 0, count);

    cout << endl;
}

void merge(ARRAY1D array, int start, int mid, int end)
{
    // 0 0 1
    cout << "merge: start - " << start << " mid - " << mid << " end - " << end << endl;
    // 1
    int firstLength = mid - start + 1;
    // 1
    int secondLength = end - mid;
    int i, j;
    ARRAY1D left, right;

    for (i = 0; i < firstLength; i++)
    {
        left[i] = array[start + i];
    }
    for (j = 0; j < secondLength; j++)
    {
        right[j] = array[mid + j];
    }
    left[firstLength + 1] = INFINITY;
    right[secondLength + 1] = INFINITY;

    i = 1;
    j = 1;

    for (int k = start; k < end; k++)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            ++i;
        }
        else
        {
            array[k] = right[j];
            ++j;
        }
    }
    print(array, start, end - start + 1);
}

void sort(ARRAY1D array, int start, int end)
{
    // 0, 3
    // 0, 1
    // 0, 0 - stop
    // 1, 1 - stop 
    int mid;
    if (start < end)
    {
        // 1
        // 0
        mid = (start + end) / 2;

        // 0, 1
        // 0, 0
        sort (array, start, mid);
        // 1, 1
        sort (array, mid + 1, end);
        // 0 0 1
        merge(array, start, mid, end);
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

void print(ARRAY1D array, int start, int numItems)
{
    for (int i=start; i < numItems; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
}
