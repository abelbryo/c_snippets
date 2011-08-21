#include <stdio.h>

int day_of_year(int,int,int);
int isleap(int);
void month_day(int, int, int*, int*);



static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
	{0, 31, 29, 31, 30, 31, 31, 31, 31, 30, 31, 30, 31}
};

int main (int argc, char const *argv[])
{
	char planets[][8] = {"Mecury","Venus","Earth","Mars","Jupiter"};
	int i;
	
	
	for(i = 0; i < 5; i++){
		printf("%s\n", planets[i]);
	}
	
	printf("%d\n",day_of_year(1985,3,24));
	
	return 0;
}

int day_of_year(int year, int month, int day){
	int i, leap;
	leap = isleap(year);
	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth,  int *pday){
	int i, leap;
	leap = isleap(year);
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int isleap(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}