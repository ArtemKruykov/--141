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
            Point p;

            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        TEST_METHOD(ValueConstructor_CreatesPointWithValues)
        {
            const double x = 10.5;
            const double y = 20.3;

            Point p(x, y);

            Assert::AreEqual(x, p.getX());
            Assert::AreEqual(y, p.getY());
        }

        TEST_METHOD(EqualityOperator_EqualPoints_ReturnsTrue)
        {
            Point p1(1, 2);
            Point p2(1, 2);

            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_EqualPoints_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(1, 2);

            Assert::IsFalse(p1 != p2);
        }

        TEST_METHOD(EqualityOperator_DifferentX_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(3, 2);

            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(EqualityOperator_DifferentX_ReturnsTrue)
        {
            Point p1(1, 2);
            Point p2(3, 2);

            Assert::IsTrue(p1 != p2);
        }


        TEST_METHOD(EqualityOperator_DifferentY_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(1, 3);

            Assert::IsFalse(p1 == p2);
        }

        TEST_METHOD(InequalityOperator_DifferentPoints_ReturnsTrue)
        {
            Point p1(1, 2);
            Point p2(1, 3);

            Assert::IsTrue(p1 != p2);
        }

        TEST_METHOD(InequalityOperator_EqualPoints_ReturnsFalse)
        {
            Point p1(1, 2);
            Point p2(1, 2);

            Assert::IsFalse(p1 != p2);
        }

        TEST_METHOD(OutputOperator_FormatsCorrectly)
        {
            Point p(10, 20);
            std::stringstream ss;

            ss << p;

            Assert::AreEqual("(10, 20)", ss.str().c_str());
        }
    };

    TEST_CLASS(ShapeTests)
    {
    public:
        TEST_METHOD(Draw_CallsToString)
        {
            class MockShape : public Shape {
            public:
                std::string toString() const override {
                    return "MockShape";
                }
                void readFromInput() override {}
            };

            MockShape shape;
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            shape.draw();

            std::cout.rdbuf(old);

            Assert::AreEqual(std::string("MockShape\n"), buffer.str());
        }
    };

    TEST_CLASS(PolygonTests)
    {
    public:
        TEST_METHOD(PolygonConstructor_ValidPoints_CreatesPolygon)
        {
            const double maxCoord = 100.0;
            std::vector<Point> points = {
                Point(10.5, 10.5),
                Point(20.1, 10.2),
                Point(20.3, 20.4)
            };

            Polygon polygon(points, maxCoord);
            std::string result = polygon.toString();

            Assert::IsTrue(result.find("(10.5, 10.5)") != std::string::npos);
            Assert::IsTrue(result.find("(20.1, 10.2)") != std::string::npos);
            Assert::IsTrue(result.find("(20.3, 20.4)") != std::string::npos);
        }

        TEST_METHOD(PolygonConstructor_TooFewPoints_ThrowsException)
        {
            const double maxCoord = 100.0;
            std::vector<Point> points = {
                Point(10.5, 10.5),
                Point(20.1, 10.2)
            };

            bool exceptionThrown = false;
            try {
                Polygon polygon(points, maxCoord);
            }
            catch (...) {
                exceptionThrown = true;
            }

            Assert::IsTrue(exceptionThrown);
        }

        TEST_METHOD(PolygonConstructor_PointsExceedMaxCoord_ThrowsException)
        {
            const double maxCoord = 100.0;
            std::vector<Point> points = {
                Point(10.5, 10.5),
                Point(20.1, 10.2),
                Point(200.5, 200.5)
            };

            bool exceptionThrown = false;
            try {
                Polygon polygon(points, maxCoord);
            }
            catch (...) {
                exceptionThrown = true;
            }

            Assert::IsTrue(exceptionThrown);
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            const double maxCoord = 100.0;
            std::vector<Point> points = {
                Point(10.5, 10.5),
                Point(20.1, 10.2),
                Point(20.3, 20.4)
            };

            Polygon polygon(points, maxCoord);
            std::string result = polygon.toString();

            Assert::IsTrue(result.find("Многоугольник с вершинами: ") != std::string::npos);
            Assert::IsTrue(result.find("(10.5, 10.5)") != std::string::npos);
            Assert::IsTrue(result.find("(20.1, 10.2)") != std::string::npos);
            Assert::IsTrue(result.find("(20.3, 20.4)") != std::string::npos);
        }

        TEST_METHOD(ReadFromInput_CreatesValidPolygon) {
            std::stringstream input;
            input << "3\n(10.5,10.5)\n(20.1,10.2)\n(20.3,20.4)\n";

            std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

            const double maxCoord = 100.0;
            bool exceptionThrown = false;
            try {
                Polygon polygon = Polygon::ReadFromInput(maxCoord);
                std::string result = polygon.toString();

                Assert::IsTrue(result.find("(10.5, 10.5)") != std::string::npos);
                Assert::IsTrue(result.find("(20.1, 10.2)") != std::string::npos);
                Assert::IsTrue(result.find("(20.3, 20.4)") != std::string::npos);
            }
            catch (...) {
                exceptionThrown = true;
            }

            std::cin.rdbuf(origCin);
            Assert::IsFalse(exceptionThrown);
        }
    };
}
