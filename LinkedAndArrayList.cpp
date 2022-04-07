#include <chrono>
#include <iostream>
#include <string>

#include "LinkedListMain.h"
#include "ArrayListMain.h"

using namespace std;


void EklemeSureOlc(int boyut);

void DusukIndexSilmeSureOlc();

void YuksekIndexSilmeSureOlc();

void DusukIndexGuncellemeSureOlc();
auto Ll = new LinkedList();
auto Al = new ArrayList();
void YuksekIndexGuncellemeSureOlc();

int main()
{
	cout << "Lutfen dizi boyutunu giriniz: \n";
	int boyut = 0;
	cin >> boyut;
	Al->olustur(boyut);
	Ll->olustur();
	cout << "\n" << boyut << " eleman icin " << endl;

	EklemeSureOlc(boyut);
	DusukIndexSilmeSureOlc();
	YuksekIndexSilmeSureOlc();
	DusukIndexGuncellemeSureOlc();
	YuksekIndexGuncellemeSureOlc();
	return 0;
}


void EklemeSureOlc(const int boyut)
{
	cout << "\n\nEkleme sureleri : " << endl;

	auto begin = chrono::high_resolution_clock::now();

	for (int i = 0; i < boyut; ++i)
	{
		const auto n = new Node();
		n->deger = i;
		Ll->ekle(n, i);
	}
	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli listeye " << boyut << " eleman ekleme suresi =>  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();
	for (int i = 0; i < boyut; ++i)
	{
		Al->ekle(i, i);
	}
	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Diziye " << boyut << " eleman ekleme suresi = >  " << newelapsed.count() << "  nano - saniye\n";

}

void DusukIndexSilmeSureOlc()
{
	cout << "\n\nDusuk index ile Silme sureleri : " << endl;


	auto begin = chrono::high_resolution_clock::now();

	Ll->sil(2);
	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli liste 2. index silme suresi =>  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();

	Al->sil(2);

	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Dizi eleman 2. index silme suresi =>  " << newelapsed.count() << "  nano - saniye\n";

}

void YuksekIndexSilmeSureOlc()
{
	cout << "\n\nYuksek index ile Silme sureleri : " << endl;


	auto begin = chrono::high_resolution_clock::now();

	Ll->sil(Ll->sayac - 2);
	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli liste " << Ll->sayac - 2 << ".index silme suresi = >  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();

	Al->sil(Al->sayac - 2);

	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Dizi " << Al->sayac - 2 << ".index silme suresi =>  " << newelapsed.count() << "  nano - saniye\n";

}

void DusukIndexGuncellemeSureOlc()
{
	cout << "\n\nDusuk index ile Guncelleme sureleri : " << endl;

	auto begin = chrono::high_resolution_clock::now();

	const auto n = new Node();
	n->deger = 55555;
	Ll->guncelle(n, 2);

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli liste 2. index guncelleme suresi =>  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();

	Al->guncelle(55555, 2);

	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Dizi 2. index guncelleme suresi =>  " << newelapsed.count() << "  nano - saniye\n";

}

void YuksekIndexGuncellemeSureOlc()
{
	cout << "\n\nYuksek index ile Guncelleme sureleri : " << endl;

	auto begin = chrono::high_resolution_clock::now();

	const auto n = new Node();
	n->deger = 55555;
	Ll->guncelle(n, Ll->sayac - 2);

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli liste " << Ll->sayac - 2 << ". index guncelleme suresi =>  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();

	Al->guncelle(55555, Al->sayac - 2);

	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Dizi " << Al->sayac - 2 << ". index guncelleme suresi =>  " << newelapsed.count() << "  nano - saniye\n";

}


void BosaltmaSureOlc()
{
	cout << "\n\nBosaltma sureleri : " << endl;


	auto begin = chrono::high_resolution_clock::now();

	Ll->bosalt();

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	cout << "\nBagli liste bosaltma suresi =>  " << elapsed.count() << "  nano - saniye\n" << endl;


	auto newbegin = chrono::high_resolution_clock::now();

	Al->bosalt();

	auto newend = chrono::high_resolution_clock::now();
	auto newelapsed = chrono::duration_cast<chrono::nanoseconds>(newend - newbegin);
	cout << "Dizi bosaltma suresi =>  " << newelapsed.count() << "  nano - saniye\n";

}