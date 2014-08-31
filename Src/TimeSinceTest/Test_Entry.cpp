#include "Utility.h"
#include <TimeSince\Entry.h>

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(QDate date, String eventText,
											  std::vector<String> tags)
		{
			Entry entry(date, eventText, tags);

			AssertAreEqual(date, entry.getDate());
			AssertAreEqual(eventText, entry.getEventText());
			//Assert::AreEqual(tags, eventText.getTags());
			AssertAreEqual(date, entry.getDate());
		}


	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			assertInstantiateAndInspectEntry(QDate(1995, 1, 3), "I was born",
											 std::vector<String>());
			
			assertInstantiateAndInspectEntry(QDate(2013, 6, 8), "I graduated high school",
											 std::vector<String>());
		}
	};
}