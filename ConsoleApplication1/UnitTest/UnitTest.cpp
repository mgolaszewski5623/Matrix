#include "pch.h"
#include "CppUnitTest.h"

#include "../ConsoleApplication1/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Constructor1)
		{
			Matrix m;
			Assert::AreEqual(1, m.GetX());
			Assert::AreEqual(1, m.GetY());
			Assert::AreEqual(0.0, m.Get(0, 0));
		}

		TEST_METHOD(Constructor2)
		{
			int size = 3;
			Matrix m0(size);
			Assert::AreEqual(size, m0.GetX());
			Assert::AreEqual(size, m0.GetY());
			size = 0;
			try {
				Matrix m1(size);
				Assert::Fail();
			}
			catch (std::exception& e) {
				Assert::IsTrue(true);
			}
			size = -1;
			try {
				Matrix m2(size);
				Assert::Fail();
			}
			catch (std::exception& e) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Constructor3) {
			int y = 2;
			int x = 3;
			Matrix m0(y, x);
			Assert::AreEqual(x, m0.GetX());
			Assert::AreEqual(y, m0.GetY());
			y = 0;
			try {
				Matrix m1(y, x);
				Assert::Fail();
			}
			catch (std::exception& e) {
				Assert::IsTrue(true);
			}
			x = 0;
			try {
				Matrix m2(y, x);
				Assert::Fail();
			}
			catch (std::exception& e) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ConstructorCopy)
		{
			Matrix original(2, 3);
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 3; j++)
					original += Matrix(2, 3);

			Matrix copy(original);
			Assert::AreEqual(original.GetX(), copy.GetX());
			Assert::AreEqual(original.GetY(), copy.GetY());

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(original.Get(i, j), copy.Get(i, j));
		}
		TEST_METHOD(OperatorAddition)
		{
			Matrix a(2, 2);
			Matrix b(2, 2);
			Matrix c = a + b;

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					Assert::AreEqual(0.0, c.Get(i, j));

			try {
				Matrix d(3, 3);
				Matrix e = a + d;
				Assert::Fail();
			}
			catch (std::exception&) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(OperatorSubtraction)
		{
			Matrix a(2, 2);
			Matrix b(2, 2);
			Matrix c = a - b;

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					Assert::AreEqual(0.0, c.Get(i, j));
		}

		TEST_METHOD(OperatorMultiplicationMatrix)
		{
			Matrix a(2, 3);
			Matrix b(3, 2);
			Matrix c = a * b;

			Assert::AreEqual(2, c.GetY());
			Assert::AreEqual(2, c.GetX());

			try {
				Matrix d(4, 4);
				Matrix e = a * d;
				Assert::Fail();
			}
			catch (std::exception&) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(OperatorScalarMultiplication)
		{
			Matrix m(2, 2);
			Matrix result = m * 2.0;

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					Assert::AreEqual(0.0, result.Get(i, j));
		}

		TEST_METHOD(OperatorEquals)
		{
			Matrix a(2, 2);
			Matrix b(2, 2);
			Assert::IsTrue(a == b);

			Matrix c(3, 3);
			Assert::IsFalse(a == c);
			Assert::IsTrue(a != c);
		}

		TEST_METHOD(Transposition)
		{
			Matrix m(2, 3);
			Matrix t = m.Transposition();

			Assert::AreEqual(3, t.GetY());
			Assert::AreEqual(2, t.GetX());
		}

		TEST_METHOD(Trace)
		{
			Matrix m(3, 3);
			Assert::AreEqual(0.0, m.Trace());

			try {
				Matrix m2(2, 3);
				double trace = m2.Trace();
				Assert::Fail();
			}
			catch (std::exception&) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(OperatorAssignment)
		{
			Matrix a(2, 2);
			Matrix b;
			b = a;
			Assert::IsTrue(a == b);
		}

		TEST_METHOD(CompoundOperators)
		{
			Matrix a(2, 2);
			Matrix b(2, 2);
			a += b;
			a -= b;
			a *= 2.0;

			Assert::IsTrue(a == b);
		}
	};
}
