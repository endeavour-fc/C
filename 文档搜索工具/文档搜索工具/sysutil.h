#pragma once
#include"Common.h"
void DirestionList(string& Path,vector<string>& subdir,vector<string>& subfile)
{
	string _path = Path;
	_path += "\\*.*";
	_finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);
	if (handle == -1)
	{
		perror("firstfind");
		return;
	}
	do
	{
		if (strcmp(file.name, ".")==0 || strcmp(file.name, "..")==0)
		{
			continue;
		}
		if (file.attrib&_A_SUBDIR)
		{
			subdir.push_back(file.name);
		}
		else
		{
			subfile.push_back(file.name);
		}
	} while (_findnext(handle, &file)==0);
	_findclose(handle);
}