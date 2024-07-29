// Christian Parker
// CIS 1202 101
// July 28, 2024

#include <iostream>

using namespace std;

class invalidCharacterExcpeption
{

};

class invalidRangeException
{

};

class caseConversionException
{

};

char character(char start, int offset)
{
    int startAsciiValue = int(start);

    int target = startAsciiValue + offset;


    try {

        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122)
        {
            throw invalidCharacterExcpeption();
        }

        else if (target < 65 || (target > 90 && target < 97) || target > 122)
        {
            throw invalidRangeException();
        }

        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterExcpeption exception1)
    {
        cout << " Invalid Character Exception " << endl;

        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " Invalid Range Exception " << endl;

        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Cannot make case changes from upper to lower or otherwise " << endl;

        return ' ';
    }

    return char(target);
}

template <typename T>

T half(T val) {

    T res;

    res = val / 2;

    if (*typeid(val).name() == 'i') {

        if (res * 2 != val) {

            res++;
        }
    }
    return res;
}

int main() {

    double a = 7.0;

    float b = 5.0f;

    int c = 3;

    cout << half(a) << endl;

    cout << half(b) << endl;

    cout << half(c) << endl;

}