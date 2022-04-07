#include <iostream>
#include <ostream>


using namespace std;

struct Node
{
	int deger;     // düðümün sayýsal deðeri
	Node* sonraki; // sonraki düðüme iþaretçi
};

struct LinkedList {

	Node* bas;                // dizinin baþlangýç adresini tutar
	void olustur();		// baþlangýç için gereken tanýmlarý içerir
	void sonaEkle(Node*);
	void basaEkle(Node*);
	void ekle(Node* n, int);     // deðer ve sýra numarasý alarak ekleme yapar
	void guncelle(Node* n, int); // deðer ve sýra numarasý alarak günceller
	void sil(int);           // sýra numarasý alarak silme yapar
	void yazdir();           // liste içeriðini ekrana yazar
	void bosalt();           // listenin bellek alanlarýný iade eder
	int sayac;               // liste kaç eleman olduðunu tutar
};


void LinkedList::olustur()
{
	bas = nullptr;
	this->sayac = 0;

}

void LinkedList::sonaEkle(Node* n)
{
	// sona ekle
	if (bas == nullptr)
	{
		bas = n;
		return;
	}
	Node* tara;
	tara = bas;
	while (tara->sonraki) // tara 'nýn sonraki deðeri null olana kadar döngü
		tara = tara->sonraki;

	tara->sonraki = n;
}

void LinkedList::basaEkle(Node* n)
{
	//basa ekle
	if (bas == nullptr)
		bas = n;
	else
	{
		n->sonraki = bas;
		bas = n;
	}
}

void LinkedList::ekle(Node* n, int index)
{
	if (bas == nullptr)
	{
		bas = n;
		return;
	}
	int dugumsayisi = 0;

	Node* tara;
	tara = bas;

	while (tara)
	{
		// eleman sayýsý bulmak
		dugumsayisi++;
		tara = tara->sonraki;
	}
	tara = bas;


	if (index > dugumsayisi)
	{
		// sona ekler
		this->sonaEkle(n);
	}
	else if (index <= 0)
	{
		// baþa ekler 
		this->basaEkle(n);
	}
	else
	{
		if (bas == nullptr)
		{
			bas = n;
			return;
		}
		// index e göre ekler
		for (int i = 0; i < index - 1; ++i)
			tara = tara->sonraki;

		n->sonraki = tara->sonraki;
		tara->sonraki = n;
	}
	this->sayac = dugumsayisi + 1;
}

void LinkedList::guncelle(Node* n, int index)
{
	Node* tara;
	tara = bas;
	if (bas == nullptr)
	{
		bas = n;
		return;
	}
	if (index <= 0)
	{
		// baþtakini günceller
		n->sonraki = tara->sonraki;
		tara->deger = n->deger;
	}
	else
	{

		for (int i = 0; i < index - 1; ++i)
		{
			if (tara)
			{
				tara = tara->sonraki;
			}
		}
		if (tara)
		{
			if (tara->sonraki)
				n->sonraki = tara->sonraki->sonraki;
			tara->sonraki = n;
		}

	}

}

void LinkedList::sil(int index)
{
	int dugumsayisi = 0;

	Node* tara;
	tara = bas;

	while (tara)
	{
		// eleman sayýsý bulmak
		dugumsayisi++;
		tara = tara->sonraki;
	}
	tara = bas;

	if (bas == nullptr)
		return;

	if (index >= dugumsayisi - 1)
	{// son index silinmeli
		if (tara->sonraki)
		{

			while (tara->sonraki->sonraki)
			{
				tara = tara->sonraki;
			}
		}
		else
		{
			bas = nullptr;
		}
		delete(tara->sonraki);
		tara->sonraki = nullptr;
	}
	else if (index <= 0)
	{
		// baþtakini siler
		bas = bas->sonraki;
	}
	else
	{
		for (int i = 0; i < index; ++i)
			tara = tara->sonraki;
		tara->deger = tara->sonraki->deger;
		tara->sonraki = tara->sonraki->sonraki;
	}
	this->sayac--;

}

void LinkedList::bosalt()
{
	bas = nullptr;
	this->sayac = 0;

}

void LinkedList::yazdir()
{
	Node* tara;
	tara = bas;
	if (!tara)
	{
		cout << "Liste bos!!!" << endl;
		return;
	}
	while (tara)
	{
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}