#include "Entry.h"


Entry::Entry(int date, CountDirection countDirection, String eventText, std::vector<String> tags, TimeUnit timeUnit, unsigned decimalPlaces)
{
	mDate = date;
	mCountDirection = countDirection;
	mEventText = eventText;
	mTags = tags;
	mTimeUnit = timeUnit;
	mDecimalPlaces = decimalPlaces;
}