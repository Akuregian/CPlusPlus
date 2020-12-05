/* Author: Anthony Kuregian
 * Description: Using Templating to sort various Types
 * Email: Anthonk3371@student.vvc.edu
 * 
*/

#include<iostream>
#include<string>

template<typename T>
void swap(T& a,T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void selection_sort(T a[], int n)
{
    /* a[0] to a[n-1] is the array to sort */
    int i,j;
    
    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    int iMin;
    for (j = 0; j < n-1; j++)
    {
    /* find the min element in the unsorted a[j .. n-1] */
     
         /* assume the min is the first element */
         iMin = j;
         /* test against elements after j to find the smallest */
         for (i = j+1; i < n; i++)
         {
             /* if this element is less, then it is the new minimum */
             if (a[i] < a[iMin])
             {
                 /* found new minimum; remember its index */
                 iMin = i;
             }
         }
     
         if (iMin != j) 
         {
             swap(a[j], a[iMin]);
         }
     }
} 

template<typename T>
void print_array(T a[], int n)
{
    for(int i=0;i<n;i++)
       std::cout << a[i] << std::endl;
}

int main()
{
    
    /* Prints double Values */
    double array_1[5] = {25.1,34.2,1.3,2.4,56.2};
    print_array<double>(array_1,5);
    selection_sort<double>(array_1,5);
    print_array<double>(array_1,5);


    /* Prints Integer Values */
    int array_2[5] = {25,34,1,2,56};
    print_array<int>(array_2,5);
    selection_sort<int>(array_2,5);
    print_array<int>(array_2,5);


    /* Prints String Values */
    std::string array_3[5] = {"Anthony", "John", "Johnny", "Mike", "Ron"};
    print_array<std::string>(array_3,5);
    selection_sort<std::string>(array_3,5);
    print_array<std::string>(array_3,5);

    return 0;
}
