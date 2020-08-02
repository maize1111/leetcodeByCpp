#include <bits/stdc++.h>
using namespace std;

string reformatDate(string date)
{
    string Day, Month, Year;
    unordered_map<string, string> days =
        {make_pair("01", "1st"), make_pair("02", "2nd"), make_pair("03", "3rd"), make_pair("04", "4th"), make_pair("05", "5th"), make_pair("06", "6th"), make_pair("07", "7th"), make_pair("08", "8th"), make_pair("09", "9th"), make_pair("10", "10th"),
         make_pair("11", "11th"), make_pair("12", "12th"), make_pair("13", "13th"), make_pair("14", "14th"), make_pair("15", "15th"), make_pair("16", "16th"), make_pair("17", "17th"), make_pair("18", "18th"), make_pair("19", "19th"), make_pair("20", "20th"),
         make_pair("21", "21st"), make_pair("22", "22nd"), make_pair("23", "23rd"), make_pair("24", "24th"), make_pair("25", "25th"), make_pair("26", "6th"), make_pair("27", "7th"), make_pair("28", "8th"), make_pair("29", "29th"), make_pair("30", "30th"),
         make_pair("31", "31st")};
    //{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}
    unordered_map<string, string> months = {make_pair("01", "Jan"), make_pair("02", "Feb"), make_pair("03", "Mar"), make_pair("04", "Apr"), make_pair("05", "May"), make_pair("06", "Jun"), make_pair("07", "Jul"), make_pair("08", "Aug"), make_pair("09", "Sep"), make_pair("10", "Oct"),
                                            make_pair("11", "Nov"), make_pair("12", "Dec")};

    vector<int> blank;
    for (int i = 0; i < date.size(); i++)
    {
        if (date[i] == ' ')
        {
            blank.push_back(i);
        }
    }
    Day = date.substr(0, blank[0]);
    Month = date.substr(blank[0] + 1, blank[1] - blank[0]-1);
    Year = date.substr(blank[1] + 1, date.size() - blank[1]);
    string day,month;
    unordered_map<string, string>::iterator it = days.begin();
    while(it!=days.end()){
        if(it->second==Day){
            day = it->first;
            break;
        }
        it++;
    }
    unordered_map<string, string>::iterator it1 = months.begin();
    while(it1!=months.end()){
        if(it1->second==Month){
            month = it1->first;
            break;
        }
        it1++;
    }

    string res = Year+'-'+month+'-'+day;
    
    return res;
}

int main()
{

    cout << reformatDate("1st Oct 2052") << endl;
    return 0;
}