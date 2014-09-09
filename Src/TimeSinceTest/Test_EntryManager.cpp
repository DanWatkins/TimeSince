#include "Utility.h"
#include <TimeSince\EntryManager.h>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeSinceTest
{
	TEST_CLASS(Test_EntryManager)
	{
	private:
		void assertCreateAndGetEntry(QString title)
		{
			EntryManager manager;
			int id = manager.createEntry(title);

			Entry entry = manager.getEntry(id);
			AssertAreEqual(entry.getTitle(), title);
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
			int id1 = entryManager.createEntry("Entry 1");
			int id2 = entryManager.createEntry("Entry 2");

			AssertAreEqual("Entry 1", entryManager.getEntry(id1).getTitle());
			AssertAreEqual("Entry 2", entryManager.getEntry(id2).getTitle());
		}


		TEST_METHOD(CreateAndCountAndEraseEntry)
		{
			int id1 = entryManager.createEntry("Entry 1");
			Assert::AreEqual(1, entryManager.entryCount(), L"Wrong number of entries");

			int id2 = entryManager.createEntry("Entry 2");
			Assert::AreEqual(2, entryManager.entryCount(), L"Wrong number of entries");

			entryManager.erase(id1);
			Assert::AreEqual(1, entryManager.entryCount(), L"Wrong number of entries");
		}


		TEST_METHOD(EraseAndVerifyEntry)
		{
			const QString title1 = "Hello";
			int id1 = entryManager.createEntry(title1);

			entryManager.erase(id1);

			Assert::ExpectException<std::exception>([&]
			{
				entryManager.getEntry(id1);
			});
		}


		TEST_METHOD(EraseAndVerifyMultipleEntries1)
		{
			int id1 = entryManager.createEntry(title1);
			int id2 = entryManager.createEntry(title2);

			entryManager.erase(id1);
			AssertAreEqual(title2, entryManager.getEntry(id2).getTitle());
		}


		TEST_METHOD(EraseAndVerifyMultipleEntries2)
		{
			int id1 = entryManager.createEntry(title1);
			int id2 = entryManager.createEntry(title2);

			entryManager.erase(id2);
			AssertAreEqual(title1, entryManager.getEntry(id1).getTitle());
		}


		TEST_METHOD(EntryManagerExportImport)
		{
			Entry startEntry;
			int id = entryManager.addEntry(startEntry);
			QSharedPointer<QByteArray> byteArray = entryManager.exportEntries();

			EntryManager otherManager;
			otherManager.importEntries(byteArray);

			Assert::IsTrue(startEntry == otherManager.getEntry(id), L"Imported entry does not match exported entry");
		}
	};
}