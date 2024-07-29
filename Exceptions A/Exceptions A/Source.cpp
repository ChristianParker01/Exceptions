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
    int startValue = int(start);

    int select = startValue + offset;


    try {

        if (startValue < 65 || (startValue > 90 && startValue < 97) || startValue > 122)
        {
            throw invalidCharacterExcpeption();
        }

        else if (select < 65 || (select > 90 && select < 97) || select > 122)
        {
            throw invalidRangeException();
        }

        else if ((select >= 65 && select <= 90 && startValue >= 95 && startValue <= 122) || (select >= 95 && select <= 122 && startValue >= 65 && startValue <= 90))
        {
            throw caseConversionException();
        }
    }

    catch (invalidCharacterExcpeption exception1)
    {
        cout << " invalidCharacterException " << endl;

        return ' ';
    }
    catch (invalidRangeException exception2)
    {
        cout << " invalidRangeException " << endl;

        return ' ';
    }
    catch (caseConversionException exception3)
    {
        cout << " Upper and lower-case transitions not allowed " << endl;

        return ' ';
    }

    return char(select);
}

int main()
{
    cout << character('a', 1) << endl;

    cout << character('a', -1) << endl;

    cout << character('Z', -1) << endl;

    cout << character('?', 5) << endl;

    cout << character('A', 32) << endl;
}