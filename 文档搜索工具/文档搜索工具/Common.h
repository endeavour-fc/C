#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<vector>
#include<io.h>
#include<set>
#include"sqlite3.h"
#pragma comment(lib,"./sqlite3.lib")
#define DOC_DB "doc.db"
#define DOC_TABLE "doc.tb"
#define SQL_BUFFER_SIZE 256
#define MAX_TITLE_BUFFER 128
#include<thread>
#include<chrono>
#include<windows.h>
#include<algorithm>
using namespace std;

