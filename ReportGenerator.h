#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

namespace ReportGenerator {


	class employee {

		std::string _full_name;
		size_t _year;
		size_t _month;
		size_t _hours_total;

	public:

		employee() = default;
		employee(std::string full_name, size_t year, size_t month, size_t hours_total);
		void SetName(std::string name) { _full_name = name; }
		void SetYear(size_t year) { _year = year; }
		void SetMonth(size_t month) { _month = month; }
		void SetTotalHours(size_t hours_total) { _hours_total = hours_total; }
		std::string GetName() { return _full_name; }
		size_t GetYear() { return _year; }
		size_t GetMonth() { return _month; }
		size_t GetTotalHours() { return _hours_total; }
		void operator+=(size_t val);
		void operator-=(size_t val);
		friend std::ostream& operator<<(std::ostream& os, const employee& rhv); 
		friend std::istream& operator>>(std::istream& is, employee& rhv); 		

	};


	const std::string month_to_string(size_t month);

	void read_parse_write(const std::string file_name, size_t year_required, size_t month_required);
	

}
