#include <iostream>
using namespace std;

class Baseball
{
public:
    void guess(const string& str)
    {
        if (str.size() != 3)
        {
            throw length_error("Must be three letters.");
        }
    }
};
