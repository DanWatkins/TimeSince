#include "CppUnitTest.h"
#include <TimeSinceEngine\Entry.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeSinceTest
{
	TEST_CLASS(Test_Entry)
	{
	private:
		void assertInstantiateAndInspectEntry(int date, CountDirection countDirection, String eventText, std::vector<String> tags, TimeUnit timeUnit, unsigned decimalPlaces)
		{
			Entry entry(date, countDirection, eventText, tags, timeUnit, 0);

			Assert::AreEqual(date, entry.getDate());
			Assert::AreEqual(static_cast<int>(countDirection), static_cast<int>(entry.getCountDirection()));
			Assert::AreEqual(eventText, entry.getEventText());
			//Assert::AreEqual(tags, eventText.getTags());
			Assert::AreEqual(static_cast<int>(timeUnit), static_cast<int>(entry.getTimeUnit()));
			Assert::AreEqual(decimalPlaces, entry.getDecimalPlaces());
		}


	public:
		TEST_METHOD(InstantiateAndInspectEntry)
		{
			assertInstantiateAndInspectEntry(7110, CountDirection::Since, "I was born", std::vector<String>(), TimeUnit::Day, 0);
			assertInstantiateAndInspectEntry(65, CountDirection::Since, "I graduated high school", std::vector<String>(), TimeUnit::Day, 0);
		}
	};
}