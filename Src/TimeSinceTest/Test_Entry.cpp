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


		void assertBuildTimeText(const QDateTime &mainDate, const QDateTime &compareDate,
			   const QString &stringDay, const QString &stringHour,
			   const QString &stringMinute, const QString &stringSecond)
		{
			const Entry entry(mainDate, "irrelevant", "irrelevant", std::vector<String>());

			AssertAreEqual(stringDay, entry.buildTimeText(compareDate, TimeUnit::Day));
			AssertAreEqual(stringHour, entry.buildTimeText(compareDate, TimeUnit::Hour));
			AssertAreEqual(stringMinute, entry.buildTimeText(compareDate, TimeUnit::Minute));				
			AssertAreEqual(stringSecond, entry.buildTimeText(compareDate, TimeUnit::Second));
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


		TEST_METHOD(EntryBuildTimeText)
		{
			//plural only
			{
				assertBuildTimeText(QDateTime(QDate(1995, 1, 3), QTime(18, 30)),
									QDateTime(QDate(2035, 1, 3), QTime(21, 55)),
									"14610 days", "350643 hours", "21038605 minutes",
									"1262316300 seconds");


				assertBuildTimeText(QDateTime(QDate(2014, 9, 2), QTime(22, 35)),
									QDateTime(QDate(2014, 9, 2), QTime(21, 55)),
									"0 days", "0 hours", "40 minutes", "2400 seconds");
			}

			//singular occurence
			{
				assertBuildTimeText(QDateTime(QDate(2014, 9, 1), QTime(10, 0)),
									QDateTime(QDate(2014, 9, 2), QTime(10, 0)),
									"1 day", "24 hours", "1440 minutes", "86400 seconds");


				assertBuildTimeText(QDateTime(QDate(2014, 9, 2), QTime(22, 35)),
									QDateTime(QDate(2014, 9, 2), QTime(21, 20)),
									"0 days", "1 hour", "75 minutes", "4500 seconds");

				assertBuildTimeText(QDateTime(QDate(2005, 5, 15), QTime(18, 0)),
									QDateTime(QDate(2005, 5, 15), QTime(18, 1)),
									"0 days", "0 hours", "1 minute", "60 seconds");

				assertBuildTimeText(QDateTime(QDate(1989, 1, 7), QTime(9, 53, 0)),
									QDateTime(QDate(1989, 1, 7), QTime(9, 53, 1)),
									"0 days", "0 hours", "0 minutes", "1 second");

			}
		}
	};
}