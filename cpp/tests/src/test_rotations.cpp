#include <gtest/gtest.h>

#include "rotations.hpp"

TEST(RotationsTests, TestRotateDoesNotThrow) {
    XYZ shape = XYZ(1, 1, 1);
    Cube cube = Cube{{XYZ(0, 0, 0)}};
    for (int i = 0; i < 24; i++) {
        EXPECT_NO_THROW(Rotations::rotate(i, shape, cube));
    }
}

TEST(RotationsTests, TestRotationsMatchesExpectation) {
    XYZ shape = XYZ(2, 1, 1);
    Cube cube = Cube{{XYZ(0, 0, 0), XYZ(1, 0, 0)}};
    XYZ expected_shapes[24] = {
        XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(2, 1, 1), XYZ(1, 2, 1),
        XYZ(1, 2, 1), XYZ(1, 2, 1), XYZ(1, 2, 1), XYZ(1, 1, 2), XYZ(1, 1, 2), XYZ(1, 1, 2), XYZ(1, 1, 2), XYZ(1, 2, 1), XYZ(1, 2, 1),
        XYZ(1, 2, 1), XYZ(1, 2, 1), XYZ(1, 1, 2), XYZ(1, 1, 2), XYZ(1, 1, 2), XYZ(1, 1, 2)
    };
    std::vector<XYZ> expected_cubes[24] = {
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        { XYZ(1, 1, 0),  XYZ(1, 1, 1), },
        { XYZ(1, 0, 2),  XYZ(1, 0, 1), },
        { XYZ(0, 1, 2),  XYZ(0, 1, 1), },
        { XYZ(0, 0, 0),  XYZ(0, 0, 1), },
        {},
        {},
        {},
        {},
        { XYZ(1, 1, 2),  XYZ(1, 1, 1), },
        { XYZ(1, 0, 0),  XYZ(1, 0, 1), },
        { XYZ(0, 1, 0),  XYZ(0, 1, 1), },
        { XYZ(0, 0, 2),  XYZ(0, 0, 1), },
    };
    std::stringstream shapes;
    std::stringstream cubes;
    for (int i = 0; i < 24; i++) {
        auto rotated = Rotations::rotate(i, shape, cube);
        EXPECT_EQ(rotated.first, expected_shapes[i]);
        EXPECT_EQ(rotated.second, expected_cubes[i]);
    }
}