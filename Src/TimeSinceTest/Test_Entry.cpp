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


		void assertThing(QDate mainDate, String preText, String postText, QDate beforeDate, QDate afterDate)
		{
			Entry entry(mainDate, preText, postText, std::vector<String>());
			AssertAreEqual(String("Until ")+preText, entry.buildBaseText(beforeDate));
			AssertAreEqual(String("Since ")+postText, entry.buildBaseText(afterDate));
		}



		TEST_METHOD(EntryDisplayTextRelativeToDateBefore)
		{
			assertThing(QDate(2014, 9, 2), "I go to work", "I went to work", QDate(2014, 9, 1),
						QDate(2014, 9, 3));

			assertThing(QDate(1961, 10, 29), "my Dad is born", "my Dad was born", QDate(1066, 7, 21),
						QDate(2014, 9, 3));
		}
	};
}