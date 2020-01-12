#include<iostream>
#include<fstream>
#include<string> 
#include <malloc.h>
#include <sstream>

using namespace std;

struct node {

	char data;
	struct node *next;
	struct node *prev;
};

struct node* start = NULL;
struct node* temp = NULL;
struct node* current = NULL;

struct node* dugumOlustur(char veri)
{
	struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
	yeniDugum->data = veri;
	yeniDugum->prev = NULL;
	yeniDugum->next = NULL;

	return yeniDugum;
}

void sonaEkle(char veri)
{
	struct node* sonaEklenecek = dugumOlustur(veri);

	if (start == NULL)
	{
		start = sonaEklenecek;
	}

	else
	{
		struct node* temp = start;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		sonaEklenecek->prev = temp;

		temp->next = sonaEklenecek;
	}
}

void basaEkle(int veri)
{
	struct node* basaEklenecek = dugumOlustur(veri);

	if (start == NULL)
	{
		start = basaEklenecek;
		return;
	}

	start->prev = basaEklenecek;
	basaEklenecek->next = start;
	start = basaEklenecek;
}

void bastanSil()
{
	if (start == NULL)
	{
		cout << endl;
		cout<< "Liste zaten bos silme yapilamiyor....";
		return;
	}

	if (start->next == NULL)
	{
		free(start);
		start = NULL;
		return;
	}

	struct node* ikinci = start->next;
	free(start);
	ikinci->prev = NULL;
	start = ikinci;
}

void sondanSil()
{
	if (start == NULL)
	{
		cout << endl;
		cout << "Liste zaten bos silme yapilamiyor...." ;
		return;
	}

	if (start->next == NULL)
	{
		bastanSil();
		return;
	}

	struct node* temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	struct node* onceki = temp->prev;
	free(temp);
	onceki->next = NULL;
}
void yazdir()
{
	struct node* temp = start;

	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
}
void Kontrol()
{
	temp = start;

	while (temp != NULL)
	{

		if (temp->next == NULL )
		{
			if (start->data == temp->data)
			{
				temp = temp->prev;
				bastanSil();
				sondanSil();
				cout << endl;
				yazdir();
				if (start == NULL)
				{
					cout << "Okunan deger polindromdur!!" << endl;
					break;
				}
					
			}
			else
			{ 
				cout << endl;
				cout << "Okunan deger polindrom degildir!!" << endl;
				break;
			}
		}
		else
		{
			cout << temp->data;
			temp = temp->next;
			if (temp->next == NULL)
				cout << temp->data;
		}
	}
}
void Duzenle()
{
	temp = start;

	while (temp != NULL)
	{

		if (temp->next == NULL)
		{
			if (start->data == temp->data)
			{
				temp = temp->prev;
				bastanSil();
				sondanSil();
				cout << endl;
				yazdir();
				if (start == NULL)
				{
					cout << "Okunan deger polindromdur!!" << endl;
					break;
				}

			}
			else
			{
				cout << endl;
				bastanSil();
				yazdir();
				cout << endl;
				basaEkle(temp->data);
				yazdir();
			}
		}
		else
		{
			cout << temp->data;
			temp = temp->next;
			if (temp->next == NULL)
				cout << temp->data;
		}
	}
}

int main()
{
	ifstream dosyaOku("dosya.txt");
	char satir ;

	int secim;

	while (1)
	{
		cout << "--------------------------------" << endl;
		cout << "1- Dosyadan Linked Liste Ekleme" << endl;
		cout << "2- Polindrom Kontrol" << endl;
		cout << "3- Polindrom Duzenle " << endl;
		cout << "4- Listeleme "<<endl;
		cout << "--------------------------------" << endl;
		cin >> secim;

		switch (secim)
		{
		case 1:

			if (dosyaOku.is_open()) {

				while (dosyaOku >> satir) {

					sonaEkle(satir);
				}
			}
			cout << "Dosyadan okuma islemi tamamlandi!!" << endl;
			break;
		case 2:
			Kontrol();
			break;
		case 3:
			Duzenle();
			break;
		case 4:
			yazdir();
			cout << endl;
			break;
		default :
			cout << "Hatali Giris!!!" << endl;
			break;

		}
	}

	dosyaOku.close();

	system("pause");
}