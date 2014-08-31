#include "Utility.h"

void AssertAreEqual(const std::string &s1, const std::string &s2, const __LineInfo *lineInfo)
{
	Assert::AreEqual(s1.c_str(), s2.c_str(), lineInfo);
}


//template <typename Type>
//void AssertAreEqual(const Type &expected, const Type &actual, const std::string &message, const __LineInfo *lineInfo)
