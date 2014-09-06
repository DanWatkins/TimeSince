#ifndef _TIMESINCE_ENTRY_H
#define _TIMESINCE_ENTRY_H

#include <string>
#include <vector>
#include <QtCore/QDateTime>

typedef std::string String;


enum class TimeUnit
{
	Day,
	Hour,
	Minute,
	Second
};


class Entry
{
private:
	String mTitle;
	QDateTime mDate;
	String mPreText, mPostText;
	std::vector<String> mTags;

public:
	Entry() {}
	Entry(const String &title) { mTitle = title; }
	Entry(const QDateTime &date, const String &preText, const String &postText, const std::vector<String> &tags);

	String buildBaseText(const QDateTime &compareDate) const;
	QString buildTimeText(const QDateTime &compareDate, TimeUnit timeUnit) const;

	String getTitle() const { return mTitle; }
	QDateTime getDate() const { return mDate; }
	String getPreText() const { return mPreText; }
	String getPostText() const { return mPostText; }
	std::vector<String> getTags() const { return mTags; }
};

#endif
