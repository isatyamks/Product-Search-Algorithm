#include<iostream>
#include<fstream>
using namespace std;


class Skart{

    private:
        int price;
        int total_price;
        int bill_number;
        string cus_name;
        string product_name;
        int rating;




    protected:
        int database;

    public:

    

    void search_button();

    void billing();

    void searchalgo(string);

    void readdatabase();


    void dispaly_product();





};
    void Skart:: readdatabase() {
        ifstream fin("database.csv"); 

        if (!fin.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        string row1, row2;

        getline(fin, row1);
        getline(fin, row2);

        cout << row1 << endl;
        cout << row2 << endl;

        fin.close(); 


    





}
void Skart :: search_button(){




    cout<<"Enter the Product name........";
    cin>>product_name;
    cout<<"Loading....";
    searchalgo(product_name);

}

void Skart ::searchalgo(string product_name){




}


int main()
{
    // cout<<"Welcome to Skart..."<<endl;
    // cout<<"choose Options to proceed!"<<endl;

    // cout<<"[1]--- for Search Button !";
    // cout<<endl;

    Skart ob1;
    ob1.readdatabase();
    



    



    return 0;
}