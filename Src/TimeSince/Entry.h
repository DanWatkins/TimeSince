#ifndef _TIMESINCE_ENTRY_H
#define _TIMESINCE_ENTRY_H

#include <QtCore/QDateTime>
#include <QtCore/QMap>

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
	QString mTitle;
	QDateTime mDate;
	QString mPreText, mPostText;
	QMap<QString, bool> mTags;

public:
	Entry() {}
	Entry(const QString &title) { mTitle = title; }
	Entry(const QDateTime &date, const QString &preText, const QString &postText);

	QString buildBaseText(const QDateTime &compareDate) const;
	QString buildTimeText(const QDateTime &compareDate, TimeUnit timeUnit) const;
	QString buildFullText(const QDateTime &compareDate, TimeUnit timeUnit) const;

	void addTag(QString tag) { mTags.insert(tag, true); }
	bool hasTag(const QString &tag) { return mTags.value(tag, false); }

	QString getTitle() const { return mTitle; }
	QDateTime getDate() const { return mDate; }
	QString getPreText() const { return mPreText; }
	QString getPostText() const { return mPostText; }
};

#endif
