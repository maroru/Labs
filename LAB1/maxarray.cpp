// Matthew Ruiz

#include <iostream>

int maxArray(int anArray[], int first, int last)
{
    if ( last-first == 1 )
        return anArray[first];
    int mid { first + (last-first) / 2 };
    return std::max(maxArray(anArray,first,mid),maxArray(anArray,mid,last));
}

int main()
{
    char repeat {};
    do 
    {
        // User defines their own array using cin
        int size; 
        std::cout << "Create an array\n" << "Size of array: ";
        std::cin >> size;
        int array[size];
        for (int i{0} ; i < size ; i++)                 // Populate the array
        {
            std::cout << "Array[" << i << "] is: ";
            std::cin >> array[i];
        }


        std::cout << "User-defined array contents: ";
        for (int i{ 0 }; i < size; i++)
            std::cout << array[i] << " ";

        std::cout << "\nFinding largest number using multipath recursion...";
        std::cout << "\nLargest number is: " << maxArray(array, 0, size) << '\n';

        std::cout << "Repeat? Y/N\n";
        std::cin >> repeat;
    } while ( repeat == 'y' || repeat == 'Y');
    return 0;
}
