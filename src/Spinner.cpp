#include "Spinner.hpp"

class Spinner {
    public: 
    
    //constructor, initalizes range to 0
    Spinner() {
        min_Range = 0;
        max_Range = 0;
    }

    virtual int spin() = 0;

    //sets range
    void setRange(int minRange, int maxRange)
    {
        min_Range = minRange;
        max_Range = maxRange;
    }

    private:
    int min_Range, max_Range;

};




