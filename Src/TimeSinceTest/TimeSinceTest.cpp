#include <QtTest>

#include "Test_Entry.h"
#include "Test_EntryManager.h"

int main(int argc, char** argv)
{
   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
	 status |= QTest::qExec(obj, argc, argv);
	 delete obj;
   };

	ASSERT_TEST(new Test_Entry());
	ASSERT_TEST(new Test_EntryManager());

	return status;
}
