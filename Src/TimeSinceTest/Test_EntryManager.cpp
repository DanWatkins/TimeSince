#include "Utility.h"
#include <TimeSince\EntryManager.h>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeSinceTest
{
	TEST_CLASS(Test_EntryManager)
	{
	private:
		const QDateTime defaultDate = QDateTime(QDate(2003, 5, 7), QTime(17, 35));


		void assertCreateAndGetEntry(QString title)
		{
			EntryManager manager;
			Entry entry(QDateTime(QDate(1995, 1, 3), QTime(18, 30)), "until I am born", "since I was born");
			int id = manager.addEntry(entry);

			Assert::IsTrue(manager.getEntry(id) == entry);
		}

		EntryManager entryManager;
		const QString title1 = "Hello";
		const QString title2 = "Bye";

	public:
		TEST_METHOD(CreateAndGetEntry)
		{
			assertCreateAndGetEntry("My first entry");
			assertCreateAndGetEntry("My second entry");
			assertCreateAndGetEntry("Entry 4");
			assertCreateAndGetEntry("");
		}


		TEST_METHOD(CreateAndGetMultipleEntries)
		{
			Entry entry1(QDateTime(QDate(1941, 1, 3)), "heyThere", "heyedThere");
			Entry entry2(QDateTime(QDate(1974, 12, 31)), "hiThere", "hiedThere");

			int id1 = entryManager.addEntry(entry1);
			int id2 = entryManager.addEntry(entry2);

			Assert::IsTrue(entry1 == entryManager.getEntry(id1), L"The first entry was not retrieved properly");
			Assert::IsTrue(entry2 == entryManager.getEntry(id2), L"The second entry was not retrieve properly");
		}


		TEST_METHOD(CreateAndCountAndEraseEntry)
		{
			int id1 = entryManager.addEntry(Entry(defaultDate, "irrelevant1", "irrelevant1"));
			Assert::AreEqual(1, entryManager.entryCount(), L"Wrong number of entries");

			int id2 = entryManager.addEntry(Entry(defaultDate, "irrelevant2", "irrelevant2"));
			Assert::AreEqual(2, entryManager.entryCount(), L"Wrong number of entries");

			entryManager.erase(id1);
			Assert::AreEqual(1, entryManager.entryCount(), L"Wrong number of entries");
		}


		TEST_METHOD(EraseAndVerifyEntry)
		{
			int id1 = entryManager.addEntry(Entry(defaultDate, "irrelevant1", "irrelevant1"));

			entryManager.erase(id1);

			Assert::ExpectException<std::exception>([&]
			{
				entryManager.getEntry(id1);
			});
		}


		TEST_METHOD(EraseAndVerifyMultipleEntries1)
		{
			int id1 = entryManager.addEntry(Entry(defaultDate, "irrelevant1", "irrelevant1"));
			int id2 = entryManager.addEntry(Entry(defaultDate, "irrelevant2", "irrelevant2"));

			entryManager.erase(id1);
			AssertAreEqual("irrelevant2", entryManager.getEntry(id2).getPreText());
		}


		TEST_METHOD(EraseAndVerifyMultipleEntries2)
		{
			int id1 = entryManager.addEntry(Entry(defaultDate, "irrelevant1", "irrelevant1"));
			int id2 = entryManager.addEntry(Entry(defaultDate, "irrelevant2", "irrelevant2"));

			entryManager.erase(id2);
			AssertAreEqual("irrelevant1", entryManager.getEntry(id1).getPreText());
		}


		TEST_METHOD(EntryManagerExportImportSingleEntry1)
		{
			Entry startEntry;
			int id = entryManager.addEntry(startEntry);
			QSharedPointer<QByteArray> byteArray = entryManager.exportEntries();

			EntryManager otherManager;
			otherManager.importEntries(byteArray);

			Assert::IsTrue(startEntry == otherManager.getEntry(id), L"Imported entry does not match exported entry");
		}


		TEST_METHOD(EntryManagerExportImportSingleEntry2)
		{
			Entry startEntry(QDateTime(QDate(1998, 12, 14), QTime(14, 20)), "a day in 1998", "a day in 1998");
			startEntry.addTag("day");
			startEntry.addTag("1998");
			int id = entryManager.addEntry(startEntry);
			QSharedPointer<QByteArray> byteArray = entryManager.exportEntries();

			EntryManager otherManager;
			otherManager.importEntries(byteArray);

			Assert::IsTrue(startEntry == otherManager.getEntry(id), L"Imported entry does not match exported entry");
		}
	};
}