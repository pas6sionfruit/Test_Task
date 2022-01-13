#include "ReportGenerator.h"

namespace ReportGenerator {


    ReportGenerator::employee::employee(std::string full_name, size_t year, size_t month, size_t hours_total)
        : _full_name(full_name), _year(year), _month(month), _hours_total(hours_total) {}



    void ReportGenerator::employee::operator+=(size_t val) {

        _hours_total += val;

    }

    void ReportGenerator::employee::operator-=(size_t val) {

        _hours_total -= val;

    }

    std::ostream& ReportGenerator::operator<<(std::ostream& os, const employee& rhv) {

        os << rhv._full_name << ";" << rhv._year << ";" << month_to_string(rhv._month) << ";" << rhv._hours_total;

        return os;
    }

    std::istream& ReportGenerator::operator>>(std::istream& is, employee& rhv) {

        std::string buf;
        std::getline(is, buf);
        is >> buf;

        std::istringstream ss(buf);

        std::string set;
        std::getline(ss, set, ';');

        if (set.empty()) {

            return is;
        }
        rhv.SetName(set);

        std::getline(ss, set, ';');
        rhv.SetYear(std::stoll(set));

        std::getline(ss, set, ';');
        rhv.SetMonth(std::stoll(set));

        std::getline(ss, set, ';');
        rhv.SetTotalHours(std::stoll(set));

        return is;
    }


    const std::string month_to_string(size_t month) {

        switch (month)
        {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        }

    }

    void read_parse_write(const std::string file_name, size_t year_required, size_t month_required) {

        std::string str;

        std::map<std::string, employee> map;

        std::fstream fsr(file_name, std::ios::in);

        if (fsr.is_open()) {

            while (!fsr.eof()) {

                getline(fsr, str);


                const size_t year = std::stoull(str.substr(str.find_last_of('-') - 7, 4));
                const size_t month = std::stoull(str.substr(str.find_last_of('-') - 2, 2));
                const std::string name = str.substr(0, str.find(';'));

                if (year == year_required && month == month_required) {


                    if (map.find(name) == map.end()) {

                        employee empl(name, year,
                            month, std::stoull(str.substr(str.find_last_of(';') + 1)));

                        map[name] = empl;
                    }
                    else {

                        map[name] += std::stoull(str.substr(str.find_last_of(';') + 1));

                    }

                }
            }
            fsr.close();
        }

        std::stringstream ss;
        ss << year_required;

        std::string file_name_out = "Report " + month_to_string(month_required) + " " + ss.str() + ".txt";

        std::fstream fsw(file_name_out, std::ios::out);

        if (fsw.is_open()) {

            for (const auto& i : map) {

                fsw << i.second << "\n";

            }

            fsw.close();
        }

        std::cout << "Check out " << file_name_out << std::endl;

    }

}



