#include "header.h"

void CheckInputFile(std::istream& fin) {
	if (!fin.good()) {
		throw "file isnt exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}

int32_t FindCountOfStudents(std::istream& fin) {
	int32_t counter{};
	std::string str{};
	while (std::getline(fin, str)) {
		++counter;
	}
	return counter;
}

void FillStructArrayFromFiles(std::istream& fin_mark, std::istream& fin_stud, Student* student, int32_t size) {
	fin_stud.clear();
	fin_stud.seekg(0);

	fin_mark.clear();
	fin_mark.seekg(0);

	std::string id;
	std::string group;
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string mark_ma;
	std::string mark_geo;
	std::string mark_prog;
	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_stud, id, ';');
		std::getline(fin_stud, surname, ';');
		std::getline(fin_stud, name, ';');
		fin_stud >> patronymic;
		std::getline(fin_mark, group, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_prog, ';');
		fin_mark >> mark_prog;

		student[i].id = std::stoi(id);
		student[i].group = std::stoi(group);
		student[i].name = name;
		student[i].surname = surname;
		student[i].patronymic = patronymic;
		student[i].mark_ma = std::stoi(mark_ma);
		student[i].mark_geo = std::stoi(mark_geo);
		student[i].mark_prog = std::stoi(mark_prog);

		fin_stud.ignore();
		fin_mark.ignore();
	}
}

void FillBinaryFileFromTextFile(std::ifstream& fin_mark, std::fstream& bin_mark) {
	fin_mark.clear();
	fin_mark.seekg(0);

	std::string line;
	while (std::getline(fin_mark, line)) {
		bin_mark << line << '\n';
	}

}



void SortStructById(Student*& students, int32_t size) {
	for (int32_t i = 0; i < size - 1; ++i) {

		for (int32_t j = 0; j < size - i - 1; ++j) {
			if (students[j].id > students[j + 1].id) {
				std::swap(students[j], students[j + 1]);

			}
		}

	}
}


void FillStructFromFileWithMarks(std::ifstream& fin_mark, Student* students, int32_t size) {

	fin_mark.clear();
	fin_mark.seekg(0);
	std::string id;
	std::string group;
	std::string mark_ma;
	std::string mark_geo;
	std::string mark_prog;

	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_mark, group, ';');
		std::getline(fin_mark, id, ';');
		std::getline(fin_mark, mark_ma, ';');
		std::getline(fin_mark, mark_ma, ';');

		std::getline(fin_mark, mark_geo, ';');
		std::getline(fin_mark, mark_geo, ';');

		std::getline(fin_mark, mark_prog, ';');
		fin_mark >> mark_prog;

		students[i].group = std::stoi(group);
		students[i].id = std::stoi(id);
		students[i].mark_ma = std::stoi(mark_ma);
		students[i].mark_geo = std::stoi(mark_geo);
		students[i].mark_prog = std::stoi(mark_prog);

		fin_mark.ignore();
	}
}

void FillFileWithMark(std::string& filename, Student* students, int32_t size) {

	std::ofstream fout_mark(filename);
	for (size_t i = 0; i < size; ++i)
	{
		fout_mark << students[i].group << ';';
		fout_mark << students[i].id << ';';
		fout_mark << "MA;" << students[i].mark_ma << ';';
		fout_mark << "???;" << students[i].mark_geo << ';';
		fout_mark << "????;" << students[i].mark_prog << '\n';
	}
	fout_mark.close();
}


void FillStructFileWithFIO(std::ifstream& fin_stud, Student* students, int32_t size) {

	fin_stud.clear();
	fin_stud.seekg(0);

	std::string id;
	std::string surname;
	std::string name;
	std::string patronymic;

	for (size_t i = 0; i < size; ++i)
	{
		std::getline(fin_stud, id, ';');
		std::getline(fin_stud, surname, ';');
		std::getline(fin_stud, name, ';');
		fin_stud >> patronymic;

		students[i].id = std::stoi(id);
		students[i].surname = surname;
		students[i].name = name;
		students[i].patronymic = patronymic;

		fin_stud.ignore();
	}
}

void FillFileWithFIO(std::string& filename, Student* students, int32_t size) {
	std::ofstream fout_stud(filename);
	for (size_t i = 0; i < size; ++i)
	{
		fout_stud << students[i].id << ';';
		fout_stud << students[i].surname << ';';
		fout_stud << students[i].name << ';';
		fout_stud << students[i].patronymic ;
		fout_stud << '\n';
	}
	fout_stud.close();
}


void MakeBinaryFileWithSurnAndMarks(Student* students, int32_t size) {
	std::ofstream fout_SMBIN("SurnamesMarks.bin", std::ios::binary);
	//D:/git/Git/practIKA29.08/practicatrio/projectTRIO/projectTRIO/
	for (size_t i = 0; i < size; ++i)
	{
		fout_SMBIN << students[i].surname << ';';
		fout_SMBIN << students[i].mark_ma << ';';
		fout_SMBIN << students[i].mark_geo << ';';
		fout_SMBIN << students[i].mark_prog << ';';
		fout_SMBIN << '\n';
	}
	//fout_SMBIN.close();
}


void FindAverageMark(Student* students, int32_t size) {

	for (size_t i = 0; i < size; ++i)
	{
		students[i].avg_mark = (students[i].mark_ma + students[i].mark_geo + students[i].mark_prog) / 3;
	}
}

