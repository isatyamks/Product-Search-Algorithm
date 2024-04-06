#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Skart
{
private:
    int name;
    

    int price;
    int total_price;
    int bill_number;
    string cus_name;
    string product_name;
    int rating;
    string filter_names;

public:
    void search_button();
    void billing();
    void readdatabase();
    void dispaly_product();


    
    vector<string> myalgo(const string &product_name);
};

string string_lower(string s){
        string result;
        for(const char c:s)
            result+=tolower(c);

        return result;
}
void Skart::search_button()
{
    string product_name;
    cout << "Enter the Product name: ";
    getline(cin,product_name);
    cout << "Searching for product: " << product_name << endl;

    vector<string> result = myalgo(product_name);

    if (result.empty())
    {
        cout << "Product not found." << endl;
    }
    else
    {
        cout << "Found product(s):" << endl;
        for (const auto &entry : result)
        {
            cout << entry << endl;
        }
    }
}

vector<string> Skart::myalgo(const string &product_name)
{
    vector<string> filter_names;

    ifstream file("database.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file: " << "database.csv" << endl;
        return filter_names;
        
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string name;
        while (getline(iss, name, ','))
        {   string t_name=string_lower(name);
            string t_product=string_lower(product_name);
            if (t_name.find(t_product)!=string::npos)
            {
                filter_names.push_back(line);
                break;
            }
        }
    }

    file.close();
    return filter_names;
    cout<<endl;
}

int main()
{
    Skart ob1;
    ob1.search_button();

    return 0;
}
