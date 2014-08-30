#include <QString>
#include <QtTest>

class TimeSinceTestTest : public QObject
{
	Q_OBJECT

public:
	TimeSinceTestTest();

private Q_SLOTS:
	void testCase1()
	{
		QVERIFY2(1, "Failure");
	}

};

TimeSinceTestTest::TimeSinceTestTest()
{
}

#include "tst_timesincetesttest.moc"
