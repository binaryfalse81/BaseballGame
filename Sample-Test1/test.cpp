#include "pch.h"
#include "../Project1/baseball.cpp"


class BaseballFixture : public testing::Test
{
public:
    Baseball game;

    void assrtIllegalArgument(string guessNumber)
    {
        try
        {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e)
        {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
    assrtIllegalArgument("12");
    assrtIllegalArgument("12s");
    assrtIllegalArgument("121");
}

