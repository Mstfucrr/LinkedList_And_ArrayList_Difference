#pragma once
#include <list>
using namespace std;


struct ArrayList {
	int* bas; //dizinin ba�lang�� adresini tutar
	void olustur(int elemansayisi); //ba�lang�� i�in gereken tan�mlar� i�erir
	void ekle(int deger, int index);//de�er ve s�ra numaras� alarak ekleme yapar
	void guncelle(int, int);//de�er ve s�ra numaras� alarak g�nceller
	void sil(int);//s�ra numaras� alarak silme yapar
	void yazdir();//liste i�eri�ini ekrana yazar
	void bosalt();//listenin bellek alanlar�n� iade eder
	int sayac;//liste ka� eleman oldu�unu tutar
};


inline void ArrayList::olustur(int elemansayisi)
{
	bas = new int[elemansayisi];
	this->sayac = 0;
}

inline void ArrayList::ekle(int deger, int index)
{
	int* tara;
	tara = bas;
	bas = new int[sayac + 1];



	//arr[index] = deger;
	for (int i = sayac - 1; i >= index; --i)
	{
		*(tara + i + 1) = *(tara + i);
	}
	tara[index] = deger;
	bas = tara;


	sayac++;

}

inline void ArrayList::guncelle(int yenideger, int index)
{
	for (int i = 0; i < sayac; ++i)
	{

		if (i == index)
		{
			bas[i] = yenideger;
			return;
		}
	}
}

inline void ArrayList::sil(int index)
{
	for (int i = 0; i < sayac; ++i)
	{

		if (i >= index)
		{
			bas[i] = bas[i + 1];
		}
	}
	sayac--;
}

inline void ArrayList::yazdir()
{
	for (int i = 0; i < sayac; ++i)
	{
		cout << bas[i] << endl;
	}
}

inline void ArrayList::bosalt()
{
	delete[] bas;
	sayac = 0;
}
