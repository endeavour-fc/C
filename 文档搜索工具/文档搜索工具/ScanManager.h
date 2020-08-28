#pragma once
#include"DataManager.h"
class ScanManager
{
public:
	static ScanManager& CreateInstance(const string &path);
	void ScanDirectory(const string &path);
	void StartScan(const string &path);
private:
	ScanManager();
};
