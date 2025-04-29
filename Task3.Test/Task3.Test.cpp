#include "CppUnitTest.h"
#include "../decision/Point.h"
#include "../decision/Polygon.h"
#include "../decision/Shape.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task3Test
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesZeroPoint)
        {
            // Arrange & Act
            Point p;

            // Assert
            Assert::AreEqual(0u, p.getX());
            Assert::AreEqual(0u, p.getY());
        }

        TEST_METHOD(ValueConstructor_CreatesPointWithValues)
        {
            // Arrange
            const unsigned int x = 10;
            const unsigned int y = 20;

            // Act
            Point p(x, y);

            // Assert
            Assert::AreEqual(x, p.getX());
            Assert::AreEqual(y, p.getY());
        }

        TEST_METHOD(EqualityOperator_EqualPoints_ReturnsTrue)
        {
            // Arrange
            Point p1(1, 2);
            Point p2(1, 2);

            // Act & Assert
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentX_ReturnsFalse)
        {
            // Arrange
            Point p1(1, 2);
            Point p2(3, 2);

            // Act & Assert
            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentY_ReturnsFalse)
        {
            // Arrange
            Point p1(1, 2);
            Point p2(1, 3);

            // Act & Assert
            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(InequalityOperator_DifferentPoints_ReturnsTrue)
        {
            // Arrange
            Point p1(1, 2);
            Point p2(1, 3);

            // Act & Assert
            Assert::IsTrue(p1 != p2);
        }

        TEST_METHOD(InequalityOperator_EqualPoints_ReturnsFalse)
        {
            // Arrange
            Point p1(1, 2);
            Point p2(1, 2);

            // Act & Assert
            Assert::IsFalse(p1 != p2);
        }

        TEST_METHOD(AdditionOperator_AddsValueCorrectly)
        {
            // Arrange
            Point p(1, 2);
            unsigned int value = 3;

            // Act
            Point result = p + value;

            // Assert
            Assert::AreEqual(4u, result.getX());
            Assert::AreEqual(5u, result.getY());
        }

        TEST_METHOD(SubtractionOperator_SubtractsValueCorrectly)
        {
            // Arrange
            Point p(5, 4);
            unsigned int value = 3;

            // Act
            Point result = p - value;

            // Assert
            Assert::AreEqual(2u, result.getX());
            Assert::AreEqual(1u, result.getY());
        }

        TEST_METHOD(OutputOperator_FormatsCorrectly)
        {
            // Arrange
            Point p(10, 20);
            std::stringstream ss;

            // Act
            ss << p;

            // Assert
            Assert::AreEqual("(10, 20)", ss.str().c_str());
        }
    };

    TEST_CLASS(ShapeTests)
    {
    public:
        TEST_METHOD(Draw_CallsToString)
        {
            // Arrange
            const unsigned int maxCoord = 100;
            std::vector<Point> points = { Point(10, 10), Point(20, 10), Point(20, 20) };
            Polygon polygon(points, maxCoord);

            // Redirect cout
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            // Act
            polygon.draw();

            // Restore cout
            std::cout.rdbuf(old);

            // Assert
            Assert::IsTrue(buffer.str().find("Polygon with vertices") != std::string::npos);
        }
    };

    TEST_CLASS(PolygonTests)
    {
    public:
        TEST_METHOD(PolygonConstructor_ValidPoints_CreatesPolygon)
        {
            // Arrange
            const unsigned int maxCoord = 100;
            std::vector<Point> points = { Point(10, 10), Point(20, 10), Point(20, 20) };

            // Act
            Polygon polygon(points, maxCoord);

            // Assert
            Assert::AreEqual(3ull, polygon.toString().find("3 vertices"));
        }

        TEST_METHOD(PolygonConstructor_TooFewPoints_ThrowsException)
        {
            // Arrange
            const unsigned int maxCoord = 100;
            std::vector<Point> points = { Point(10, 10), Point(20, 10) };

            // Act & Assert
            Polygon polygon(points, maxCoord);

            Assert::IsTrue(exceptionThrown, L"Should throw exception when too few points");
        }

        TEST_METHOD(PolygonConstructor_PointsExceedMaxCoord_ThrowsException)
        {
            // Arrange
            const unsigned int maxCoord = 100;
            std::vector<Point> points = { Point(10, 10), Point(20, 10), Point(200, 200) };

            // Act & Assert
            Polygon polygon(points, maxCoord);
            Assert::IsTrue(exceptionThrown, L"Should throw exception when coordinates exceed max");
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            // Arrange
            const unsigned int maxCoord = 100;
            std::vector<Point> points = { Point(10, 10), Point(20, 10), Point(20, 20) };
            Polygon polygon(points, maxCoord);

            // Act
            std::string result = polygon.toString();

            // Assert
            Assert::IsTrue(result.find("Polygon with vertices") != std::string::npos);
            Assert::IsTrue(result.find("(10, 10)") != std::string::npos);
        }
    };
}
