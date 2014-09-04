#include "Utility.h"
#include <TimeSince\Entry.h>

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(const QDateTime &date, const String &preText, const String &postText,
											  const std::vector<String> &tags)
		{
			Entry entry(date, preText, postText, tags);

			AssertAreEqual(date, entry.getDate());
			AssertAreEqual(preText, entry.getPreText());
			AssertAreEqual(postText, entry.getPostText());
			//Assert::AreEqual(tags, eventText.getTags());
			AssertAreEqual(date, entry.getDate());
		}


		void assertBaseTextRelativeDates(const QDateTime &mainDate, const String &preText, const String &postText,
										 const QDateTime &beforeDate, const QDateTime &afterDate)
		{
			Entry entry(mainDate, preText, postText, std::vector<String>());
			AssertAreEqual(String("Until ")+preText, entry.buildBaseText(beforeDate));
			AssertAreEqual(String("Since ")+postText, entry.buildBaseText(afterDate));
		}


	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			{
				QDateTime mainDate(QDate(1995, 1, 3), QTime(18, 30));
				assertInstantiateAndInspectEntry(mainDate, "I will be born", "I was born",
												 std::vector<String>());
			}
			

			{
				QDateTime mainDate(QDate(2013, 6, 8), QTime(17, 23));
				assertInstantiateAndInspectEntry(mainDate, "I graduate high school",
												 "I graduated high school",
												 std::vector<String>());
			}
		}


		TEST_METHOD(EntryBaseTextRelativeToDateBeforeAfter)
		{
			{
				QDateTime mainDate(QDate(2014, 9, 2), QTime(9, 0));
				QDateTime preDate(QDate(2014, 9, 1), QTime(0, 10));
				QDateTime postDate(QDate(2014, 9, 3), QTime(16, 33));
				assertBaseTextRelativeDates(mainDate, "I go to work", "I went to work",
											preDate, postDate);
			}


			{
				QDateTime mainDate(QDate(1961, 10, 29), QTime(7, 20));
				QDateTime preDate(QDate(1066, 7, 21), QTime(4, 50));
				QDateTime postDate(QDate(2014, 9, 3), QTime(11, 21));
				assertBaseTextRelativeDates(mainDate, "my Dad is born", "my Dad was born",
											preDate, postDate);
			}
		}
	};
}