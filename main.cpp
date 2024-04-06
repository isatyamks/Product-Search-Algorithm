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
    struct Product {
        string model;
        int price;
        double rating;
        string features;
    };

    vector<Product> filter_names;

public:
    void search_button();
    void display_product();
    vector<string> myalgo(const string &product_name);
};

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

    vector<string> result = myalgo(product_name);

    if (result.empty()) {
        cout << "Product not found." << endl;
    }
    else {
        cout << "Found product(s):" << endl;
        for (const auto &entry : result) {
            cout << entry << endl;
        }
    }
}

vector<string> Skart::myalgo(const string &product_name) {
    vector<string> found_products;

    ifstream file("database.csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << "database.csv" << endl;
        return found_products;
    }

    string line;
    getline(file, line); // Read and ignore header

    while (getline(file, line)) {
        istringstream iss(line);
        string model, price_str, rating_str, features;
        double rating;

        getline(iss, model, ',');
        getline(iss, price_str, ',');
        getline(iss, rating_str, ',');
        getline(iss, features, ',');

        rating = stod(rating_str);

        if (string_lower(model).find(string_lower(product_name)) != string::npos) {
            found_products.push_back(line);
        }
    }

    file.close();
    cout<<found_products.line;
    return found_products;
}

void Skart::display_product() {
    cout << "Found products:" << endl;
    for (const auto& product : filter_names) {
        cout << "Model: " << product.model << endl;
        cout << "Price: " << product.price << endl;
        cout << "Rating: " << product.rating << endl;
        cout << "Features: " << product.features << endl;
        cout << "---------------------" << endl;
    }
}

int main() {
    Skart ob1;
    ob1.search_button();

    return 0;
}
