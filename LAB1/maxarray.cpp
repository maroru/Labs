// Matthew Ruiz

#include <iostream>

int maxArray(int anArray[], int first, int last)
{
    if ( first+1 == last )
        return anArray[first];
    int mid { first + (last-first) / 2 };
    return std::max(maxArray(anArray,first,mid),maxArray(anArray,mid,last));
}

int main()
{
    int array[]{ 1, 2, 3, 4, 5, 6, 7 };
    int n {sizeof(array)/sizeof(array[0])};

    for (int i{ 0 }; i < n; i++)
        std::cout << array[i];

    std::cout << "\nLargest number is: " << maxArray(array, 0, n) << '\n';
    return 0;
}
