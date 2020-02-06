// Matthew Ruiz

#include <iostream>

template <class T>
T maxArray(T anArray[], int first, int last)
{
    
    if ( last-first == 1 )
        return anArray[first];
    int mid { first + (last-first) / 2 };
    return std::max(maxArray(anArray,first,mid),maxArray(anArray,mid,last));
}

template <class T>
void displayArray(T anArray[], int size)
{
    int i {0};
    while ( i < size )
    {
        std::cout << anArray[i] << " ";
        i++;
    }
}

int main()
{
    int intArray[7]{ 11, 2, 3, 4, 9, 10, 13};
    char charArray[6]{ 'v', 'b', 'z', 'd', 'e', 'j'};

    displayArray<int>(intArray, 7);
    std::cout << "\nFinding largest number using multipath recursion...";
    std::cout << "\nLargest number is: "
              << maxArray<int>(intArray, 0, 7) << '\n';

    displayArray<char>(charArray, 6);
    std::cout << "\nFinding largest character using multipath recursion...";
    std::cout << "\nLargest char is: "
              << maxArray<char>(charArray, 0, 6) << '\n';
    return 0;
}

/* Tested Arrays:
 * Array 1 :<1 , 2 , 9 , 5 , 6 >
 * Result: Largest number is: 9
 *
 * Array 2 :<10 , 4 , 5 , 13>
 * Result: Largest number is: 13
 */
