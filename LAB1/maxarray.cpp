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
    int x;
    std::cout << "Create an array\n" << "Size of array: ";;
    std::cin >> x;
    int array[x];
    for (int i{0} ; i < x ; i++)
    {
        std::cout << "Array[" << i << "] is: ";
        std::cin >> array[i];
    }
    //int n {sizeof(array)/sizeof(array[0])};
    std::cout << "User-defined array contents: ";
    for (int i{ 0 }; i < x; i++)
        std::cout << array[i] << " ";

    std::cout << "\nFinding largest number using multipath recursion...";
    std::cout << "\nLargest number is: " << maxArray(array, 0, x) << '\n';
    if (x == 1)
        main();
    return 0;
}