void FillBinFileAverageMark(std::fstream& bin_file, Student* students, int32_t size) {

	for (size_t i = 0; i < size; ++i)
	{
		bin_file << students[i].surname << ';';
		bin_file << students[i].avg_mark;
		bin_file << '\n';

	}
}

int32_t FindCountOfSillyStudents(Student* silly_studs, Student* student, int32_t size) {
	int32_t counter{};
	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].mark_geo <= 4 || student[i].mark_prog <= 4 || student[i].mark_ma <= 4) {
			++counter;
		}

	}
	return counter;
}

void FillSillyStudents(Student* student, Student* silly_studs, int32_t size) {
	int32_t k{};

	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].mark_geo <= 4 || student[i].mark_prog <= 4 || student[i].mark_ma <= 4) {
			silly_studs[k].id = student[i].id;
			silly_studs[k].group = student[i].group;
			silly_studs[k].name = student[i].name;
			silly_studs[k].surname = student[i].surname;
			silly_studs[k].patronymic = student[i].patronymic;
			silly_studs[k].mark_ma = student[i].mark_ma;
			silly_studs[k].mark_geo = student[i].mark_geo;
			silly_studs[k].mark_prog = student[i].mark_prog;
			++k;
		}

	}
}

void FillBinFileSillyStuds(std::fstream& bin_file, Student* students, int32_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		bin_file << students[i].surname << ';';
		bin_file << students[i].group << ';';
		bin_file << students[i].id;
		bin_file << '\n';
	}
}


int32_t FindGroup(Student student) {
	return student.group;
}

std::string FindSurname(Student student) {
	return student.surname;
}

int CompareUpStud(const void* el1, const void* el2) {
	if (FindGroup(*((Student*)el1)) == FindGroup(*((Student*)el2))) {

		if (FindSurname(*((Student*)el1)) > FindSurname(*((Student*)el2))) {
			return 1;
		}
		else {
			return -1;
		}

	}
	return  FindGroup(*((Student*)el1)) - FindGroup(*((Student*)el2));
}
void QsortArrayUpStud(Student* array, int32_t size) {
	std::qsort(array, size, sizeof(Student), CompareUpStud);
}

void EnterGroup(int32_t& choice_group) {
	std::cout << "enter choice of group :\n";
	std::cin >> choice_group;
}

int CompareUpStudByAlphabet(const void* el1, const void* el2) {
	if (FindSurname(*((Student*)el1)) > FindSurname(*((Student*)el2))) {
		return 1;
	}
	else {
		return -1;
	}

}
void QsortArrayUpStudByAlphabet(Student* array, int32_t size) {
	std::qsort(array, size, sizeof(Student), CompareUpStudByAlphabet);
}

void FillBinStatementsOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group) {
	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].group == choice_group) {
			bin_file << student[i].id << ';';
			bin_file << student[i].group << ';';
			bin_file << student[i].name << ';';
			bin_file << student[i].surname << ';';
			bin_file << student[i].patronymic << ';';
			bin_file << student[i].mark_ma << ';';
			bin_file << student[i].mark_geo << ';';
			bin_file << student[i].mark_prog;
			bin_file << '\n';

		}

	}
}



int32_t FindAverage(Student student) {
	return student.avg_mark;
}

int CompareDownAvg(const void* el1, const void* el2) {

	return  FindAverage(*((Student*)el2)) - FindAverage(*((Student*)el1));
}
void QsortArrayDownAvg(Student* array, int32_t size) {
	std::qsort(array, size, sizeof(Student), CompareDownAvg);
}

void FillBinStatementsAvgOfGroup(std::fstream& bin_file, Student* student, int32_t size, int32_t choice_group) {
	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].group == choice_group) {
			bin_file << student[i].id << ';';
			bin_file << student[i].group << ';';
			bin_file << student[i].name << ';';
			bin_file << student[i].surname << ';';
			bin_file << student[i].patronymic << ';';
			bin_file << student[i].avg_mark;
			bin_file << '\n';

		}

	}
}



int32_t FindCountOfGoodStudents(Student* good_studs, Student* student, int32_t size) {
	int32_t counter{};
	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].mark_geo > 4 && student[i].mark_prog > 4 && student[i].mark_ma > 4) {
			++counter;
		}

	}
	return counter;
}

void FillGoodStudents(Student* student, Student* good_studs, int32_t size) {
	int32_t k{};

	for (size_t i = 0; i < size; ++i)
	{
		if (student[i].mark_geo > 4 || student[i].mark_prog > 4 || student[i].mark_ma > 4) {
			good_studs[k].id = student[i].id;
			good_studs[k].group = student[i].group;
			good_studs[k].name = student[i].name;
			good_studs[k].surname = student[i].surname;
			good_studs[k].patronymic = student[i].patronymic;
			good_studs[k].mark_ma = student[i].mark_ma;
			good_studs[k].mark_geo = student[i].mark_geo;
			good_studs[k].mark_prog = student[i].mark_prog;
			++k;
		}

	}
}

void FillBinFileGoodStuds(std::fstream& bin_file, Student* students, int32_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		bin_file << students[i].surname << ';';
		bin_file << students[i].group << ';';
		bin_file << students[i].id;
		bin_file << '\n';
	}
}


void FillTxtFileFromBin(std::fstream& bin_file, std::ofstream& file) {
	bin_file.clear();
	bin_file.seekg(0);

	std::string str;
	while (std::getline(bin_file, str)) {
		file << str << '\n';
		std::cout << str << '\n';
	}
	std::cout << '\n';
	file.close();
}