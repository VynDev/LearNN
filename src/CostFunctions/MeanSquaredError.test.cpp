#include "../catch.h"
#include "MeanSquaredError.h"
#include "../Vector.h"

namespace LearNN {

    TEST_CASE("CossFunction : MeanSquaredError") {
    
        SECTION("Function : Calculate()") {
            MeanSquaredError meanSquaredError;

            Vector<double> output {5, 8, 4, 3};
            Vector<double> expectedOutput {5, 9, 4, 3};

            REQUIRE(meanSquaredError.Calculate(output, expectedOutput) == 0.25);

            output = {1};
            expectedOutput = {54};
            REQUIRE(meanSquaredError.Calculate(output, expectedOutput) == 2809);

            output = {1, 8, 3};
            expectedOutput = {0, 7, 2};
            REQUIRE(meanSquaredError.Calculate(output, expectedOutput) == 1);

            output = {1, 8, 3};
            expectedOutput = {1, 8, 3};
            REQUIRE(meanSquaredError.Calculate(output, expectedOutput) == 0);
        }

        SECTION("Function : CalculateDerivative()") {
            MeanSquaredError meanSquaredError;

            Vector<double> output {5, 7, 4, 3};
            Vector<double> expectedOutput {5, 9, 4, 3};

            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 0) == 0);
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 1) == -0.5);
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 2) == 0);
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 3) == 0);

            output = {1};
            expectedOutput = {54};
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 0) == -53);

            output = {1, 8, 3};
            expectedOutput = {0, 7, 2};
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 0) == Approx(0.3333333333));

            output = {1, 8, 3};
            expectedOutput = {1, 8, 3};
            REQUIRE(meanSquaredError.CalculateDerivative(output, expectedOutput, 0) == 0);
        }
    }
}