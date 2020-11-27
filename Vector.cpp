#include "Vector.h"
#include <iostream>

Vector::Vector(const Vector& theOther)
{
    elementNum = theOther.elementNum;
    pData = new int[elementNum];
    for (unsigned int i = 0; i < theOther.elementNum; i++)
    {
        pData[i] = theOther.pData[i];
    }
}


std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    for (unsigned int i = 0; i < v.elementNum; i++)
    {
        os << v.pData[i] << " ";
    }
    return os;
}


void Vector::clear()
{
    elementNum = 0;
    delete[] pData;
    pData = NULL;
}


void Vector::erase(unsigned int position)
{
    int* TmpPtr = new int[elementNum - 1];
    for (unsigned int i = 0, j = 0; i < elementNum; i++)
    {
        if (i == position)
            ;
        else
        {
            TmpPtr[j] = pData[i];
            j++;
        }
    }
    elementNum--;
    delete[] pData;
    pData = TmpPtr;
}

int& Vector::at(unsigned int position)
{
    return pData[position];
}


const int& Vector::at(unsigned int position) const
{
    const int& pos = pData[position];
    return pos;
}


bool Vector::insert(unsigned int position, int element)
{
    int* ptr;
    if (position >= UINT8_MAX)
    {
        return false;
    }
    else if (position >= elementNum)
    {
        ptr = new int[position + 1];
        unsigned int i;
        for (i = 0; i < position; i++)
        {
            if (i < elementNum)
                ptr[i] = pData[i];
            else
                ptr[i] = 0;
        }
        ptr[position] = element;
        elementNum = position + 1;
    }
    else
    {
        elementNum += 1;
        ptr = new int[elementNum];
        unsigned int i;
        for (i = 0; i < position; i++)
        {
            ptr[i] = pData[i];
        }
        ptr[position] = element;
        for (i = position + 1; i < elementNum; i++)
        {
            ptr[i] = pData[i - 1];
        }
    }
    delete[] pData;
    pData = ptr;
    return true;
}


const Vector& Vector::operator=(const Vector& theOther)
{
    elementNum = theOther.elementNum;
    int* newptr = new int[elementNum];
    for (unsigned int i = 0; i < theOther.elementNum; i++)
    {
        newptr[i] = theOther.pData[i];
    }
    pData = newptr;
    return *this;
}


int& Vector::operator[](unsigned int position)
{
    return pData[position];
}


const int& Vector::operator[](unsigned int position) const
{
    const int& SubOpr = pData[position];
    return SubOpr;
}


//Sorting the Vector in Ascending order
void Vector::sort()
{
    for (unsigned int j = 0; j < elementNum; j++)
    {

        for (unsigned int i = j + 1; i < elementNum; i++)
        {
            if (pData[j] > pData[i]) {
                unsigned int tmp = pData[j];
                pData[j] = pData[i];
                pData[i] = tmp;
            }
        }
    }
}
