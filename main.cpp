#include <iostream>

using namespace std;

//multiply string a by factor of b
string opr (string a, int b){
    string output = "";
    while(b--){
        output += a;
    }
    return output;

}

//manipulate string a so that have a length of maxletter
string cleanWord (string a, int maxletter){
    int wordlength = a.length()/7.1;
    int baseMultiplier = maxletter/6;
    string output = "";
    string tab = "\t";

    output = a + opr(tab, baseMultiplier-wordlength);
 
    return output;
}

//similar function to cleanWord
string cleanNumber(int a, int maxtab){
    string output = "";
    string tab = "\t";
    if(a >= 0 && a < 10^6){
        output = to_string(a) + opr(tab, maxtab);
    }else if(a >= 10^6 && a < 10^12){
        output = to_string(a) + opr(tab, maxtab-1);
    }else if(a >= 10^12 && a < 10^18){
        output = to_string(a) + opr(tab, maxtab-2);
    }else if(a >= 10^18 && a < 10^24){
        output = to_string(a) + opr(tab, maxtab-3);
    }

    return output;
}

int main()
{
    char menu;
    long saldo, kredit, debit, jumlah = 0;
    long iRiwayat = 0;
    string riwayatBarang[10000] = {};
    long riwayatHarga[10000] = {};
    long riwayatJumlah[10000] = {};
    long riwayatDebit[10000] = {};
    long riwayatSaldo[10000] = {};

    riwayatBarang[iRiwayat] = "";
    riwayatHarga[iRiwayat] = 0;
    riwayatJumlah[iRiwayat] = 0;
    riwayatDebit[iRiwayat] = 0;
    riwayatSaldo[iRiwayat] = 0;

    cout << "Buku Tabungan \n";
    cout << "\n     Menu\n\n";
    cout << ">b for bantuan\n";
    cout << ">k for kredit\n";
    cout << ">d for debit\n";
    cout << ">s for saldo\n";
    cout << ">r for riwayat\n";
    cout << ">e for exit/keluar\n\n";

    while(menu != 'e'){

        cout << "\n>" ;
        cin >> menu;

        switch(menu){
            case 'b':{
                cout << "\n>b for bantuan\n";
                cout << ">k for kredit\n";
                cout << ">d for debit\n";
                cout << ">s for saldo\n";
                cout << ">r for riwayat\n";
                cout << ">e for exit/keluar\n\n";
                break;}
            case 'k':{
                cout << "\nKredit\n\n";
                cout << "Barang/Pengeluaran lainnya: ";
                cin >> riwayatBarang[iRiwayat];
                cout << "Harga: Rp";
                cin >> kredit;
                riwayatHarga[iRiwayat] = kredit;
                cout << "Jumlah barang: ";
                cin >> jumlah;
                riwayatJumlah[iRiwayat] = jumlah;
                riwayatDebit[iRiwayat] = 0;
                iRiwayat++;
                break;}
            case 'd':{
                cout << "\nDebit\n\n";
                cout << "Jenis Pemasukan: ";
                cin >> riwayatBarang[iRiwayat];
                cout << "Pemasukan: Rp";
                cin >> debit;
                riwayatDebit[iRiwayat] = debit;
                riwayatHarga[iRiwayat] = 0;
                riwayatJumlah[iRiwayat] = 0;
                iRiwayat++;
                break;}
            case 's':{
                cout << "\nSaldo\n\n";
                cout << "Saldo anda: Rp" << saldo <<endl;
                break;}
            case 'r':{
                cout << "\nRiwayat\n\n";
                cout <<"Jenis \t\t\t\t Kredit \t\t\t\t\t\t Debit " << endl;
                cout <<"---------------------------------------------------------------------------------------------------------------------------"<<endl;
                cout <<"No\tPengeluaran/Pemasukan\tHarga\t\tKuantitas\tSub Total\t\tDebit\t\t\tSaldo" <<endl;
                for(int i = 0; i<iRiwayat ; i++){
                    cout << cleanNumber(i+1,1) << cleanWord(riwayatBarang[i], 18) << cleanNumber(riwayatHarga[i],2) << cleanNumber(riwayatJumlah[i],2) << cleanNumber(riwayatHarga[i]*riwayatJumlah[i],3) << cleanNumber(riwayatDebit[i],3) << riwayatSaldo[i] << endl;
                }
                cout << "\n\nSaldo Anda: Rp" << saldo <<endl;
                break;}
            case 'u':{
                cout << "\nUndo Succeed" << endl;
                if(iRiwayat > 0){
                saldo = riwayatSaldo[iRiwayat-1]-riwayatSaldo[iRiwayat-2];
                iRiwayat--;}
                break;}
            case 'e':{
                break;}
            default:{
                cout << "\ninvalid command\n";}
        }

        saldo = saldo + debit;
        saldo = saldo - (kredit*jumlah);

        if(menu != 'u'){
        riwayatSaldo[iRiwayat - 1] = saldo;
        }else{
        saldo = riwayatSaldo[iRiwayat-1];
        }


        kredit = 0; //reset
        debit = 0;  //reset
        jumlah = 0; //reset
    }

    return 0;
}
