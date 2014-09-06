#ifndef _TIMESINCETEST_UTILITY_H
#define _TIMESINCETEST_UTILITY_H

#include <string>
#include <QtCore/QString>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void AssertAreEqual(const std::string &s1, const std::string &s2,
					const std::string &message="", const __LineInfo *lineInfo=nullptr);

void AssertAreEqual(const QString &expected, const QString &actual, const QString &message="",
					const __LineInfo *lineInfo=nullptr);




/*
 * \brief Asserts if expected does not equal actual based on the == operator. Type must implement
 * toString().
 */
template <typename Type>
void AssertAreEqual(const Type &expected, const Type &actual, const std::string &message="",
					const __LineInfo *lineInfo=nullptr)
{
	std::string s1 = expected.toString().toStdString();
	std::string s2 = actual.toString().toStdString();

	bool sameString = (s1 == s2);

	if (expected != actual)
	{
		if (sameString)
			Assert::Fail(L"The strings are the same, but the objects are not!", lineInfo);
		else
			AssertAreEqual(s1, s2, message, lineInfo);
	}
}

#endif

