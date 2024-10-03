/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#ifndef SPINNER_H
#define SPINNER_H

/**
 * @brief a base class for Spinner Objects
 */
class Spinner {
    public:
    /**
     * @brief Constructor, sets min and max range to 0
     */
    Spinner();

    /**
     * @brief to be overridden in enherited classes, currently returns 0
     */
    int spin();

    /**
     * @brief sets our range
     * @param minRange int value for lower part of range
     * @param maxRange int value for higher part of range
     */
    void setRange(int minRange, int maxRange);

    private:
    int min_Range, max_Range;
};

#endif