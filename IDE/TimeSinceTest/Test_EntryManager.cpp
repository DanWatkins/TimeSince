#include "CppUnitTest.h"
#include <TimeSinceEngine\EntryManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void AssertAreEqual(const std::string &s1, const std::string &s2)
{
	Assert::AreEqual(s1.c_str(), s2.c_str());
}


namespace TimeSinceTest
{
	TEST_CLASS(Test_EntryManager)
	{
	private:
		void assertCreateAndGetEntry(std::string title)
		{
			EntryManager manager;
			int id = manager.createEntry(title);

			Entry entry = manager.getEntry(id);
			AssertAreEqual(entry.getTitle(), title);
		}

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
			EntryManager manager;
			int id1 = manager.createEntry("Entry 1");
			int id2 = manager.createEntry("Entry 2");

			AssertAreEqual("Entry 1", manager.getEntry(id1).getTitle());
			AssertAreEqual("Entry 2", manager.getEntry(id2).getTitle());
		}


		TEST_METHOD(CreateAndCountEntry)
		{
			EntryManager manager;

			int id1 = manager.createEntry("Entry 1");
			Assert::AreEqual(1, manager.entryCount(), L"Wrong number of entries");

			int id2 = manager.createEntry("Entry 2");
			Assert::AreEqual(2, manager.entryCount(), L"Wrong number of entries");
		}
	};
}