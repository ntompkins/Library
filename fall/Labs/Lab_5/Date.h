#ifndef DATE_H
#define DATE_H

class Date {
    private:
		int year, month, day;
	public:
		Date();
		Date(int,int,int);
		
		int getYear();
		int getMonth();
		int getDay();
		
		void setYear (int);
		void setMonth(int);
		void setDay  (int);
		void setDate (int,int,int);
		void setDefaultDate();
		
		bool isValidYear (int);
		bool isValidMonth(int);
		bool isValidDay	 (int);
		bool isValidDate (int,int,int);
		bool isLeapYear(int);
		
		int daysInMonth(int);
		
		void display();
		enum DateFormat { SHORT_FORM, LONG_FORM };
		std::string toString(DateFormat df);
};

#endif