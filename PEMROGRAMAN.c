//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdio.h>

//Dekalarasi variable global yang di gunakan pada program manjemen keuangan ini:
int p;                                //variabel p            => berfungsi untuk menyimpan masukkan saldo yang di inputkan oleh user
int kategori;                         //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori transaksi yang di lakukan oleh user
int pilihanmasuk;                     //variabel pilihanmasuk => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu login
int pilihanmenu;                      //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu program
int *saldo ;                          //pointer saldo         => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo di kurang dengan adanya proses transaksi secara berulang kali
int harga [10];                       //variabel harga        => berfungsi untuk menyimpan masukkan harga dari transaksi yang di inputkan oleh user pada menu transaksi           
int total;                            //variabel total        => berfungsi untuk menyimpan hasil dari proses pengurangan saldo setelah user melakukan proses transaksi, dimana setelah proses ini variabel total ini akan menyimpan sisa dari saldo terbaru yang di miliki oleh user
int milih;                            //variabel milih        => berfungsi untuk menyimpan pilihan yang dimasukkan oleh user untuk di proses ke switch case pada pemilihan jenis dari transaksi yang ingin di lakukan oleh user pada menu transaksi yang sudahh terdapat pada program
int Det_Transaksi [50];                    //Variabel Det_Transaksi     => berfunsgi untuk menyimpan masukan dari info transaksi yang di masukkan user jika pada melihilan jenis transaksi user memilih kategori lainnya sehingga user di minta untuk memasukkan manual informasi dari transaksi yang di lakukan.
int i;                                //variabel i            => berfungsi untuk menyimpan nilai increment pada proses looping yang terdapat pada fungsi menu,dimana variabel ini akan melakukan pengulangan proses transaksi dengan nilai saldo yang di proses merupakan sisa dari saldo transaksi yang dilakukan oleh user sebelumnya.
char email [50];                      //variabel email        => berfungsi untuk menyimpan inputan email yang dimasukkan oleh user 
char password [50];                   //variabel password     => berfungsi untuk menyimpan inputan password yang dimasukkan oleh user 
char nama [50];                       //variabel nama         => berfungsi untuk menyimpan inputan nama yang dimasukkan oleh user 
char passwordcoba[50];                //variabel passwordcoba => berfungsi untuk menyimpan inputan password dari user yang akan di gunakan untuk mengecek apakah yang sedang login adalah pemilik akun dari program yang sedang berjalan

//Deklarasi fungsi fungsi yang digunkan pada program manajemen keuangan 
void konfirmasi ( char password1);    // Merupakan fungsi yang di gunakan untuk melakukan pengecekkan apakah yang sedang menjalankan program adalah user yang memiliki akun dari program ini , dengan membbuat parameter char password untuk menyimpan inputan password yang dibuat oleh user pada saat pertama kali memasuki program
void menu ();                         // Merupakan fungsi yang di gunakan untuk menampilakan berbagai isi dari MENU , yaitu di dalamnya terdapat menu transaksi dan kaetgori transaksi serta menampilkan pilihan utnuk user melakukan pengecekkan sisa saldo yang di miliki oleh user sendiri

