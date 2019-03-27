
#include "dataStruct.h"

class TradeDay
{
    private:
        std::unordered_map<Date, bool, HashFunc> ump;
    public:
    TradeDay();
    void init(const std::vector<Date> &tradeDayList);
    Date getTradeDay(Date time, int offsetDays);
    
};
TradeDay::TradeDay(){
    
}
void TradeDay::init(const std::vector<Date> &tradeDayList)
{
    for(auto tradeDay : tradeDayList)
    {
        ump[tradeDay] = true;
    }
}
Date TradeDay::getTradeDay(Date time, int offsetDays)
{
    time = time + offsetDays;
    bool sig = offsetDays > 0 ? true : false; //forward or back
    while(ump.find(time)==ump.end())//loop when not trade day 
    {
        if(sig)
            time =  time + 1;
        else
            time = time - 1;
    }
    return time;
}

int main()
{
    // Date date(2019, 3, 2);
    // date = date - 2;
    // date.print(); //test

    //test case 

    //trade day
    Date a1(2019, 3, 18);
    Date a2(2019, 3, 21);
    Date a3(2019, 3, 22);
    //not trade day
    Date a4(2019, 3, 19);
    Date a5(2019, 3, 15);
    std::vector<Date> tradeDayList({a1, a2, a3});
    TradeDay td;
    td.init(tradeDayList);
    Date res = td.getTradeDay(a4, 1); //trade day back of a4
    res.print();


    return 0;
}