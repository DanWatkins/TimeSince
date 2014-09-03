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


		void assertBaseTextRelativeDates(QDate mainDate, String preText, String postText, QDate beforeDate, QDate afterDate)
		{
			Entry entry(mainDate, preText, postText, std::vector<String>());
			AssertAreEqual(String("Until ")+preText, entry.buildBaseText(beforeDate));
			AssertAreEqual(String("Since ")+postText, entry.buildBaseText(afterDate));
		}


	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			{
				QDate mainDate(1995, 1, 3);
				assertInstantiateAndInspectEntry(mainDate, "I will be born", "I was born",
												 std::vector<String>());
			}
			

			{
				QDate mainDate(2013, 6, 8);
				assertInstantiateAndInspectEntry(mainDate, "I graduate high school",
												 "I graduated high school",
												 std::vector<String>());
			}
		}


		TEST_METHOD(EntryDisplayTextRelativeToDateBefore)
		{
			{
				QDate mainDate(2014, 9, 2);
				QDate preDate(2014, 9, 1);
				QDate postDate(2014, 9, 3);
				assertBaseTextRelativeDates(mainDate, "I go to work", "I went to work",
											preDate, postDate);
			}


			{
				QDate mainDate(1961, 10, 29);
				QDate preDate(1066, 7, 21);
				QDate postDate(2014, 9, 3);
				assertBaseTextRelativeDates(mainDate, "my Dad is born", "my Dad was born",
											preDate, postDate);
			}
		}
	};
}