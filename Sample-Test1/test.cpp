#include "pch.h"
#include "../Project1/baseball.cpp"


class BaseballFixture : public testing::Test
{
public:
    Baseball game{"123"};

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

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber2)
{
    GuessResult result = game.guess("023");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber3)
{
    GuessResult result = game.guess("321");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(1, result.strikes);
    EXPECT_EQ(2, result.balls);
}

