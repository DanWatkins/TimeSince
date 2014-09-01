#include "Utility.h"
#include <TimeSince\Entry.h>

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(QDate date, String preText, String postText,
											  std::vector<String> tags)
		{
			Entry entry(date, preText, postText, tags);

			AssertAreEqual(date, entry.getDate());
			AssertAreEqual(preText, entry.getPreText());
			AssertAreEqual(postText, entry.getPostText());
			//Assert::AreEqual(tags, eventText.getTags());
			AssertAreEqual(date, entry.getDate());
		}


	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			assertInstantiateAndInspectEntry(QDate(1995, 1, 3), "I will be born", "I was born",
											 std::vector<String>());
			
			assertInstantiateAndInspectEntry(QDate(2013, 6, 8), "I graduate high school",
											 "I graduated high school",
											 std::vector<String>());
		}
	};
}