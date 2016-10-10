// In this challenge, given an array of integers, the goal is to efficiently
// find the subarray that has the greatest value when all of its elements are
// summed together. Note that because some elements of the array may be
// negative, the problem is not solved by simply picking the start and end
// elements of the array to be the subarrray, and summing the entire array. 
//
// For example, given the array
//
//  {1, 2, -5, 4, -3, 2}
//  
// The maximum sum of a subarray is 4. It is possible for the subarray to be
// zero elements in length (if every element of the array were negative). 

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

const int ARRAY_RESERVED_VAL = 1000;
const int MAX_ARRAY_SIZE = 100;
const int INVALID_INDEX = -1;

typedef int ARRAY1D[MAX_ARRAY_SIZE];

void print(ARRAY1D array, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void find (ARRAY1D array, int count, int &start, int &end)
{
    start = INVALID_INDEX;
    end = INVALID_INDEX;

    int sum = 0;

    for (int i=0; i<count; i++)
    {
        if ((end != INVALID_INDEX) && (end + 1 == i))
        {
            if (sum + array[i] > sum)
            {
                if (start != INVALID_INDEX)
                {
                    end = i;
                    sum += array[i];
                }
                else
                {
                    start = end = i;
                    sum = array[i];
                }
            }
        }
        else
        {
            if (array[i] >= sum)
            {
                start = end = i;
                sum = array[i];
            }
        }
    }
}

int main()
{
    ARRAY1D array;
    int idx=INVALID_INDEX, count;
    cout << "Enter values for the array (end with " << ARRAY_RESERVED_VAL << "):";
    do
    {
        ++idx;
        cin >> array[idx];
    } while(array[idx] != ARRAY_RESERVED_VAL);
    count = idx;

    if (count > 0)
    {
        cout << "Input array: ";
        print(array, 0, count - 1);

        int start, end;
        find(array, count, start, end);
        if ((start >= 0) && (end >= 0))
        {
            cout << "Output array (start: " << start << " end: " << end << "): ";
            print (array, start, end);
        }
        else
        {
            cout << "No subarray with sum greater than 0" << endl;
        }
    }
    else
    {
        cout << "Input array is invalid" << endl;
    }

    return 0;
}
