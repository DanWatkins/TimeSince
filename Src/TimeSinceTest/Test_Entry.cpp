#include "Utility.h"
#include <TimeSince\Entry.h>

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(const QDateTime &date, const QString &preText, const QString &postText)
		{
			Entry entry(date, preText, postText);

			AssertAreEqual(date, entry.getDate());
			AssertAreEqual(preText, entry.getPreText());
			AssertAreEqual(postText, entry.getPostText());
			AssertAreEqual(date, entry.getDate());
		}


		void assertBaseTextRelativeDates(const QDateTime &mainDate, const QString &preText,
										 const QString &postText, const QDateTime &beforeDate,
										 const QDateTime &afterDate)
		{
			Entry entry(mainDate, preText, postText);
			AssertAreEqual(QString("until ")+preText, entry.buildBaseText(beforeDate));
			AssertAreEqual(QString("since ")+postText, entry.buildBaseText(afterDate));
		}


		void assertBuildTimeText(const QDateTime &mainDate, const QDateTime &compareDate,
								 const QString &stringDay, const QString &stringHour,
								 const QString &stringMinute, const QString &stringSecond)
		{
			const Entry entry(mainDate, "irrelevant", "irrelevant");

			AssertAreEqual(stringDay, entry.buildTimeText(compareDate, TimeUnit::Day));
			AssertAreEqual(stringHour, entry.buildTimeText(compareDate, TimeUnit::Hour));
			AssertAreEqual(stringMinute, entry.buildTimeText(compareDate, TimeUnit::Minute));				
			AssertAreEqual(stringSecond, entry.buildTimeText(compareDate, TimeUnit::Second));
		}


		void assertBuildDisplayText(const QDateTime &mainDate, const QDateTime &compareDate,
									const QString &preText, const QString &postText,
									const QString &stringDay, const QString &stringHour,
									const QString &stringMinute, const QString &stringSecond)
		{
			Entry entry(mainDate, preText, postText);

			AssertAreEqual(stringDay, entry.buildFullText(compareDate, TimeUnit::Day));
			AssertAreEqual(stringHour, entry.buildFullText(compareDate, TimeUnit::Hour));
			AssertAreEqual(stringMinute, entry.buildFullText(compareDate, TimeUnit::Minute));
			AssertAreEqual(stringSecond, entry.buildFullText(compareDate, TimeUnit::Second));
		}



	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			{
				QDateTime mainDate(QDate(1995, 1, 3), QTime(18, 30));
				assertInstantiateAndInspectEntry(mainDate, "I will be born", "I was born");
			}
			

			{
				QDateTime mainDate(QDate(2013, 6, 8), QTime(17, 23));
				assertInstantiateAndInspectEntry(mainDate, "I graduate high school",
												 "I graduated high school");
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


		TEST_METHOD(EntryBuildFullText)
		{
			assertBuildDisplayText(QDateTime(QDate(2012, 1, 3), QTime(13, 20)),
									QDateTime(QDate(1985, 7, 2), QTime(15, 0)),
									"I buy Battlefield 3", "I bought Battlefield 3",
									"9681 days until I buy Battlefield 3",
									"232343 hours until I buy Battlefield 3",
									"13940600 minutes until I buy Battlefield 3",
									"836436000 seconds until I buy Battlefield 3");

			assertBuildDisplayText(QDateTime(QDate(2012, 1, 3), QTime(13, 20)),
									QDateTime(QDate(2014, 9, 6), QTime(15, 0)),
									"I buy Battlefield 3", "I bought Battlefield 3",
									"977 days since I bought Battlefield 3",
									"23448 hours since I bought Battlefield 3",
									"1406920 minutes since I bought Battlefield 3",
									"84415200 seconds since I bought Battlefield 3");
		}


		TEST_METHOD(EntryAddAndFilterByTag)
		{
			{
				Entry entry;
				entry.addTag("car");
				Assert::IsTrue(entry.hasTag("car"), L"The entry does not have tag \"car\"");
			}

			{
				Entry entry;
				entry.addTag("adventure");
				Assert::IsFalse(entry.hasTag("friends"), L"The entry has tag \"adventure\" when it shouldn't");
			}

			{
				Entry entry;
				entry.addTag("friends");

				Assert::IsTrue(entry.hasTag("friends"), L"The entry does not have tag \"adventure\"");
			}
		}


		TEST_METHOD(EntryAddAndFilterByTagsWhichExist)
		{
			Entry entry;
			entry.addTag("car");
			entry.addTag("programming");

			Assert::IsTrue(entry.hasTags("car", "programming"));
		}


		TEST_METHOD(EntryAddAndFilterByTagsWhichDontExist)
		{
			Entry entry;
			entry.addTag("dog");
			entry.addTag("cat");

			Assert::IsFalse(entry.hasTags("dog", "cat", "frog"));
		}


		TEST_METHOD(EntryAddAndFilterByTagsWhichAreBlank)
		{
			Entry entry;
			entry.addTag("");
			entry.addTag("lizzard");

			Assert::IsTrue(entry.hasTags("", "lizzard"));
		}


		TEST_METHOD(EntryCompareSameEntries)
		{
			Entry e1(QDateTime(QDate(1066, 1, 1), QTime(0, 0)), "until 1066", "since 1066");
			Entry e2(QDateTime(QDate(1066, 1, 1), QTime(0, 0)), "until 1066", "since 1066");

			Assert::IsTrue(e1 == e2);
		}


		TEST_METHOD(EntryCompareDifferentEntries)
		{
			Entry e1(QDateTime(QDate(1066, 1, 1), QTime(0, 0)), "until 1066", "since 1066");
			Entry e2(QDateTime(QDate(2004, 1, 1), QTime(0, 0)), "until 2004", "since 2004");

			Assert::IsFalse(e1 == e2);
		}


		TEST_METHOD(EntryAddAndFilterByTagsScrambledOrder)
		{
			Entry entry;
			entry.addTag("cow");
			entry.addTag("goat");
			entry.addTag("visualStudio");
			entry.addTag("screen");

			Assert::IsTrue(entry.hasTags("visualStudio", "cow", "screen", "goat"));
		}
	};
}