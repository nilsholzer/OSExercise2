#include "pointers.h"

int average(int *arrayPointer, unsigned int size)
{
    if (size == 0)
    {
        return 0;
    }
    unsigned int count;
    int sum = 0;
    for (count = 0; count < size; count++)
    {
        sum += arrayPointer[count];
    }
    
    return sum / size;
}

int averageIndirect(int **arrayPointer, unsigned int size)
{
    if (size == 0)
    {
        return 0;
    }
    unsigned int count;
    int sum = 0;
    for (count = 0; count < size; count++)
    {
        sum += *arrayPointer[count];
    }
    
    return sum / size;
}
