#include "catch.hpp"

#include "linalg.hpp"

// TODO
TEST_CASE("dot test", "AbstractVector") {
	DenseVector<int> vector1(2);

	vector1(1) = 3;
	vector1(2) = 2;

	REQUIRE(norm1(vector1) == 5);
	REQUIRE(norm2(vector1) == sqrt(13));

}