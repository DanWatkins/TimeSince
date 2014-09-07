#include "Utility.h"
#include <TimeSince\Entry.h>

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(const QDateTime &date, const QString &preText, const QString &postText,
											  const QVector<QString> &tags)
		{
			Entry entry(date, preText, postText, tags);

			AssertAreEqual(date, entry.getDate());
			AssertAreEqual(preText, entry.getPreText());
			AssertAreEqual(postText, entry.getPostText());
			//Assert::AreEqual(tags, eventText.getTags());
			AssertAreEqual(date, entry.getDate());
		}


		void assertBaseTextRelativeDates(const QDateTime &mainDate, const QString &preText, const QString &postText,
										 const QDateTime &beforeDate, const QDateTime &afterDate)
		{
			Entry entry(mainDate, preText, postText, QVector<QString>());
			AssertAreEqual(QString("Until ")+preText, entry.buildBaseText(beforeDate));
			AssertAreEqual(QString("Since ")+postText, entry.buildBaseText(afterDate));
		}


		void assertBuildTimeText(const QDateTime &mainDate, const QDateTime &compareDate,
			   const QString &stringDay, const QString &stringHour,
			   const QString &stringMinute, const QString &stringSecond)
		{
			const Entry entry(mainDate, "irrelevant", "irrelevant", QVector<QString>());

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
													QVector<QString>());
			}
			

			{
				QDateTime mainDate(QDate(2013, 6, 8), QTime(17, 23));
				assertInstantiateAndInspectEntry(mainDate, "I graduate high school",
												 "I graduated high school",
												 QVector<QString>());
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


		void assertBuildDisplayText(const QDateTime &mainDate, const QDateTime &compareDate,
									const QString &preText, const QString &postText,
									const QString &stringDay, const QString &stringHour,
									const QString &stringMinute, const QString &stringSecond)
		{
			Entry entry(mainDate, preText, postText,
						QVector<QString>());

			AssertAreEqual(stringDay, entry.buildDisplayText(compareDate, TimeUnit::Day));
			AssertAreEqual(stringHour, entry.buildDisplayText(compareDate, TimeUnit::Hour));
			AssertAreEqual(stringMinute, entry.buildDisplayText(compareDate, TimeUnit::Minute));
			AssertAreEqual(stringSecond, entry.buildDisplayText(compareDate, TimeUnit::Second));
		}


		TEST_METHOD(EntryBuildDisplayText)
		{
			assertBuildDisplayText(QDateTime(QDate(2012, 1, 3), QTime(13, 20)),
									QDateTime(QDate(1985, 7, 2), QTime(15, 0)),
									"I buy Battlefield 3", "I bought Battlefield 3",
									"9681 days Until I buy Battlefield 3",
									"232343 hours Until I buy Battlefield 3",
									"13940600 minutes Until I buy Battlefield 3",
									"836436000 seconds Until I buy Battlefield 3");

			assertBuildDisplayText(QDateTime(QDate(2012, 1, 3), QTime(13, 20)),
									QDateTime(QDate(2014, 9, 6), QTime(15, 0)),
									"I buy Battlefield 3", "I bought Battlefield 3",
									"977 days Since I bought Battlefield 3",
									"23448 hours Since I bought Battlefield 3",
									"1406920 minutes Since I bought Battlefield 3",
									"84415200 seconds Since I bought Battlefield 3");
		}
	};
}