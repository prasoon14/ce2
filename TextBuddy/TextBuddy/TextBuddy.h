#ifndef TEXTBUDDY_H_
#define TEXTBUDDY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void updateFile(char*);
void add(string);
void del(int);
void display(char*);
void clear();
void collectData(char*);
void sortFile(vector<string>&);
bool isFileSorted(vector<string>&);

#endif