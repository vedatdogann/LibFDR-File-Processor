# Proje Adı: LibFDR FİLE PROCESSOR

## Amaç:
Bu projede, veri dosyasından okunan komutlara göre çıkış dosyası oluşturan bir programı C dilinde geliştirmek amaçlanmıştır. Program, giriş dosyasındaki komutları işleyerek belirtilen özel karakterler ve komutlar doğrultusunda çıktı dosyasını üretir. Komutların anlamları: 
yaz: Rakam karakter-> Rakam adedince karakterden basar.
sil: Rakam karakter-> bulunan noktadan geri doğru tarar, istenen karakterlerden bulduğunu adedince siler. Aradığından yeterince bulamazsa başa kadar gider, bulamadım diye dönüş yapar.
sonagit: Rakam karakter-> Dosyanın sonuna gider
dur: Rakam karakter-> tüm komutların icrasından oluşan veriyi dosyaya yazar ve programdan çıkılır.

## ÖZET:
Program Giris.dat’ ı okumaya başlar ve onune gelen komutlara gore işlemler yaparak Sonuc.dat’ sonuçları yazdırır. Bu projede çift yonlu bağıl liste kullanılmıştır. Libfdr kütüphanesi kullanılarak işlemleri kolaylaştırılmıştır.

## İçerik:
Proje aşağıdaki dosyalardan oluşmaktadır:
1. Kaynak dosyalar: *.h, *.c ve *.a dosyaları
2. Makefile: Projenin derlenmesi ve çalıştırılabilir dosyanın oluşturulması için gerekli
3. Örnek giriş ve çıkış dosyaları

## Derleme ve Çalıştırma:
### Gereksinimler:
- GCC veya herhangi bir C derleyici
- "libfdr" kütüphanesi

### Derleme:
Proje dizininde aşağıdaki komutu çalıştırarak projeyi derleyebilirsiniz:
```bash
make


## Örnek Resimler
![libfhoto](https://github.com/vedatdogann/LibFDR-File-Processor/assets/104203746/355c2139-fe3c-4ca6-91c6-003f4f70e640)
![libfdrfhotoo](https://github.com/vedatdogann/LibFDR-File-Processor/assets/104203746/8bbe4919-3f81-4691-8c4b-e142eef7df45)


