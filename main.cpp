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
        string model;
        int price;
        double rating;
        string features;

public:
    void search_button();
    vector<Skart> myalgo(const string &product_name);
    Skart(string="",int=0,double=0.0f,string="");
};

string string_clear(const string &str){
    string res;
    for(const char c:str){
        if(isdigit(c))
        res+=c;

    }
    return res;
}
Skart::Skart(string m,int p,double r,string f)
    :model{m},price{p},rating{r},features{f}{

}
string string_lower(string s) {
    string result;
    for (const char c : s)
        result += tolower(c);

    return result;
}

void Skart::search_button() {
    string product_name;
    cout << "Enter the Product name: ";
    getline(cin, product_name);
    cout << "Searching for product: " << product_name << endl;

    vector<Skart> result = myalgo(product_name);

    if (result.empty()) {
        cout << "Product not found." << endl;
    }
    else {
        cout << "Found product(s):" << endl;
        for (auto &entry : result) {
            cout << "Model: " << entry.model << endl;
            cout << "Price: $" << entry.price << endl;
            cout << "Rating: " << entry.rating << endl;
            cout << "Features: " <<entry.features << endl;
            cout << "---------------------" << endl;
        }
    }
}

vector<Skart> Skart::myalgo(const string &product_name) {
    vector<Skart> found_products;

    ifstream file("database.csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << "database.csv" << endl;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        istringstream iss(line);
        string model, price_str, rating_str, features;
        ;

        getline(iss, model, ',');
        getline(iss, price_str, ',');
        getline(iss, rating_str, ',');

        features=line.substr(line.find('"')+1,line.length()-(line.find('"')+1)-1);


        if (string_lower(model).find(string_lower(product_name)) != string::npos) {
            found_products.emplace_back(model,stoi(string_clear(price_str)),stod(rating_str),features);
        }
    }

    file.close();
    
   return found_products;
}

int main() {
    Skart ob1;
    ob1.search_button();

    return 0;
}
