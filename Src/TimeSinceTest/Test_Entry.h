#ifndef _TIMESINCETEST_ENTRY_H
#define _TIMESINCETEST_ENTRY_H


#include <TimeSince/Entry.h>
#include <QtTest>

class Test_Entry : public QObject
{
	Q_OBJECT

private:
	void assertInstantiateAndInspectEntry(QDate date, String eventText, std::vector<String> tags, unsigned decimalPlaces)
	{
		Entry entry(date, eventText, tags, 0);

		QVERIFY2(date == entry.getDate(), "The dates don't match up");
		QVERIFY(eventText == entry.getEventText());
		//Assert::AreEqual(tags, eventText.getTags());
		QVERIFY(decimalPlaces == entry.getDecimalPlaces());
	}


private Q_SLOTS:
	void InstantiateAndInspectEntry()
	{
		assertInstantiateAndInspectEntry(QDate(1995, 1, 3), "I was born", std::vector<String>(), 0);
		assertInstantiateAndInspectEntry(QDate(2013, 6, 8), "I graduated high school", std::vector<String>(), 0);
	}
};

#endif
