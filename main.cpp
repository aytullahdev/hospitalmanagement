#include<bits/stdc++.h>

int indx = 0;//index number
int ind = 0;
int data = 0;
using namespace std;
//Hospital class
class hospital {

  int paitent = 0, discharged = 0, death = 0;
  public:
      //hospital constructor
    hospital(int a, int b, int c) {

      ifstream myfile("hospital.txt");//get the paitent discharghed and dath data form file;
      myfile >> a >> b >> c;
      paitent += a;//assign the value of paitent from file which saved before;
      discharged += b;//same
      death += c;//same
      indx = a;//last index value of our tabele

      myfile.close();

    }

  void update(string str, int a) {
      //update the vlaue

    if (str == "Paitent" || str == "paitent") {

      paitent += a;

    } else if (str == "discharged" || str == "Discharged") {

      discharged += a;
      paitent -= a;

    } else if (str == "death" || str == "Death") {

      death += a;
      paitent -= a;

    }
    //update the value and save it in hostital.txt for reuse
    ofstream savefile("hospital.txt");
    savefile << paitent << " " << discharged << " " << death;
    savefile.close();
  }
  void show_data() {
     //showing the data
    cout << "Paitent :" << paitent << endl << endl << "Dischargged :" << discharged << endl << endl << "Death :" << death << endl << endl;

  }

};
class HPaitent {
  string name, pn, age;
  public:
      //set up a new paitent detailes
    void setdata() {
      cout << "Enter paitent nicname: ";
      cin >> name;

      cout << "Enter paitent age : ";
      cin >> age;

      cout << "Enter paitent phone number : ";
      cin >> pn;
      system("cls");

    }

  void appdata() {
      //append the paitent.txt file
    fstream patient("paitent.txt", ios::app);
    patient << indx++ << " " << name << " " << age << " " << pn << endl;
    patient.close();
    cout << ++ind << " Data inserted" << endl;

  }
  void show_all() {
    int pindx;
    //show all data from paitent.txt file which save before
    fstream myfile("paitent.txt");
    cout << "----------------------------------------------------" << endl;
    cout << " INDEX |   Name     | AGE        | PHONE            " << endl;
    cout << "----------------------------------------------------" << endl;
    while (myfile >> pindx >> name >> age >> pn) {
      cout << pindx << "          " << name << "        " << age << "         " << pn << endl;
    }
    myfile.close();
  }
  void spaitent(string sname, string sage) {
      //search a paitent wiith name and age;
    int pindx;
    fstream myfile("paitent.txt");
    cout << "----------------------------------------------------" << endl;
    cout << " INDEX |   Name     | AGE        | PHONE            " << endl;
    cout << "----------------------------------------------------" << endl;
    while (myfile >> pindx >> name >> age >> pn) {
      if (name == sname || age == sage) {
        data++;
        cout << pindx << "          " << name << "        " << age << "         " << pn << endl;
      }

    }
    cout << endl << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "             " << data << " data found               " << endl;
    cout << "----------------------------------------------------" << endl;
    data = 0;
    myfile.close();

  }
};

int main() {

  system("Color 0B");
  hospital obj1(0, 0, 0);
  HPaitent pobj;
  printf("\n\n\n\n\n\n");
  printf("     ###  ###  ###     ##    ######           #####      ###########\n");
  printf("     ###  ###  ###     ##  ##      ##        ##   ##     ##       ##\n");
  printf("     ###  ###  ###     ##  ##               ##     ##    ##       ##\n");
  printf("     ###  ###  ###     ##  ##         #### ###########   ##       ##\n");
  printf("     ###  ###  ###     ##  ##      ##      ##        ##  ##       ##\n");
  printf("     ###  ###   ########    #######        ##        ##  ###########\n");
  printf("\n\n\n\n\n\n");
  cout << "Welcome to IIUC Hospital" << endl;
  while (1) {
    int opt, paitent;

    cout << "1)ADD OR UPDATE DATA\n2)SHOW DATA\n3)SEARCH PAITENT\n4)Exit" << endl;
    cin >> opt;
    if (opt == 4) {
      cout << ">>>>>>EXIT>>>>" << endl;
      exit(1);
    } else if (opt == 1) {
      system("CLS");
      cout << "1)ADD PAITENTS 2)ADD DEATH NUMBER 3)ADD DISCHARGED NUMBER 4) BACK" << endl;
      cin >> opt;
      if (opt == 1) {
        ind = 0;
        system("CLS");


          pobj.setdata();
          pobj.appdata();


        obj1.update("paitent", paitent);

      }
      if (opt == 2) {
        system("CLS");

        cout << "New Number of Death paitent :";
        cin >> paitent;
        obj1.update("death", paitent);

      }
      if (opt == 3) {
        system("CLS");
        cout << "New number of discharged paitent : ";
        cin >> paitent;
        obj1.update("discharged", paitent);

      }
      if (opt == 4) {
        system("cls");
        continue;
      }

    } else if (opt == 2) {
      system("CLS");
      cout << "1)SHOW STATISTICS 2) SHOW DETAILES 3)BACK" << endl;
      cin >> opt;
      if (opt == 1) {
        obj1.show_data();
      } else if (opt == 2) {
        pobj.show_all();
      } else {
        system("cls");
        continue;
      }

    } else if (opt == 3) {
      system("cls");
      string name, age;
      cout << "Enter paitent name: ";
      cin >> name;
      cout << "Enter paitent age: ";
      cin >> age;
      system("CLS");
      pobj.spaitent(name, age);
    }

  }

  return 0;
}
