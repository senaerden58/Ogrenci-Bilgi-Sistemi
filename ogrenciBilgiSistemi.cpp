/**************************************************************************************************
**                                   SAKARYA UNIVERSITESI
**                           BILGISAYAR VE BÝLÝSÝM BÝLÝMLER FAKULTESÝ
**                               BILGISAYAR MUHENDISLIGI BOLUMU
**                                 PROGRAMLAMAYA GIRIS DERSI
**
**                                        ODEV:1
**                                 OGRENCI ADI:SENA ERDEN
**                               OGRENI NUMARASI:B211210041
**                                    OGRENCI GRUBU :C
****************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>

using namespace std;

struct date       
//tarih icin bir struct olusturdum.Fakat ogrenciler icin dogum gunu kullanýlsýn demedigi icin onu kullamadim.
{
	int day;
	int month;
	int year;
};

struct student {
	// ogrenci ana struct yapimi istenene gore duzenledim. 
	string name;
	string surname;
	int number;
	float exam1;
	float exam2;
	float homework1;
	float homework2;
	float project;
	float midtermExam;
	float final;
	double successGrade;
	struct date;
};

struct studentNameSurname {                                  
//ad soyad struct yapimi olusturdum.
	string randomNameSurname[2][100];
};

struct randomNumbers {                                           
//notlarý atamak icin struct yapisi olusturdum.
	int arrayLenght;
	int randomNumberArray[100];
};


//sabit ad soyad dizisi olusturdum.
const string name[30] = { "Kursat","Sena","Ebrar","Elif","Ceren","Dilara","Ezgi","Ece","Hayal","Kerem","Murat","Eren","Azra","Nehir","Yusuf","Zeynep",
	"Kaan","Alper","Furkan","Veysel","Emre","Yagmur","Fatma","Merve","Aras","Muhammet","Arda","Hasan","Umut","Deniz" };

const string surname[30] = { "Apaydin","Yilmaz","Erden","Ates","Kaya","Demir","Celik","Sahin","Yildirim","Aslan","Kara","Koc","Kurt","Korkmaz","Ozturk","Ozdemir","Kilic",
		"Dogan","Cetin","Aydin","Yildiz","Oz","Acar","Avci","Bolat","Acar","Guler","Kaplan","Yuksel","Aksoy" };


//fonksiyonlarý buraya yazdým.
//student students[100];
const int i = 20;
student read();
void Print(student student);
double Success_calculate(student student);
void ClassList(string);
float Letter_grade(float);
float Note_control(float);
void PrintClassList(student* students);
studentNameSurname getRandomNames();
randomNumbers getRandomNumbersFinal();
randomNumbers getRandomNumbersMidtermExam();
randomNumbers getRandomNumbersProject();
randomNumbers getRandomNumbersExam1();
randomNumbers getRandomNumbersExam2();
randomNumbers getRandomNumbersHomework1();
randomNumbers getRandomNumbersHomework2();
void getMinNote(student* students);
void getMaxNote(student* students);
void getAverageNote(student* students);
void getNoteLowerThen80(student* students);
void getNotesLessThan70(student* students);
void getNotesGreaterThan70(student* students);
float calculateSD(student* students);
int getMinNote1(student stdnt);
int getMaxNote1(student stdnt);
int getAverageNote1(student stdnt);
string CLasslist1(student stdnt);

int main()
{
	setlocale(LC_ALL, "turkish");
	int stdntCount = 0;
	student  stdnt;
	int choice;
	char ch = 'a';
	do
	{
		
		student* studentArray = nullptr;                        
		//pointerlerý kullanarak ogrenci dizime atadým
		int count = 100;
		studentArray = new student[count];

		studentNameSurname resultsstudentNameSurnames = getRandomNames();
		randomNumbers resultsexam1 = getRandomNumbersExam1();
		randomNumbers resultsexam2 = getRandomNumbersExam2();
		randomNumbers resultshomework1 = getRandomNumbersHomework1();
		randomNumbers resultshomework2 = getRandomNumbersHomework2();
		randomNumbers resultsproject = getRandomNumbersProject();
		randomNumbers resultsmidtermExam = getRandomNumbersMidtermExam();
		randomNumbers resultsfinal = getRandomNumbersFinal();

		for (int k = 0; k < 100; k++)
		{
			studentArray[k].name = resultsstudentNameSurnames.randomNameSurname[0][k];
			studentArray[k].surname = resultsstudentNameSurnames.randomNameSurname[1][k];
			studentArray[k].exam1 = resultsexam1.randomNumberArray[k];
			studentArray[k].exam2 = resultsexam2.randomNumberArray[k];
			studentArray[k].homework1 = resultshomework1.randomNumberArray[k];
			studentArray[k].homework2 = resultshomework2.randomNumberArray[k];
			studentArray[k].project = resultsproject.randomNumberArray[k];
			studentArray[k].midtermExam = resultsmidtermExam.randomNumberArray[k];
			studentArray[k].final = resultsfinal.randomNumberArray[k];

			studentArray[k].successGrade = (studentArray[k].midtermExam * 0.5
				+ studentArray[k].exam2 * 0.07
				+ studentArray[k].exam1 * 0.07
				+ studentArray[k].homework1 * 0.1
				+ studentArray[k].homework2 * 0.1
				+ studentArray[k].project * 0.16) * 0.55 + studentArray[k].final * 0.45;

		}

		cout << "--------------MAIN MENU--------------";
		cout << "What do you want to do?" << endl;                     //kullanýcýya secenekler sundum.
		cout << "1-Students are determined randomly." << endl;
		cout << "2-Student information will be entered by the user." << endl;
		cin >> choice;
		//menu secenegi sundum.

		if (choice == 1)
		{
			//1e basarsa random þekilde tanýmladým ve random notlar ve isimlerle iþlemler yapmasýný saðladým.
			string menu;                                           
			int menu_choice;
			char ch3 = 'n';
			cout << "Name Surname" << setw(15) << left << " Exam 1 : " << setw(15) << left << "Exam2: " << setw(15) << left << "Homework1:" << setw(15) << left << "Homework2" << setw(15) << left << "Project:" << setw(15) << left << "Midterm exam : " << setw(15) << left << "Final:" << setw(15) << left << "Success Grade";

			for (int i = 0; i < 100; i++)
			{
				cout << endl;
				cout << studentArray[i].name << " " << setw(15) << left << studentArray[i].surname << setw(15) << left << studentArray[i].exam1 << setw(15) << left << studentArray[i].exam2 << setw(15) << left <<
					studentArray[i].homework1 << setw(15) << left << studentArray[i].homework2 << setw(15) << left << studentArray[i].project << setw(15) << left << studentArray[i].midtermExam <<
					setw(15) << left << studentArray[i].final << setw(15) << left << studentArray[i].successGrade << endl;
			}

			do
			{
            //random atanmýþ notlar ve isimlerle iþlem yapýlmasý için menü
				do
				{
					cout << "-----MENU-----" << endl;
					cout << "Please make a selection." << endl;
					cout << "1-Write the class list." << endl;
					cout << "2-Show Max Note." << endl;
					cout << "3-Show Min Note" << endl;
					cout << "4-Average note." << endl;
					cout << "5-Notes greater than 50 or less than 80 notes." << endl;
					cout << "6-Notes Less Than 70" << endl;
					cout << "7-Notes greater than 70" << endl;
					cout << "8-standard deviation calculation" << endl;

					cin >> menu_choice;
					//menü seçimi
				} while (menu_choice < 0 && menu_choice>8);
				if (menu_choice == 1)
				{
					cout << "Class List:" << endl;                //sýnýf listesi yirmiþer yazdýrýlýr.
					PrintClassList(studentArray);

				}
				else if (menu_choice == 2)                        //sinavlar yazdirilir ve fonksýyon sayesýnde en yuksek basarý notu int tipinde yazdýrýlýr.
				{


					getMaxNote(studentArray);                    //int tipindedir ve basarý notu esas alýnýr.
					system("pause");

				}
				else if (menu_choice == 3)
				{


					getMinNote(studentArray);                    //int tipindedir ve basarý notu esas alýnýr.
					system("pause");
				}
				else if (menu_choice == 4)
				{                                                //ogrenci notlarý ataanýr ve ortalama basarý notu bulunur.


					getAverageNote(studentArray);                 //int tipindedir ve basarý notu esas alýnýr.
					system("pause");


				}

				else if (menu_choice == 5)
				{

					getNoteLowerThen80(studentArray);              //basari notu 80-50 arasý olan isimler yazilir.
					system("pause");
				}

				else if (menu_choice == 6)
				{

					getNotesLessThan70(studentArray);               //basari notu 70ten asagý olan notlar yazýlýr
					system("pause");
				}
				else if (menu_choice == 7)
				{

					getNotesGreaterThan70(studentArray);           //basari notu 70 ten cok olan ýsýmler yazýlýr.
					system("pause");
				}
				else if (menu_choice == 8)
				{


					cout << endl << "Standard Deviation = " << calculateSD(studentArray) << endl;

				}
				cout << "Do you want to continue?";
				cin >> ch3;
			} while (!(ch3 == 'n' || ch3 == 'N'));
		}

		else if (choice == 2)            //kullancinin istedigi kadar ogrenci girilebilecek.
		{
			int choices;
			student s1 = read();
			Print(s1);
			Success_calculate(s1);
			//seçenek 2 için farklý bir menü sundum.
			cout << "----MENU----" << endl;
			cout << "1-Find min notes." << endl;
			cout << "2-Find max notes." << endl;
			cout << "3-Find average note." << endl;
			cin >> choices;
			if (choices == 1)
			{
				getMinNote1(s1);
			}
			else if (choices == 2)
			{
				getMaxNote1(s1);
			}
			else if (choices == 3)
			{
				getAverageNote1(s1);
			}
			else if (choices == 4)
			{
				CLasslist1(s1);
			}

		}

		else
		{                                                            //belirrli araliklarda deger girilmesi icin kullnýcý uyarýlýr.
			cout << "Enter numbers in certain value ranges...";
		}


		cout << "Do you want to continue?" << endl;
		cout << "y-yes" << endl;
		cout << "n-no";
		cin >> ch;                                           //devam etmek isterse bastaký secenekler sunulur.            


	} while (ch != 'h' && ch != 'H');

	system("CLS");
	system("PAUSE");
}

studentNameSurname getRandomNames() {

	studentNameSurname stdntNameSurnames;

	srand(time(NULL));

	for (int i = 0; i < 2; i++)                                            //matrislerden yararlanarak ad soyad secme
	{
		//satiri dönduruyor.
		for (int j = 0; j < 100; j++)
		{
			//sutunlarý dönduruyor.
			if (i == 0) {
				//isim kismi.
				int randNameIndex = rand() % 30;                           //olusan sabit isim dizisinden 30 tane seciyor

				stdntNameSurnames.randomNameSurname[i][j] = name[randNameIndex];
			}
			if (i == 1) {
				//soyad kismi burasi.
				int randSurnameIndex = rand() % 30;                         //olusan  sabit soyisim dizisinden 30 tane seciyor.

				stdntNameSurnames.randomNameSurname[i][j] = surname[randSurnameIndex];
			}
		}
	}
	return stdntNameSurnames;
}

randomNumbers getRandomNumbersExam1() {               //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int i = 0;i < sizeof(student);i++)
	{
		for (int i = 0;i < 10;i++)
		{
			rndNumbers.randomNumberArray[i] = rand() % 41;

		}
		for (int i = 10;i < 60;i++)
		{
			rndNumbers.randomNumberArray[i] = rand() % 30 + 41;
		}
		for (int i = 60;i < 75;i++)
		{
			rndNumbers.randomNumberArray[i] = rand() % 11 + 70;
		}
		for (int i = 75;i < 100;i++)
		{
			rndNumbers.randomNumberArray[i] = rand() % 21 + 80;
		}

	}
	return rndNumbers;                                              //fonksiyonu döndürdüm.
}
randomNumbers getRandomNumbersExam2() {                 //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int j = 0;j < sizeof(student);j++)
	{
		for (int j = 0;j < 10;j++)
		{
			rndNumbers.randomNumberArray[j] = rand() % 21 + 80;
		}
		for (int j = 10;j < 60;j++)
		{
			rndNumbers.randomNumberArray[j] = rand() % 41;
		}
		for (int j = 60;j < 75;j++)
		{
			rndNumbers.randomNumberArray[j] = rand() % 11 + 70;
		}
		for (int j = 75;j < 100;j++)
		{
			rndNumbers.randomNumberArray[j] = rand() % 30 + 41;

		}

	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}
randomNumbers getRandomNumbersHomework1() {                     //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int k = 0;k < sizeof(student);k++)
	{
		for (int k = 0;k < 10;k++)
		{
			rndNumbers.randomNumberArray[k] = rand() % 40 + 41;

		}
		for (int k = 10;k < 60;k++)
		{
			rndNumbers.randomNumberArray[k] = rand() % 21 + 80;


		}
		for (int k = 60;k < 75;k++)
		{
			rndNumbers.randomNumberArray[k] = rand() % 41;
		}
		for (int k = 75;k < 100;k++)
		{

			rndNumbers.randomNumberArray[k] = rand() % 11 + 70;


		}

	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}
randomNumbers getRandomNumbersHomework2() {                           //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int l = 0;l < sizeof(student);l++)
	{
		for (int l = 0;l < 10;l++)
		{
			rndNumbers.randomNumberArray[l] = rand() % 11 + 70;

		}
		for (int l = 10;l < 60;l++)
		{
			rndNumbers.randomNumberArray[l] = rand() % 40 + 41;

		}
		for (int l = 60;l < 75;l++)
		{
			rndNumbers.randomNumberArray[l] = rand() % 21 + 80;


		}
		for (int l = 75;l < 100;l++)
		{
			rndNumbers.randomNumberArray[l] = rand() % 41;
		}

	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}
randomNumbers getRandomNumbersProject() {                          //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int m = 0;m < sizeof(student);m++)
	{
		for (int m = 0;m < 10;m++)
		{
			rndNumbers.randomNumberArray[m] = rand() % 41;

		}
		for (int m = 10;m < 60;m++)
		{

			rndNumbers.randomNumberArray[m] = rand() % 11 + 70;

		}
		for (int m = 60;m < 75;m++)
		{
			rndNumbers.randomNumberArray[m] = rand() % 40 + 41;
		}

	}
	for (int m = 75;m < 100;m++)
	{
		rndNumbers.randomNumberArray[m] = rand() % 21 + 80;


	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}
randomNumbers getRandomNumbersMidtermExam() {                    //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int b = 0;b < sizeof(student);b++)
	{
		for (int i = 0;i < 10;i++)
		{
			rndNumbers.randomNumberArray[i] = rand() % 21 + 80;


		}
		for (int i = 10;i < 60;i++)
		{

			rndNumbers.randomNumberArray[i] = rand() % 41;

		}
		for (int i = 60;i < 75;i++)
		{

			rndNumbers.randomNumberArray[i] = rand() % 11 + 70;
		}
		for (int i = 75;i < 100;i++)
		{

			rndNumbers.randomNumberArray[i] = rand() % 40 + 41;
		}

	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}
randomNumbers getRandomNumbersFinal() {                            //sýnavlarý random atadým.

	randomNumbers rndNumbers = { 0, {0} };                //kumeyi kabul etmedigi icin default karakter girdim.
	srand(time(0));
	for (int c = 0;c < sizeof(student);c++)
	{
		for (int c = 0;c < 10;c++)
		{
			rndNumbers.randomNumberArray[c] = rand() % 41;

		}
		for (int c = 10;c < 60;c++)
		{

			rndNumbers.randomNumberArray[c] = rand() % 21 + 80;

		}
		for (int c = 60;c < 75;c++)
		{
			rndNumbers.randomNumberArray[c] = rand() % 40 + 41;

		}
		for (int c = 75;c < 100;c++)
		{
			rndNumbers.randomNumberArray[c] = rand() % 11 + 70;


		}

	}
	return rndNumbers;                                              //fonksiyonu dondurdum.
}

void getMinNote(student* students)
{
	int resultIndex;
	int lowestValue = 100;                  //en kucugu basta en buyuk sectým ký diger her gelen dizi elemaný en kucuk sayý dýye atanabýlsýn.
	for (int i = 0;i < sizeof(students); i++)
	{
		if (students[i].successGrade < lowestValue) {
			lowestValue = students[i].successGrade;                    //bu islem basarý notu ýcýn gecerlidir.
			resultIndex = i;
		}
	}
	cout << " Min note : " << lowestValue << endl;
}

void getMaxNote(student* students) {

	int highValue = 0;                          //en buyugu alýnabýlecek en kucuk sayý sectým.
	int resultIndex;

	for (int i = 1; i <= sizeof(student); i++) {

		if (students[i].successGrade > highValue) {
			highValue = students[i].successGrade;                      //bu islem basarý notu ýcýn gecerlidir.
			resultIndex = i;
		}
	}
	cout << " MAX SUCCESS GRADE: " << highValue << endl;
}

void getAverageNote(student* students)
{

	int resultIndex = 0;
	int sum = 0;                      //toplamý basta 0 sectim.

	for (int i = 1; i < 100; i++) {
		sum = sum + students[i].successGrade;                                           //dizi elemanlari toplandi.

	}

	float average = sum / 100;                                                        //toplamý eleman sayisina boldum.
	cout << "Average note : " << average << endl;

}

void getNoteLowerThen80(student* students)
{
	cout << "Notes greater than 50 or less than 80 notes " << endl;

	for (int i = 1; i < sizeof(student); i++) {

		if (students[i].successGrade >= 50 && students[i].successGrade < 80) {                             //basari notlarini if ile sectim.
			cout << "FINDEND NOTE : " << students[i].name << "   " << students[i].surname << endl;                //araliga uyan notlari alan kisilerin ismini yazdirdim.
		}
	}
}

void getNotesLessThan70(student* students)
{
	cout << "Notes Less Than 70" << endl;
	for (int i = 0;i < sizeof(student); i++)                                    //ogrenci sayisi kadar dondurdum.
	{
		if (students[i].successGrade < 70)                                   //araliga uyan notlari if le sectim.
		{
			cout << "FINDED NOTE:" << students[i].name << "   " << students[i].successGrade << endl;    //notu olan kisileri yazdiridm.
		}
	}

}

void getNotesGreaterThan70(student* students)
{
	cout << "Notes greater than 70";
	for (int i = 0;i < sizeof(student);i++)                       //ogrenci sayisi kadar dondurdum.
	{
		if (students[i].successGrade > 70)                      //araliga uyan notlari if le sectim.
		{
			cout << "FINDED NOTE:" << students[i].name << "  " << students[i].surname << endl;       //notu olan kisileri yazdiridm.
		}
	}
}

student read()
{
	cout << "PLEASE ENTER STUDENT COUNT.";
	student stdnt;
	int index = 0;
	int k;
	cin >> k;
	for (int i = 0;i < k;i++)
	{
		
		cout << "--------Enter student information.--------" << endl;              //istenen ogrenci bilgileri kullanici tarafindan giriliyor.
		cout << "name:";                                                              // ayni zamanda harf notu bilgisayar tarafindan veriliyor ve not kontrol ediliyor.
		cin >> stdnt.name;
		cout << "surname:";
		cin >> stdnt.surname;

		cout << "Exam1:";
		cin >> stdnt.exam1;
		Letter_grade(Note_control(stdnt.exam1));
		cout << endl;

		cout << "Exam2:";
		cin >> stdnt.exam2;
		Letter_grade(Note_control(stdnt.exam2));
		cout << endl;

		cout << "Homework1:";
		cin >> stdnt.homework1;
		Letter_grade(Note_control(stdnt.homework1));
		cout << endl;

		cout << "Homework2:";
		cin >> stdnt.homework2;
		Letter_grade(Note_control(stdnt.homework2));
		cout << endl;

		cout << "Project:";
		cin >> stdnt.project;
		Letter_grade(Note_control(stdnt.project));
		cout << endl;

		cout << "midtermExam:";
		cin >> stdnt.midtermExam;
		Letter_grade(Note_control(stdnt.midtermExam));
		cout << endl;

		cout << "Final:";
		cin >> stdnt.final;
		Letter_grade(Note_control(stdnt.final));
		cout << endl;
	}
	return stdnt;

}

void Print(student stdnt)                                              //oku kisminda yazilan bilgiler yazdiriliyor.
{
	cout << "Student Printed..." << endl;
	cout << "Name:" << stdnt.name << endl;
	cout << "Surname:" << stdnt.surname << endl;
	cout << "Exam1:" << Note_control(stdnt.exam1) << endl;
	cout << "Exam2:" << Note_control(stdnt.exam2) << endl;
	cout << "Homework1:" << Note_control(stdnt.homework1) << endl;
	cout << "Homework2:" << Note_control(stdnt.homework2) << endl;
	cout << "Project:" << Note_control(stdnt.project) << endl;
	cout << "MidtermExam:" << Note_control(stdnt.midtermExam) << endl;
	cout << "Final:" << Note_control(stdnt.exam1) << endl;
}

double Success_calculate(student stdnt)            //yýl sonu basarý notu istenen degerlere gore hesaplanýr.
{
	double in_year = stdnt.midtermExam * 0.5 + stdnt.exam1 * 0.07 + stdnt.exam2 * 0.07 + stdnt.homework1 * 0.1 + stdnt.exam2 * 0.1 + stdnt.project * 0.16;
	double successGrade = in_year * 0.55 + stdnt.final * 0.45;

	cout << "Average:" << successGrade << endl;

	return successGrade;
}

float Note_control(float num)                        //sayýnýn 0-100 aralýgýnda olup olmadýgýný kontrol eden fonksýyon
{
	if (num < 0 && num>100)
	{
		//sayi 0-100 arasýnda degilse  uyarýr.
		cout << "Enter numbers between 0-100.";
		cin >> num;
	}

	return num;
}

float Letter_grade(float successGrade)                   //girilen nota gore harf notu veren fonksiyon
{                                                               //notun araligina gore if 'e girer.
	if (100 >= successGrade && successGrade >= 80)
	{
		cout << "AA";
	}
	else if (80 > successGrade && successGrade >= 70)
	{
		cout << "BB";
	}
	else if (70 > successGrade && successGrade >= 50)
	{
		cout << "CC";
	}
	else if (50 > successGrade && successGrade >= 40)
	{
		cout << "DD";
	}
	else if (40 > successGrade && successGrade >= 30)
	{
		cout << "EE";
	}
	else if (30 > successGrade && 0 <= successGrade)
	{
		cout << "FF";
	}
	else
	{
		cout << "beliri araliklarda sayi giriniz.";
		Note_control(successGrade);
	}
	return successGrade;

}

int getMinNote1(student stdnt)
{
	 int successGrade[100];                                           //baþarý notu dizisi tanýmladým.
	    int studentCount;
		int temp;                                                            // Geçiçi deðiþken.
		cout << "Please enter student counts. ";
		cin >> studentCount;
		
		cout << endl << "Enter exam1 notes: " << endl;
		for (int i = 0; i <studentCount; i++) {
			cout << i + 1 << ". sayýyý giriniz: ";
			cin >> successGrade[i];
		}
		for (int i = 0; i < studentCount; i++) {
			for (int j = i; j < studentCount; j++) {
				
				if (successGrade[i] < successGrade[j]) {
					temp = successGrade[i];
					successGrade[i] = successGrade[j];
					successGrade[j] = temp;
				}
			}
		}
		cout << endl;
		cout <<studentCount << "Big to small: ";                     //büyükten küçüðe yadýrdým.
		for (int i = 0; i < studentCount; i++) {
			cout << successGrade[i] << " ";
		}
		cout << endl;

		system("PAUSE");
		return 0;
}

int getMaxNote1(student stdnt)
{
	    int successGrade[100];              //basarý notu dizisi tanýmladým.
	    int studentCount;
		int temp;                                                            // Geçiçi deðiþken.
		cout << "Please enter student counts. ";
		cin >> studentCount;
		
		cout << endl << "Enter exam1 notes: " << endl;
		for (int i = 0; i <studentCount; i++) {
			cout << i + 1 << ". sayýyý giriniz: ";
			cin >> successGrade[i];
		}
		for (int i = 0; i < studentCount; i++) {
			for (int j = i; j < studentCount; j++) {
				
				if (successGrade[i] > successGrade[j]) {
					temp = successGrade[i];
					successGrade[i] = successGrade[j];
					successGrade[j] = temp;
				}
			}
		}
		cout << endl;
		cout <<studentCount << " Sorting from smallest to largest: ";
		for (int i = 0; i < studentCount; i++) {
			cout << successGrade[i] << " ";
		}
		cout << endl;

		system("PAUSE");
		return 0;
	}

int getAverageNote1(student stdnt)
{
	int successGrade[100];
	int studentCount;   
	int sum = 0;
	int average;
	cout << "Please enter student counts. ";
	cin >> studentCount;

	cout << endl << "Enter exam1 notes: " << endl;
	for (int i = 0; i < studentCount; i++) {
		cout << i + 1 << ".number: ";
		cin >> successGrade[i];
	}
	for (int i = 0; i < studentCount; i++) 
	{
		sum = sum + successGrade[i];
	}
	average = sum / studentCount;
	cout << endl;
	cout << average;                                      //dizi elemanlarýný toplayýp dizi eleman sayýsýna bölerek ortalamayý buldum.
	cout << endl;

	system("PAUSE");
	return 0;
	

}

string  CLasslist1(student stdnt)
{
	string classListt;
	cout << "please enter student counts again correctly.";
	int studentCount;
	cin >> studentCount;
	for (int i = 0;i < studentCount;i++)
	{
		classListt = stdnt.name +"  "+ stdnt.surname;
		cout <<"Class list."<< classListt << endl;
	}
	return classListt;
}

void ClassList(string liste)            //yirmiþer yazdýrýlan sýnýf listesi
{
	string name[30] = { "Kursat","Sena","Ebrar","Elif","Ceren","Dilara","Ezgi","Ece","Hayal","Kerem","Murat","Eren","Azra","Nehir","Yusuf","Zeynep",
	"Kaan","Alper","Furkan","Veysel","Emre","Yagmur","Fatma","Merve","Aras","Muhammet","Arda","Hasan","Umut","Deniz" };

	string surname[30] = { "Apaydin","Yilmaz","Erden","Ates","Kaya","Demir","Celik","Sahin","Yildirim","Aslan","Kara","Koc","Kurt","Korkmaz","Ozturk","Ozdemir","Kilic",
			"Dogan","Cetin","Aydin","Yildiz","Oz","Acar","Avci","Bolat","Acar","Guler","Kaplan","Yuksel","Aksoy" };


	int studentCount[20];
	int i = 0;

	srand(time(NULL));

	while (i < 5)
	{
		cout << setw(8) << left << "student" << setw(8) << left << "name" << setw(5) << "surname" << endl;
		for (int i = 0;i < 20;i++)
		{
			for (int j = 0;j < 20;j++)
			{
				studentCount[i] = rand() % 30;
				studentCount[j] = rand() % 30;
				cout << i + 1 << "-" << setw(10) << left << name[studentCount[i]] << setw(10) << left << surname[studentCount[j]] << endl;
				if (j % 20 == 0)
				{
					break;
				}

			}

		}
		i++;
		system("pause");
		system("cls");
	}


	system("pause");
}

float calculateSD(student* students)                                          //standart sapma hesap fonksiyonu
{                                                                              //standart sapma formulunu fonksiyoa uygulattým.
	float sum = 0.0, mean, standardDeviation = 0.0;

	int i;

	for (i = 0; i < 100; ++i)
	{
		sum += students[i].successGrade; //basarý notlarý toplanýyor.
	}

	mean = sum / 100;       //kisi sayisia bolonur.

	for (i = 0; i < sizeof(student); ++i)
		standardDeviation += pow(students[i].successGrade - mean, 2);                         //ortalamadan herbir basari degeri cýkartýlýyor ve bunun karesi alýnýyor.

	return sqrt(standardDeviation / 100);                                //tekrar bolunerek karekoku alýnýyor.
}

void PrintClassList(student* students)                   //yirmiþer yazdýrma
{
	int counter1 = 0;

	for (int i = 0;i < 20;i++)                                                //20 tane ogrenci atanýyor sonra tusa basýlýnca tekrar 20 ogrenci gosterýlýyor.toplam 100 ogrenci
	{
		for (int j = 0;j < 20;j++)
		{
			cout << students[i].name << "  " << students[i].surname << endl;
			if (j % 20 == 0)
			{
				break;                   //donguyu durduruyor.
			}
		}

	}
	system("pause");                    //ekraný sabitliyor.
	system("cls");                        //tuþa basýlýnca devam etmesi saglanýyor.
	for (int i = 20;i < 40;i++)
	{
		for (int j = 20;j < 40;j++)
		{
			cout << students[i].name << "  " << students[i].surname << endl;
			if (j % 20 == 0)
			{
				break;
			}
		}

	}
	system("pause");
	system("cls");
	for (int i = 40;i < 60;i++)
	{
		for (int j = 40;j < 60;j++)
		{
			cout << students[i].name << "  " << students[i].surname << endl;
			if (j % 20 == 0)
			{
				break;
			}
		}

	}
	system("pause");
	system("cls");
	for (int i = 60;i < 80;i++)
	{
		for (int j = 60;j < 80;j++)
		{
			cout << students[i].name << "  " << students[i].surname << endl;
			if (j % 20 == 0)
			{
				break;
			}
		}

	}
	system("pause");
	system("cls");
	for (int i = 80;i < 100;i++)
	{
		for (int j = 80;j < 100;j++)
		{
			cout << students[i].name << "  " << students[i].surname << endl;
			if (j % 20 == 0)
			{
				break;
			}
		}

	}
}