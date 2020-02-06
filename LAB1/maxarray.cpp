// Matthew Ruiz

#include <iostream>

// Template function to find max value of an array
template <class T>
T maxArray(T anArray[], int first, int last)
{
    
    if ( last-first == 1 )
        return anArray[first];
    int mid { first + (last-first) / 2 };
    return std::max(maxArray(anArray,first,mid),maxArray(anArray,mid,last));
}

// Function Declaration
template <class T>
void displayArray(T anArray[], int size);

int main()
{
    int intArray[7]{ 11, 2, 3, 4, 9, 10, 13};
    char charArray[6]{ 'v', 'b', 'z', 'd', 'e', 'j'};

    std::cout << "Displaying intArray of size 7\n";
    displayArray<int>(intArray, 7);
    std::cout << "\nFinding largest number using multipath recursion...";
    std::cout << "\nLargest number is: "
              << maxArray<int>(intArray, 0, 7) << "\n\n";

    std::cout << "Displaying charArray of size 6\n";
    displayArray<char>(charArray, 6);
    std::cout << "\nFinding largest character using multipath recursion...";
    std::cout << "\nLargest char is: "
              << maxArray<char>(charArray, 0, 6) << "\n\n";
    return 0;
}

// Displays contents of array
template <class T>
void displayArray(T anArray[], int size)
{
    int i {0};
    std::cout << "Contents of array: ";
    while ( i < size )
    {
        std::cout << anArray[i];
        i++;
        if ( i != size ) { std::cout << ", "; }
    }
}
/* Tested Arrays:
 * integer Array : { 11 , 2 , 3 , 4 , 9 , 10 , 13 }
 * Result: Largest number is: 13
 *
 * Array 2 : { v , b , z , d , e , j }
 * Result: Largest character is: z
 */
