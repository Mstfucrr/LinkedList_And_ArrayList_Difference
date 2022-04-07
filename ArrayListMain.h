#pragma once
#include <list>
using namespace std;


struct ArrayList {
	int* bas; //dizinin başlangıç adresini tutar
	void olustur(int elemansayisi); //başlangıç için gereken tanımları içerir
	void ekle(int deger, int index);//değer ve sıra numarası alarak ekleme yapar
	void guncelle(int, int);//değer ve sıra numarası alarak günceller
	void sil(int);//sıra numarası alarak silme yapar
	void yazdir();//liste içeriğini ekrana yazar
	void bosalt();//listenin bellek alanlarını iade eder
	int sayac;//liste kaç eleman olduğunu tutar
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
