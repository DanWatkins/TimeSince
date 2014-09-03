#ifndef _TIMESINCE_ENTRY_H
#define _TIMESINCE_ENTRY_H

#include <string>
#include <vector>
#include <QtCore/QDateTime>

typedef std::string String;

class Entry
{
private:
	String mTitle;
	QDateTime mDate;
	String mPreText, mPostText;
	std::vector<String> mTags;

public:
	Entry() {}
	Entry(String title) { mTitle = title; }
	Entry(QDateTime date, String preText, String postText, std::vector<String> tags);

	String buildBaseText(QDateTime compareDate);

	String getTitle() { return mTitle; }
	QDateTime getDate() { return mDate; }
	String getPreText() { return mPreText; }
	String getPostText() { return mPostText; }
	std::vector<String> getTags() { return mTags; }
};

#endif
