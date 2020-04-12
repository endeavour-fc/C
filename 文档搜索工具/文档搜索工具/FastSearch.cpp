#include"sysutil.h"

void test()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
}
int main()
{
	string path("G:\\Code\\C++");
	vector<string> subdir, subfile;
	DirestionList(path, subdir, subfile);
	for (vector<string>::iterator it1 = subfile.begin(); it1 != subfile.end(); it1++)
		cout << *it1 << endl;
	for (vector<string>::iterator it1 = subdir.begin(); it1 != subdir.end(); it1++)
		cout << *it1 << endl;
	test();
	system("pause");
	return 0;
}