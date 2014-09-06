#include "Utility.h"

void AssertAreEqual(const std::string &s1, const std::string &s2, const std::string &message,
					const __LineInfo *lineInfo)
{
	Assert::AreEqual(s1.c_str(), s2.c_str(), message.c_str(), lineInfo);
}


void AssertAreEqual(const QString &expected, const QString &actual, const QString &message,
					const __LineInfo *lineInfo)
{
	AssertAreEqual(expected.toStdString(), actual.toStdString(), message.toStdString(), lineInfo);
}