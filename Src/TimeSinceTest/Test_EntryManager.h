#ifndef _TIMESINCETEST_ENTRYMANAGER_H
#define _TIMESINCETEST_ENTRYMANAGER_H

#include <TimeSince\EntryManager.h>
#include <QtTest>


class Test_EntryManager : public QObject
{
	Q_OBJECT


private:
	void assertCreateAndGetEntry(String title)
	{
		EntryManager manager;
		int id = manager.createEntry(title);

		Entry entry = manager.getEntry(id);
		QVERIFY(entry.getTitle() == title);
	}

	EntryManager entryManager;
	const String title1 = "Hello";
	const String title2 = "Bye";

private Q_SLOTS:
	void CreateAndGetEntry()
	{
		assertCreateAndGetEntry("My first entry");
		assertCreateAndGetEntry("My second entry");
		assertCreateAndGetEntry("Entry 4");
		assertCreateAndGetEntry("");
	}


	void CreateAndGetMultipleEntries()
	{
		int id1 = entryManager.createEntry("Entry 1");
		int id2 = entryManager.createEntry("Entry 2");

		QVERIFY("Entry 1" == entryManager.getEntry(id1).getTitle());
		QVERIFY("Entry 2" == entryManager.getEntry(id2).getTitle());
	}


	void CreateAndCountAndEraseEntry()
	{
		int id1 = entryManager.createEntry("Entry 1");
		QVERIFY2(1 == entryManager.entryCount(), "Wrong number of entries");

		int id2 = entryManager.createEntry("Entry 2");
		QVERIFY2(2 == entryManager.entryCount(), "Wrong number of entries");

		entryManager.erase(id1);
		QVERIFY2(1 == entryManager.entryCount(), "Wrong number of entries");
	}


	void EraseAndVerifyEntry()
	{
		const String title1 = "Hello";
		int id1 = entryManager.createEntry(title1);

		entryManager.erase(id1);

		/*Assert::ExpectException<std::out_of_range>([&]
		{
			entryManager.getEntry(id1);
		});*/
	}


	void EraseAndVerifyMultipleEntries1()
	{
		int id1 = entryManager.createEntry(title1);
		int id2 = entryManager.createEntry(title2);

		entryManager.erase(id1);
		QVERIFY(title2 == entryManager.getEntry(id2).getTitle());
	}


	void EraseAndVerifyMultipleEntries2()
	{
		int id1 = entryManager.createEntry(title1);
		int id2 = entryManager.createEntry(title2);

		entryManager.erase(id2);
		QVERIFY(title1 == entryManager.getEntry(id1).getTitle());
	}
};

#endif
