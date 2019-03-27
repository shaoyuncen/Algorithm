#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>

struct Date{
    int year;
    int month;
    int day;
    int clock;
    int seconds;
    std::unordered_map<int, int> HasDay;
    bool trade;//true is a trade day, false is not.
    Date(int tyear, int tmonth, int tday){
        year = tyear;
        month = tmonth;
        day = tday;
        HasDay[1] = 31;
        HasDay[2] = year % 4 == 0 ? 29 : 28;
        HasDay[3] = 31;
        HasDay[4] = 30;
        HasDay[5] = 31;
        HasDay[6] = 30;
        HasDay[7] = 31;
        HasDay[8] = 31;
        HasDay[9] = 30;
        HasDay[10] = 31;
        HasDay[11] = 30;
        HasDay[12] = 31;
    }
    Date operator+(const int n){
        day = day + n;
        if (day > HasDay[month])
        {
            day -= HasDay[month];
            month++;
            if (month > 12)
            {
                year++;
                month -= 12;
            }
        }
        Date out(this->year, this->month, this->day);
        return out;
    }
    Date operator-(const int n){
        day = day - n;
        if(day<1)
        {
            if(month==1){
                month = 12;
                year--;
            }
            else
                month--;
            day = day + HasDay[month];
        }
        Date out(this->year, this->month, this->day);
        return out;
    }
    bool operator<(const Date& rhs) const{
        if(year==rhs.year)
        {
            if(month == rhs.month)
            {
                return day<rhs.day?true:false;
            }
            else
            {
                if(month<rhs.month)
                    return true;
                return false;
            }
        }
        else
        {
            if(year<rhs.year)
                return true;
            return false;
        }
    }
    bool operator==(const Date& rhs) const
    {
		return(year == rhs.year) && (month == rhs.month) && (day == rhs.day);
    }
    
    void print()
    {
        std::cout << year << "-" << month << "-" << day << ' ' << std::endl;
    }
};
struct HashFunc
{
	std::size_t operator()(const Date &date) const 
	{
		using std::size_t;
		using std::hash;
 
		return ((hash<int>()(date.year)
			^ (hash<int>()(date.month) << 1)) >> 1)
			^ (hash<int>()(date.day) << 1);
	}
};

