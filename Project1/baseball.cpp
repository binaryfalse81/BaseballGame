#include <iostream>
using namespace std;

class Baseball
{
public:
    void guess(const string& guessNumber)
    {
        assertIlligalArgument(guessNumber);
    }

    void assertIlligalArgument(const string& guessNumber)
    {
        if (guessNumber.size() != 3)
        {
            throw length_error("Must be three letters.");
        }

        for (char ch : guessNumber)
        {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Must be Number.");
        }

        if (isDupNumber(guessNumber))
        {
            throw invalid_argument("Must not have the same Number.");
        }
    }
    bool isDupNumber(const string& guessNumber)
    {
        return (guessNumber[0] == guessNumber[1]) ||
            (guessNumber[0] == guessNumber[2]) ||
            (guessNumber[1] == guessNumber[2]);
    }
};
