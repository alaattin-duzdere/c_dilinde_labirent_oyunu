#include <math.h>
#include <stdio.h>

int girdikontrol1();

typedef struct {
  char ad[20];
  int x_koordinati;
  int y_koordinati;
  double uzakligi;
} kisi;

int main(void) {
  int length, width;
  printf("Labirent programina hosgeldiniz.\n");
  printf("lutfen 10-100 arasinda uzunluk degerleri giriniz.");

  printf("\n\n\nLabirentin yuksekligini giriniz :  "); // labirent yukseklgini
                                                       // aldık
  length = girdikontrol1(10, 100);

  printf(
      "\n\n\nLabirentin genisligini giriniz :  "); // labirent genisligini aldık
  width = girdikontrol1(10, 100);

  printf("\n\n\nLabirentte kac kisi var(1-10) : "); // kisi sayisini aldik
  int kisi_sayisi = girdikontrol1(0, 10);

  // kisilerin koordinatlarini aldik
  kisi kisilistesi[kisi_sayisi];
  for (int i = 1; i <= kisi_sayisi; i++) {
    sprintf(kisilistesi[i - 1].ad, "kisi%d", i);
    printf("\n%d. kisinin x konumunu giriniz : ", i);
    kisilistesi[i - 1].x_koordinati = girdikontrol1(0, width);
    printf("%d. kisinin y konumunu giriniz : ", i);
    kisilistesi[i - 1].y_koordinati = girdikontrol1(0, length);
  }
  // koordinatlari yazdirdik
  for (int i = 0; i < kisi_sayisi; i++) {
    printf("\n%s adli kisinin koordinatlari (%d,%d)", kisilistesi[i].ad,
           kisilistesi[i].x_koordinati, kisilistesi[i].y_koordinati);
  }

  // kendi konumumuzu aldik
  printf("\n\nbulundugunuz konumun x koordinatini giriniz : ");
  int self_x = girdikontrol1(0, width);
  printf("bulubdugunuz konumun y koordinatini giriniz : ");
  int self_y = girdikontrol1(0, length);

  // tespit mesafesi aldik
  printf("\nbir tespit mesafesi giriniz : ");
  int target_distance = girdikontrol1(0, 100);

  // mesafe turu sectirdik
  printf("\nmesafe turu seciniz : \n");
  printf("1- Oklid Mesafesi(tavsiye edilir)\n");
  printf("2- Manhattan Mesafesi\n=> ");
  int distance_type;
  distance_type = girdikontrol1(0, 3);
  printf("distance type : %d \n", distance_type);

  // her kisinin mesafesini hesapla
  // oklid mesafesi
  if(distance_type == 1){
    for (int i = 0; i < kisi_sayisi; i++) {
      double distance = sqrt(pow(kisilistesi[i].x_koordinati - self_x, 2) +pow(kisilistesi[i].y_koordinati - self_y, 2));
      kisilistesi[i].uzakligi = distance;
    }
  }
  // manhattan mesafesi
  else if(distance_type == 2){
    for (int i = 0; i < kisi_sayisi; i++) {
      double distance = fabs(kisilistesi[i].x_koordinati - self_x) +fabs(kisilistesi[i].y_koordinati - self_y);
      kisilistesi[i].uzakligi = distance;
    }
  }
  
  // belirtilen target icinde olanlari yazdir
  printf("\nbelirtilen tespit mesafesindeki kisiler: \n");
  for(int i=0;i<kisi_sayisi;i++){
    if(kisilistesi[i].uzakligi<=target_distance){
      printf("%s adli kisi %lf uzakliginda bulunuyor.\n",kisilistesi[i].ad,kisilistesi[i].uzakligi);
    }
  }
  
  // en yakin ve en uzak kisileri yazdir
  int min_uzaklik=100;
  int min_index;
  int max_index;
  int max_uzaklik=0;
  if(kisi_sayisi>1){
    for(int i=0;i<kisi_sayisi;i++){
      if(kisilistesi[i].uzakligi<min_uzaklik && kisilistesi[i].uzakligi<=target_distance){
        min_uzaklik=kisilistesi[i].uzakligi;
        min_index=i;
      }
      if(kisilistesi[i].uzakligi>max_uzaklik && kisilistesi[i].uzakligi<=target_distance){
        max_uzaklik=kisilistesi[i].uzakligi;
        max_index=i;
      }
    }
  }
  printf("\n\nen yakin kisi : %s \nuzakligi : %f \n",kisilistesi[min_index].ad,kisilistesi[min_index].uzakligi);
  printf("\nen uzak kisi : %s \nuzakligi : %f",kisilistesi[max_index].ad,kisilistesi[max_index].uzakligi);



  
  return 0;
}

// girdikontrol fonksiyonu iki parametre alır(min,max) ve girdinin min-max
// araliginda bir sayi olup olmadıgını kontrol eder. Sayet girdi tipi ve
// aralıgı dogruysa girdiyi dondurur.
int girdikontrol1(int min, int max) {
  int exit = 0;
  int result = 0;
  while (exit == 0) {
    if (scanf("%d", &result) == 1) { // girilen degerin sayi oldugu durum
      if (result > min && result < max) {
        // printf("dogru aralikta deger girdiniz");
        return result;
        exit = 1; // girilen deger dogru aralıktaki bir sayi ise donguyu bitirir
      } else {
        printf("hatali veri girisi!!\n");
        printf("lutfen dogru aralikta deger giriniz : ");
        while (getchar() != '\n')
          ; // girilen veriyi temizle
      }
    } else {
      printf("hatali veri girisi!!\n");
      printf("lutfen sayi giriniz : ");
      while (getchar() != '\n')
        ; // girilen veriyi temizle
    }
  }
  printf("fonksiyon bitti");
}