#include "catch.hpp"

#include "sparse_vector.hpp"

// TODO
TEST_CASE("test sparse", "[SparseVector]") {
	SparseVector<double> v1(1000);
	v1(45) = 88.5;
	CHECK(v1(45) == 88.5);
	CHECK(v1(88) == 0);
	CHECK(v1(90) == 0);
	CHECK(v1(105) == 0);
	CHECK(v1.length() == 1000);


	SparseVector<double> v2(100);
	v2 = v1;


}