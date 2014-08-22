#include <QString>
#include <QtTest>

class UtilityTest : public QObject
{
	Q_OBJECT

public:
	UtilityTest();

private Q_SLOTS:
	void testCase1();
};

UtilityTest::UtilityTest()
{
}

void UtilityTest::testCase1()
{
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(UtilityTest)

#include "tst_utilitytest.moc"
