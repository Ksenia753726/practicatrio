#pragma once
#define HEADER_H
#ifdef HEADER_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

struct Student {
	int32_t id{};
	int32_t group{};
	std::string name;
	std::string surname;
	std::string patronymic;
	int32_t mark_ma{};
	int32_t mark_geo{};
	int32_t mark_prog{};
	int32_t avg_mark{};
};

void CheckInputFile(std::istream& fin);

int32_t FindCountOfStudents(std::istream& fin);
void FillStructArrayFromFiles(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size);


void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark);

void SortStructById(Student*& students, int32_t size);

void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* student, int32_t size);
void FillFileWithMark(std::string& filename, Student* students, int32_t size); 

void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size);
void FillFileWithFIO(std::string& filename, Student* students, int32_t size);

void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size);

void FindAverageMark(Student* students, int32_t size);
void FillBinFileAverageMark(std::fstream& bin_file, Student* students, int32_t size);

int32_t FindCountOfSillyStudents(Student* silly_studs, Student* student, int32_t size);
void FillSillyStudents(Student* student, Student* silly_studs, int32_t size);
void FillBinFileSillyStuds(std::fstream& bin_file, Student* students, int32_t size);

int32_t FindGroup(Student student);

std::string FindSurname(Student student);

int CompareUpStud(const void* el1, const void* el2);
void QsortArrayUpStud(Student* array, int32_t size);

void EnterGroup(int32_t& choice_group);
int CompareUpStudByAlphabet(const void* el1, const void* el2);
void QsortArrayUpStudByAlphabet(Student* array, int32_t size);
void FillBinStatementsOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group);


int32_t FindAverage(Student student);
int CompareDownAvg(const void* el1, const void* el2);
void QsortArrayDownAvg(Student* array, int32_t size);
void FillBinStatementsAvgOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group);


int32_t FindCountOfGoodStudents(Student* good_studs, Student* student, int32_t size);
void FillGoodStudents(Student* student, Student* good_studs, int32_t size);
void FillBinFileGoodStuds(std::fstream& bin_file, Student* students, int32_t size);


//4
void FillTxtFileFromBin(std::fstream& bin_file, std::ofstream& file);

#endif