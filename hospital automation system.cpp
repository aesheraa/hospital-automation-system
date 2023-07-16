


#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>

using namespace std;

void hastaekle();

void hastataburcu();

void ekrana_yazdir(short, char[], char[], short, char[]);

void listeyazdir();

void listeguncelle();

void taburcuolanhasta(short, char[], char[], short, char[]);


int main() {

	int islem = 0;
	char secim;
	do {
		do {
			cout << "islem seciniz 1-hasta ekeleme , 2-hasta taburcu , 3-hasta listeleme";
			cout <<" seciminiz"<< endl;
			cin >> islem;

		}

		while (islem != 1 && islem != 2 && islem != 3);
		cout << endl;
		switch (islem) {
			case 1:
				hastaekle();
				break;
			case 2:
				hastataburcu();
				break;
			case 3:

				listeyazdir();
				break;

		}

		cin.clear();
		cout << " baska islem yapacak misisniz ? (y) seciminiz: "<<endl;
		cin >> secim;
		cout << endl;
	}

	while (secim == 'y' || secim == 'Y');
	return 0;

}

void hastaekle(void) {


	ofstream hastacikti("hastaliste.txt", ios::app);

	cout << " hasta girisi yapiniz / cikis yapmak icin ctrl+Z kullanin" << endl;

	cout << " gerekenler : adsoyad , kan , yas ,telno" << endl;
	cout << " ornek giris : ali atay AB + 40 00000000";

	srand(time(0));

	char adsoyad[15], kan[5], telno[10];
	short yas, hastano = rand() % 1000;

	cout << endl<< hastano<< "  ";
	cin >> adsoyad >> kan >> yas >> telno;
	hastacikti << endl<<hastano<< "  "<< adsoyad<< "  "<< kan << "  "<< yas << "  " <<telno;

	hastacikti.close();
}

void hastataburcu(void) {

	char adsoyad[15], kan[15], telno[10];
	short yas, hastano, sorgu;
	bool kontrol = 0;


	listeyazdir();

	ifstream hastagirdi("hastaliste.txt", ios::in);


	ofstream taburcucikti("temp.txt", ios::trunc);

	cout << " taburcu edilecek hasta no " << endl;
		cin >> sorgu;

		while ( hastagirdi>>hastano>>adsoyad >> kan>> yas>>telno ) {

			if (hastano == sorgu) {

				cout << adsoyad << "isimli hasta bulundu " << endl;
					kontrol = 1;

			}

			else {

				taburcuolanhasta(hastano, adsoyad, kan, yas, telno);
			}
		}

		if (!kontrol)
			cout << "\a " << " taburcu edilmek istenen hasta bulunamadi " << endl;

		else
			listeguncelle();

		hastagirdi.close();
}


void ekranayazdir(short h, char a[], char k[], short y, char t[]) {

	cout << setw(3) << h << setw(15) << a << setw(6) << k << setw(6) << y << setw(15) << t << endl;

}
void listeyazdir( void) {

	char adsoyad[15], kan[5], telno[10];
	short yas, hastano, sorgu;

	ifstream hastagirdi("hataliste.txt", ios::in);

	while (!hastagirdi.eof()) {

		hastagirdi >> hastano >> adsoyad >> kan >> yas >> telno;
		ekranayazdir(hastano, adsoyad, kan, yas, telno);
	}

	hastagirdi.close();

	void listeguncelle(void); {


		char kaydet;

		cout << " hasta taburcu edilsin mi? (y) seciminiz:";
		cin >> kaydet;

		if (kaydet == 'y' || kaydet == 'Y') {

			ifstream stream1("temp.txt"); // kaynak dosya 
			ofstream stream2("hastaliste.txt"); // hedef dosya 


			stream2 << stream1.rdbuf(); // kaynagi hedefe kopyaladi
		}
	}

	void taburcuolanhasta(short h, char a[], char k[], short y, char t[])
	{


		ofstream taburcucikti("temp.txt", ios::app);
		taburcucikti << endl << h << "  " << a << "  " << k << "  " << y << "  " << t;
		taburcucikti.close();

	}

}