// fungsi main adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){

        // Pada menu awal user akan dimnta untuk memasukkan pilihan untuk masuk ke dalam program, dimana disini terdapat dua pilihan yaitu Login dan SignUp, dimana disetiap pilihan akan mengantarkan user ke masing masing menu dari setiap pilihan tersebut
        pil_masuk:
        printf ("Pilihan Masuk\n");
        printf ("1. Login \n2. SignUp\n");
        printf ("Masukan Pilihan :");
        scanf  ("%d",&pilihanmasuk);

        // menu switch case disini merupakan lanjutan dari pilihan yang di masukkan oleh user sebelumnya, dimana user akan di minta untuk megisi beberapa data yang di butuhkan untuk melakukan proses masuk ke dalam program
        switch (pilihanmasuk)
        {
        //pada case 1 ini program akan menampilakn tampilan seperti berikut ini, dan meminta user untuk mengisi dat ayang sudah di inputkan sebagai pendukung  untuk menu login
        case 1:
            printf   ("\nLogin.....\n=============================\n");
            printf   ("Masukan Email Anda           :");
            scanf    ("%s",&email [50]);
            printf   ("Masukan Passowrd untuk login :");
            scanf    ("%s",&password [50]);
            break;

        //pada case 2 ini program akan menampilakn tampilan seperti berikut ini, dan meminta user untuk mengisi dat ayang sudah di inputkan sebagai pendukung  untuk menu SignUp
        case 2:
            printf   ("\nSignUp....\n==========================\n");
            printf   ("LENGKAPI BIODATA\n");
            printf   ("Buat Email Anda           :");
            scanf    ("%s",&email [50]);
            printf   ("Buat Passowrd untuk login :");
            scanf    ("%s",&password [50]);
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\nSilahkan Memilih Pilihan yang Sudah ada\n=========================================\n");
            //goto masuk; dimana syntax ini akan membawa user kembali ke menu pemilihan metode masuk program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.            
            goto pil_masuk;
            break;
        }
            // Pada bagian ini sistem akan meminta agar user memasukkan nama atau username sebagai inisial pengguna untuk memngakses program selanjutnya
            printf   ("\n==================\n");
            printf   ("TENTUKAN NAMA PENGGUNA\n");
            printf   ("Masukan Nama Pengguna  :");
            scanf    (" %[^\n]",&nama);
            // Pada bagian ini program akan menampilkan ucapan selamat datang untuk pertama kalinya dengan menyertakan username yang sudah di tentukan oleh user pada proses sebelumnya.
            printf   ("\nHALLO %s....\n",nama);
            printf   ("Selamat datang... :)\n");
            printf   ("==================\n");
            
            // pada bagian ini program akan menampilkan menu program yang bisa di akses melalui program manajemen keuangan ini
        pilih:
            puts     ("\nMenu Program");
            puts     ("============");
            puts     ("1. MENU");
            printf   ("Masukan Pilihan Anda :");
            scanf    ("%d",&pilihanmenu);

        // pada switch case bagian ini , disini akan memproses dari inputan yang sudah dimasukkan oleh user pada proses pemiihan pemilihan menu sebelumnya dan mengantarkan program pada fungsi yang merupakan panggilan dari pilihan yang di inputkan oleh user.
        switch (pilihanmenu)
        {
            //pada case 1 ini, program akan memanggil fungsi yang sudah dibuat yaitu fungsi yang bernama void menu();
        case 1:
            menu ();
            break;

            //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");

            //goto pilih; dimana syntax ini akan membawa user kembali ke menu pemilihan program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.
            goto pilih;
            break;
        }
}

// Merupakan fungsi yang di gunakan untuk melakukan pengecekkan apakah yang sedang menjalankan program adalah user yang memiliki akun dari program ini , dengan membbuat parameter char password untuk menyimpan inputan password yang dibuat oleh user pada saat pertama kali memasuki program
void konfirmasi (char password1){
    
    //bagian ini akan menampilkan pilihan dari program yang sedang di akses oleh user
    printf ("Cek Saldo...\n");
    pass:

    // bagian ini akan menampilkan perintah dan meminta user untuk memasukkan ulang password yang sudah di buatnya pada pertama kali login untuk mengkonvirmasi bahwa yang sedang mengakses program ini adalah pemilik akun dari program yang sedang dijalankan,
    printf ("Masukan Password untuk mengetahui Jumlah SALDO Anda :");
    scanf  ("%s",&passwordcoba [50]);

    // melakukan pengecekkan apabila password yang baru saja di masukkan untuk mengkonvirmasi sama dengan password yang di buat pertama kali yang dibuat oleh user, maka proses akan di lanjutkan pada program selanjutnya.
    if (passwordcoba [50] == password1)
    {
        printf ("Password Benar!!");
    }
    // jika password yang di masukan salah , maka program akan menampilakn pemberitahuan pasword salah
    else
    {
        printf ("Password Salah!!");
        //goto pass; syntax ini digunakan untuk mebawa user kembali ke menu masukkan pasword untuk mengkonvirmasi ulang, jadi syntax ini akan terus berulang hingga user memasukkan pasword yang benar dengan password yang dibuat pada saat pertama kali masuk kedalam program
        goto pass;
    }
}

