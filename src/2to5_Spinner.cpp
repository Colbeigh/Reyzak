#include "2to5_Spinner.hpp"
#include "Spinner.hpp"
#include <iostream>



class FiveSpinner : public Spinner {
    int spin() override {
    std::cout << "0 to 5 spinner spun" << std::endl;
return 0;
    }

    

};