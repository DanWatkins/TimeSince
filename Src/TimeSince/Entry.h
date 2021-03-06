#ifndef _TIMESINCE_ENTRY_H
#define _TIMESINCE_ENTRY_H

#include <QtCore/QDateTime>
#include <QtCore/QMap>
#include <QtCore/QXmlStreamWriter>


enum class TimeUnit
{
	Day,
	Hour,
	Minute,
	Second
};


class Entry
{
public:
	Entry() {}
	Entry(const QDateTime &date, const QString &preText, const QString &postText);

	QString buildBaseText(const QDateTime &compareDate) const;
	QString buildTimeText(const QDateTime &compareDate, TimeUnit timeUnit) const;
	QString buildFullText(const QDateTime &compareDate, TimeUnit timeUnit) const;

	void addTag(QString tag) { mTags.insert(tag, true); }
	bool hasTag(const QString &tag) const { return mTags.value(tag, false); }

	template<typename ...Types>
	bool hasTags(const QString &first, Types... rest) const
	{
		if (!hasTag(first))
			return false;
		
		return hasTags(rest...);
	}

	QDateTime getDate() const { return mDate; }
	QString getPreText() const { return mPreText; }
	QString getPostText() const { return mPostText; }

	bool operator == (const Entry &rhs) const;

	void writeToXmlStream(QXmlStreamWriter &stream) const;
	void readFromXmlStream(QXmlStreamReader &xml);

private:
	QDateTime mDate;
	QString mPreText, mPostText;

	typedef QMap<QString, bool> TagsMap;
	TagsMap mTags;

	//This is only to break out of recursion for the variadic hasTags
	bool hasTags() const { return true; }
};


#endif
