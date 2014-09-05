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


		TEST_METHOD(EntryTimeTextRelativeToDateBefore)
		{
			{
				QDateTime mainDate(QDate(1995, 1, 3), QTime(18, 30));
				QDateTime preDate(QDate(2035, 1, 3), QTime(21, 55));
				const Entry entry(mainDate, "irrelevant", "irrelevant", std::vector<String>());

				AssertAreEqual("14610 days", entry.buildTimeText(preDate, TimeUnit::Day));
				AssertAreEqual("350643 hours", entry.buildTimeText(preDate, TimeUnit::Hour));
				AssertAreEqual("21038605 minutes", entry.buildTimeText(preDate, TimeUnit::Minute));				
				AssertAreEqual("1262316300 seconds", entry.buildTimeText(preDate, TimeUnit::Second));
			}


			{
				QDateTime mainDate(QDate(2014, 9, 2), QTime(22, 35));
				QDateTime preDate(QDate(2014, 9, 2), QTime(21, 55));
				const Entry entry(mainDate, "irrelevant", "irrelevant", std::vector<String>());

				AssertAreEqual("0 days", entry.buildTimeText(preDate, TimeUnit::Day));
				AssertAreEqual("0 hours", entry.buildTimeText(preDate, TimeUnit::Hour));
				AssertAreEqual("40 minutes", entry.buildTimeText(preDate, TimeUnit::Minute));				
				AssertAreEqual("2400 seconds", entry.buildTimeText(preDate, TimeUnit::Second));
			}


			{
				QDateTime mainDate(QDate(2014, 9, 2), QTime(22, 35));
				QDateTime preDate(QDate(2014, 9, 2), QTime(21, 20));
				const Entry entry(mainDate, "irrelevant", "irrelevant", std::vector<String>());

				AssertAreEqual("0 days", entry.buildTimeText(preDate, TimeUnit::Day));
				AssertAreEqual("1 hours", entry.buildTimeText(preDate, TimeUnit::Hour));
				AssertAreEqual("75 minutes", entry.buildTimeText(preDate, TimeUnit::Minute));				
				AssertAreEqual("4500 seconds", entry.buildTimeText(preDate, TimeUnit::Second));
			}
		}
	};
}