#include "pch.h"
#include "../Project1/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}