// Merupakan fungsi yang di gunakan untuk menampilakan berbagai isi dari MENU , yaitu di dalamnya terdapat menu transaksi dan kaetgori transaksi serta menampilkan pilihan utnuk user melakukan pengecekkan sisa saldo yang di miliki oleh user sendiri
void menu (){

    //Pada bagian ini user diminta untuk memasukkan jumlah saldo yang di miliki sebagai starter dalam program manajemen keuangan ini
    printf   ("Masukan Saldo :");
    scanf    ("%d",& p);

    //penginisialisain bahwa pointer saldo yang sudah di buat sebelumnya disimpan pada variabel p
    saldo = &p;
      ktgri:
  //pada bagian looping ini , disini berfungsi untuk menjalankan proses dari program manjemen keungan ini, dimana setiap dilakukan proses transaksi atau cek saldo maka yang akan di proses dan di tampilkan adalah saldo terbaru yang merupakan hasil dari proses sebelumnya yang di lakukan oleh user seperti proses transaksi yang dapat merubah banya saldo, sehingga program dapat di jalankan sesuai ekspetasi yang di inginkan oleh penulis programnya
  for(i=0; i<1; i++){
    printf ("pilihan : \n1.Transaksi\n2.CekSaldo\nMasukan Pilihan Anda:");
    scanf  ("%d",&kategori);

    //pada menu switch case bagian ini , merupakan lanjutan proses dari pilihan user yang di inputkan sebelumnya pada pilihan pada MENU program.
    switch (kategori)
    {
        // pada case 1 ini, karena user milih program transaksi maka program akan menampilkan menu kategori dan user akan diminta untuk memilih kategori untuk transaksi yang di lakukan oleh user.
        case 1:
            printf ("Kategori Pengeluaran\n");
            printf ("1. Makanan\n2. Transportasi\n3. Fashion\n4. Rumah Tangga\n5. Pendidikan\n6. Lainnya..\nMasukan Pilihan Anda :");
            scanf  ("%d",&milih);
            switch (milih){    

        //pada case 1 dari menu switch(kategori), memiliki syntax switch case lagi di dalamnya, dimana disini berfungsi untuk meneksekusi inputan dari pilihan yang dimasukkan oleh user pada pilihan kategori transaksi sebelumnya.
        //dalam case 1 ini mengeksekusi perintah jika user memilih kategori makanan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 1:
            printf ("Makanan....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //dalam case 2 ini mengeksekusi perintah jika user memilih kategori Transportasi pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 2:
            printf ("Transportasi....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //dalam case 3 ini mengeksekusi perintah jika user memilih kategori Fashion pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 3:
            printf ("Fashion....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //dalam case 4 ini mengeksekusi perintah jika user memilih kategori Rumah Tangga pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 4:
            printf ("Rumah Tangga....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //dalam case 5 ini mengeksekusi perintah jika user memilih kategori Pendidikan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 5:
            printf ("Pendidikan....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //dalam case 6 ini mengeksekusi perintah jika user memilih kategori Lainnya pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 6:
            printf ("Lainnya....\n");
            printf ("Masukkan Total Transaksi anda :");
            scanf  ("%d",&harga[i]);
            printf ("Masukan Jenis Transaksi :");
            scanf  ("%s",&Det_Transaksi);
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
            break;
        }
        
    //pada case 2 dari menu switch (kategori), karena user memilih menu untuk mengecek saldo maka program akan menampilkan sisa saldo yang dimiliki oleh user saat menu ini di akses
    case 2:
            //pada bagian dimana total digunakan untuk menyimpan dari proses pengurangan saldo dengan jumlah harga transaksi yang di lakukan user
            total = *saldo - harga[i];
          
            // Menampilkan pemberitahuan sisa saldo yang di miliki user pada saat mengakses program
            printf ("Sisa Saldo Anda Adalah  :Rp. %d \n" , total);

            //Pointer saldo akan menyimpan sisa saldo terbaru yang akan di proses kembali apabila ada proses transaksi lagi .
            *saldo = total;

            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untuk memasukan pilihan yang benar, syntax ini akan terus berulang hingga inputan yang dimasukan user benar.
            goto ktgri;
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
    default :
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");
            //goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program, 
            goto ktgri;
    }
  }
}
