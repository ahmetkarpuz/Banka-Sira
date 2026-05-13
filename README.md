#  Banka Sıra Alım Otomasyonu

Bu proje, bir bankadaki sıra alma sistemini simüle eden C++ tabanlı bir konsol uygulamasıdır. Kullanıcıların TC kimlik numaralarıyla sisteme kayıt olmalarını ve kayıtlı kullanıcıların sıra alabilmelerini sağlar.

##  Öne Çıkan Özellikler
*   **Kayıt Sistemi:** Kullanıcıların TC kimlik numaralarını `tckayit.txt` dosyasına kalıcı olarak kaydeder.
*   **Doğrulama (Validation):** Girilen TC kimlik numarasının 11 hane olup olmadığını kontrol eder.
*   **Sıra Yönetimi:** Sadece kayıtlı kullanıcıların sıra almasına izin verir, kayıtlı olmayanları kayıt ekranına yönlendirir.
*   **Hata Yönetimi:** Üst üste hatalı girişlerde sistem güvenliği için programı sonlandırır.

##  Teknik Detaylar
*   **Dosya İşlemleri:** `ofstream` ile veri yazma ve `ifstream` ile veri okuma (Check mekanizması).
*   **Windows API:** `Sleep()` fonksiyonu ile kullanıcı deneyimi iyileştirmesi.
*   **Döngü Yönetimi:** `while(true)` ve `switch-case` yapılarına alternatif menü mantığı.

##  Kurulum ve Çalıştırma
1. C++ derleyicinizin (MinGW, Visual Studio vb.) kurulu olduğundan emin olun.
2. `bankaFis.cpp` dosyasını derleyin:
   g++ bankaFis.cpp -o bankaFis
3. Programı çalıştırın:
   ./bankaFis
