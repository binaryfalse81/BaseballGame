#include <iostream>
using namespace std;

struct GuessResult
{
    bool solved;
    int strikes;
    int balls;
};

class Baseball
{
public:
    explicit Baseball(const string& question)
        : question(question)
    {
    }

    GuessResult guess(const string& guessNumber)
    {
        assertIlligalArgument(guessNumber);
        if (guessNumber == question)
        {
            return { true, 3, 0 };
        }

        int strikeCnt = getStrikeCnt(guessNumber);

        if (strikeCnt == 2)
        {
            return { false, 2, 0 };
        }

        int ballCnt = getBallCnt(guessNumber);

        if (strikeCnt == 1 && ballCnt == 2)
        {
            return { false, 1, 2 };
        }

        return { false, 0, 0 };
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

    int getStrikeCnt(const string& guessNumber)
    {
        int strikeCnt = 0;
        for (int i = 0; i < guessNumber.size(); i++)
        {
            if (guessNumber[i] == question[i])
            {
                strikeCnt++;
            }
        }

        return strikeCnt;
    }

    int getBallCnt(const string& guessNumber)
    {
        int ballCnt = 0;
        for (int i = 0; i < guessNumber.size(); i++)
        {
            for (int j = 0; j < question.size(); j++)
            {
                if (guessNumber[i] == question[j] && i != j)
                {
                    ballCnt++;
                }
            }
        }

        return ballCnt;
    }

private:
    string question;
};
