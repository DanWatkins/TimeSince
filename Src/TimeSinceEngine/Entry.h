#include <string>
#include <vector>

typedef std::string String;


enum class CountDirection
{
	Since
};


enum class TimeUnit
{
	Day
};


class Entry
{
private:
	String mTitle;

	int mDate;
	CountDirection mCountDirection;
	String mEventText;
	std::vector<String> mTags;
	TimeUnit mTimeUnit;
	unsigned mDecimalPlaces;

public:
	Entry() {}
	Entry(String title) { mTitle = title; }
	Entry(int date, CountDirection countDirection, String eventText, std::vector<String> tags, TimeUnit timeUnit, unsigned decimalPlaces);

	String getTitle() { return mTitle; }

	int getDate() { return mDate; }
	CountDirection getCountDirection() { return mCountDirection; }
	String getEventText() { return mEventText; }
	std::vector<String> getTags() { return mTags; }
	TimeUnit getTimeUnit() { return mTimeUnit; }
	unsigned getDecimalPlaces() { return mDecimalPlaces; }
};