
#include "header.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fileNameMark = "Group_ID_MA_Mark_GEO_Mark_PROG_Mark.txt";
	std::string fileNameStud = "ID_SNP.txt";


	std::ifstream fin_mark("Group_ID_MA_Mark_GEO_Mark_PROG_Mark.txt");
	std::ifstream fin_stud("ID_SNP.txt");
	std::fstream bin_mark("Bin_Group_ID_MA_Mark_GEO_Mark_PROG_Mark.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_stud("Bin_ID_SNP.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_avg_mark("Bin_Average.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_silly_stud("Bin_Silly_Std.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_silly_stud_aft("Bin_Silly_Std_After.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_statement("Bin_Statement.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_statement_avg("Bin_Statement_Avg.bin", std::ios::in | std::ios::out | std::ios::binary);
	std::fstream bin_good_stud("Bin_Good_Std.bin", std::ios::in | std::ios::out | std::ios::binary);
	try {
		CheckInputFile(fin_mark);
		CheckInputFile(fin_stud);

		int32_t size = FindCountOfStudents(fin_mark);
		Student* students = new Student[size];
		Student* silly_studs = new Student[size];
		Student* good_studs = new Student[size];

				//a
		FillBinaryFileFromTextFile(fin_mark, bin_mark);
		FillBinaryFileFromTextFile(fin_stud, bin_stud);


		FillStructFromFileWithMarks(fin_mark, students, size);
		SortStructById(students, size);
		FillFileWithMark(fileNameMark, students, size);

		FillStructFileWithFIO(fin_stud, students, size);
		SortStructById(students, size);
		FillFileWithFIO(fileNameStud, students, size);

		FillStructArrayFromFiles(fin_mark, fin_stud, students, size);

				//b
		MakeBinaryFileWithSurnAndMarks(students, size);
				//c
		FindAverageMark(students, size);
		FillBinFileAverageMark(bin_avg_mark, students, size);
				//d
		int32_t size_sill{ FindCountOfSillyStudents(silly_studs,students,size) };

		FillSillyStudents(students, silly_studs, size);
		FillBinFileSillyStuds(bin_silly_stud, silly_studs, size_sill);

				//e
		QsortArrayUpStud(silly_studs, size_sill);

				//f
		FillBinFileSillyStuds(bin_silly_stud_aft, silly_studs, size_sill);

				//g

		int32_t choice_group{};
		EnterGroup(choice_group);
		if (choice_group <= 0 || choice_group >= 7) {
			throw "dont know this choice";
		}
		QsortArrayUpStudByAlphabet(students, size);
		FillBinStatementsOfGroup(bin_statement, students, size, choice_group);

				//h
		QsortArrayDownAvg(students, size);
		FillBinStatementsAvgOfGroup(bin_statement_avg, students, size, choice_group);
				//i
		int32_t size_good{ FindCountOfGoodStudents(good_studs,students,size) };

		FillGoodStudents(students, good_studs, size);
		FillBinFileGoodStuds(bin_good_stud, good_studs, size_good);

				//
		std::ofstream foutAverg("Avarage.txt");
		FillTxtFileFromBin(bin_avg_mark, foutAverg);

		std::ofstream foutSilly("SillyStudents.txt");
		FillTxtFileFromBin(bin_silly_stud, foutSilly);

		std::ofstream foutSillyAft("SillyStudentsAft.txt");
		FillTxtFileFromBin(bin_silly_stud_aft, foutSillyAft);

		std::ofstream foutStatm("Statment.txt");
		FillTxtFileFromBin(bin_statement, foutStatm);

		std::ofstream foutStatmAvr("StatmentAvr.txt");
		FillTxtFileFromBin(bin_statement_avg, foutStatmAvr);

		std::ofstream foutGoodSt("GoodStudents.txt");
		FillTxtFileFromBin(bin_good_stud, foutGoodSt);
	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}