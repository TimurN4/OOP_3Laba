#include <gtest/gtest.h>
#include "triangle.h"  

TEST(TriangleTest, DefaultConstructor) {
    triangle t;
    ASSERT_TRUE(t.valid_triangle() == true);  
}

TEST(TriangleTest, ConstructorWithPoints) {
    point p1(0, 0), p2(1, 0), p3(0, 1);
    triangle t(p1, p2, p3);
    EXPECT_TRUE(t.valid_triangle());  
}

TEST(TriangleTest, ConstructorWithArray) {
    point points[3] = { point(0, 0), point(1, 0), point(0, 1) };
    triangle t(points);
    EXPECT_TRUE(t.valid_triangle());  
}

TEST(TriangleTest, AssignmentOperatorCopy) {
    triangle t1(point(0, 0), point(1, 0), point(0, 1));
    triangle t2;
    t2 = t1;
    EXPECT_TRUE(t2.valid_triangle());  
    EXPECT_TRUE(t1 == t2);  
}

TEST(TriangleTest, AssignmentOperatorMove) {
    triangle t1(point(0, 0), point(1, 0), point(0, 1));
    triangle t2;
    t2 = std::move(t1);
    EXPECT_TRUE(t2.valid_triangle());  
    EXPECT_FALSE(t1.valid_triangle());  
}

TEST(TriangleTest, EqualityOperator) {
    triangle t1(point(0, 0), point(1, 0), point(0, 1));
    triangle t2(point(0, 0), point(1, 0), point(0, 1));
    triangle t3(point(1, 0), point(0, 0), point(0, 1));
    EXPECT_TRUE(t1 == t2);  
    EXPECT_FALSE(t1 == t3);  
}

TEST(TriangleTest, GetPointsOfFigure) {
    triangle t(point(0, 0), point(1, 0), point(0, 1));
    t.get_points_of_figure(); 
}

TEST(TriangleTest, GetCenter) {
    triangle t(point(0, 0), point(1, 0), point(0, 1));
    point center = t.get_center();
    EXPECT_EQ(center, (0.333333, 0.333333));  
}


TEST(TriangleTest, ConversionOperator) {
    triangle t(point(0, 0), point(1, 0), point(0, 1));
    double area = static_cast<double>(t);
    EXPECT_NEAR(area, 0.5, 1e-6);  
}

TEST(TriangleTest, InputOperator) {
    triangle t;
    std::istringstream iss("0 0 1 0 0 1");
    std::cin >> t;
    EXPECT_TRUE(t.valid_triangle());  
}

TEST(TriangleTest, OutputOperator) {
    triangle t(point(0, 0), point(1, 0), point(0, 1));
    std::ostringstream oss;
    oss << t;
    EXPECT_EQ(oss.str(), "Triangle: (0, 0), (1, 0), (0, 1)");  
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}