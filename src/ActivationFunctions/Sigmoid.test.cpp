#include "../catch.h"
#include "Sigmoid.h"


namespace LearNN {

    TEST_CASE("ActivationFunction : Sigmoid") {
    
        Sigmoid sigmoid;

        SECTION("Function: Calc()") {
            REQUIRE(sigmoid.Calculate(-1) == Approx(0.2689414214));
            REQUIRE(sigmoid.Calculate(0) == 0.5);
            REQUIRE(sigmoid.Calculate(1) == Approx(0.7310585786));
            REQUIRE(sigmoid.Calculate(0.869) == Approx(0.70454));
            REQUIRE(sigmoid.Calculate(77) == Approx(1));
        }

        SECTION("Function: DerivativeCalc()") {
            REQUIRE(sigmoid.CalculateDerivative(-1) == Approx(0.1966119332));
            REQUIRE(sigmoid.CalculateDerivative(0) == 0.25);
            REQUIRE(sigmoid.CalculateDerivative(1) == Approx(0.1966119332));
            REQUIRE(sigmoid.CalculateDerivative(0.869) == Approx(0.2081643799));
            REQUIRE(Approx(sigmoid.CalculateDerivative(77)) == 0);
        }
    }
}