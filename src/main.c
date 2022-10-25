#include <stdio.h>
#include <stdlib.h>

struct inis_pisti_kullanim_sirasi{
    int o_id;
    int u_id;
    int i_sa;
    int gecikme;
    struct inis_pisti_kullanim_sirasi *sD;
}*ilkDugum = NULL, *sonDugum = NULL, *temp, *temp2, *tDugum, *yDugum;

struct kalkis_pisti_kullanim_sirasi{
    int o_id;
    int u_id;
    int t_i_sa;
    int i_sa;
    int gecikme;
    int k_sa;
    struct kalkis_pisti_kullanim_sirasi *sD;
}*k_ilkDugum = NULL, *k_sonDugum = NULL, *k_temp, *k_tDugum;

int eS = 0;
int a=0;
int b=0;
int c=0;
int d=0;
char ucakKodu[5][20] = {"Ucak Adlari", "Ambulans Ucagi", "Savas Ucagi", "Yolcu Ucagi", "Kargo Ucagi"};

void sonaEkle(int v1, int v2, int v3, int v4){
    if (sonDugum == NULL){
        sonDugum = (struct inis_pisti_kullanim_sirasi *)malloc(sizeof(struct inis_pisti_kullanim_sirasi));
        sonDugum->sD = NULL;
        sonDugum->o_id = v1;
        sonDugum->u_id = v2;
        sonDugum->i_sa = v3;
        sonDugum->gecikme = v4;
        ilkDugum = sonDugum;
    }
    else{
        temp = (struct inis_pisti_kullanim_sirasi *)malloc(sizeof(struct inis_pisti_kullanim_sirasi));
        sonDugum->sD = temp;
        temp->o_id = v1;
        temp->u_id = v2;
        temp->i_sa = v3;
        temp->gecikme = v4;
        temp->sD = NULL;
        sonDugum = temp;
    }
    eS++;
}

void k_sonaEkle(int v1, int v2, int v3, int v4, int v5, int v6){
    if (k_sonDugum == NULL){
        k_sonDugum = (struct kalkis_pisti_kullanim_sirasi *)malloc(sizeof(struct kalkis_pisti_kullanim_sirasi));
        k_sonDugum->sD = NULL;
        k_sonDugum->o_id = v1;
        k_sonDugum->u_id = v2;
        k_sonDugum->t_i_sa = v3;
        k_sonDugum->i_sa = v4;
        k_sonDugum->gecikme = v5;
        k_sonDugum->k_sa = v6;
        k_ilkDugum = k_sonDugum;
    }
    else{
        k_temp = (struct kalkis_pisti_kullanim_sirasi *)malloc(sizeof(struct kalkis_pisti_kullanim_sirasi));
        k_sonDugum->sD = k_temp;
        k_temp->o_id = v1;
        k_temp->u_id = v2;
        k_temp->t_i_sa = v3;
        k_temp->i_sa = v4;
        k_temp->gecikme = v5;
        k_temp->k_sa = v6;
        k_temp->sD = NULL;
        k_sonDugum = k_temp;
    }
}

void basaEkle(int v1, int v2, int v3, int v4){
    if (sonDugum == NULL){
        sonDugum = (struct inis_pisti_kullanim_sirasi *)malloc(sizeof(struct inis_pisti_kullanim_sirasi));
        sonDugum->sD = NULL;
        sonDugum->o_id = v1;
        sonDugum->u_id = v2;
        sonDugum->i_sa = v3;
        sonDugum->gecikme = v4;
        ilkDugum = sonDugum;
    }
    else{
        temp = (struct inis_pisti_kullanim_sirasi *)malloc(sizeof(struct inis_pisti_kullanim_sirasi));
        struct inis_pisti_kullanim_sirasi* oncekiBirinci = ilkDugum;
        ilkDugum = temp;
        ilkDugum->sD = oncekiBirinci;
        ilkDugum->o_id = v1;
        ilkDugum->u_id = v2;
        ilkDugum->i_sa = v3;
        ilkDugum->gecikme = v4;
    }
    eS++;
}

void arayaEkle(int v1, int v2, int v3, int v4, int sira){
    if(sira == 0){
        basaEkle(v1, v2, v3, v4);
        return;
    }
    tDugum = ilkDugum;
    int sayac = 0;
    while(tDugum != NULL){
        if(sayac == sira-1)
            break;
        tDugum = tDugum->sD;
        sayac++;
    }
    if(sayac+1 != sira){
        printf("Boyle bir pozisyon yok.");
        return;
    }
    if(tDugum->sD == NULL){
        sonaEkle(v1, v2, v3, v4);
        return;
    }
    temp2 = tDugum->sD;
    temp = (struct inis_pisti_kullanim_sirasi *)malloc(sizeof(struct inis_pisti_kullanim_sirasi));
    temp->o_id = v1;
    temp->u_id = v2;
    temp->i_sa = v3;
    temp->gecikme = v4;
    temp->sD = temp2;
    tDugum->sD = temp;
    eS++;
}

void bastanSil(){
    tDugum = ilkDugum;

    if(tDugum == NULL){
        printf("Kuyruk Bos!\n");
        return;
    }
    else{
        if (tDugum->sD != NULL){
            tDugum = tDugum->sD;
            free(ilkDugum);
            ilkDugum = tDugum;
        }
        else{
            free(ilkDugum);
            ilkDugum = NULL;
            sonDugum = NULL;
        }
        eS--;
    }
}

void k_bastanSil(){
    k_tDugum = k_ilkDugum;

    if(k_tDugum == NULL){
        return;
    }
    else{
        if (k_tDugum->sD != NULL){
            k_tDugum = k_tDugum->sD;
            free(k_ilkDugum);
            k_ilkDugum = k_tDugum;
        }
        else{
            free(k_ilkDugum);
            k_ilkDugum = NULL;
            k_sonDugum = NULL;
        }
    }
}


void sondanSil(){
    temp = ilkDugum;
    while(temp->sD->sD != NULL)
        temp = temp->sD;
    free(temp->sD);
    temp->sD = NULL;
    sonDugum = temp;
    eS--;
}

void aradanSil(int sira){
    tDugum = ilkDugum;
    int sayac = 0;
    if(sira == 0){
        bastanSil();
        return;
    }
    while(tDugum != NULL){
        if(sayac == sira-1)
            break;
        tDugum = tDugum->sD;
        sayac++;
    }
    if(sayac+1 != sira){
        printf("\nGirilen sirada eleman yok.");
        return;
    }
    if(tDugum->sD == NULL){
        sondanSil();
        return;
    }
    temp = tDugum->sD->sD;
    free(tDugum->sD);
    tDugum->sD = temp;
    eS--;
}

void k_yazdir(){
    k_tDugum = k_ilkDugum;
    printf("\n--------------------------------------------------------------------------------------\n");
    printf("oncelik_id  ucak_id  talep_edilen_inis_saati  inis_saati  gecikme_suresi  kalkis_saati\n");
    if(k_tDugum == NULL){
        printf("Kuyruk Bos!\n");
        return;
    }
    while(k_tDugum != k_sonDugum){
        printf("%10d  %7d  %23d  %10d  %13d  %12d\n", k_tDugum->o_id, k_tDugum->u_id, k_tDugum->t_i_sa, k_tDugum->i_sa, k_tDugum->gecikme, k_tDugum->k_sa);
        k_tDugum = k_tDugum->sD;
    }
    if(k_tDugum == k_sonDugum){
        printf("%10d  %7d  %23d  %10d  %13d  %12d\n", k_tDugum->o_id, k_tDugum->u_id, k_tDugum->t_i_sa, k_tDugum->i_sa, k_tDugum->gecikme, k_tDugum->k_sa);
    }
    printf("--------------------------------------------------------------------------------------\n");
}

void guncel(){
    int v1, v2, v3, v4, v5, v6;
    while(k_ilkDugum != NULL){
        k_bastanSil();
    }
    tDugum = ilkDugum;
    tDugum = tDugum->sD;
    while(tDugum->o_id != 100){
        v1 = tDugum->o_id;
        v2 = tDugum->u_id;
        v3 = (tDugum->i_sa) - (tDugum->gecikme);
        v4 = tDugum->i_sa;
        v5 = tDugum->gecikme;
        v6 = (tDugum->i_sa) + 1;
        k_sonaEkle(v1, v2, v3, v4, v5, v6);
        tDugum = tDugum->sD;
    }

    FILE *ou;
    if((ou=fopen("output.txt","w"))==NULL){
        printf("Hata: Output Dosyasi Acilamadi!\n");
        exit(1);
    }
    fprintf(ou,"oncelik_id ucak_id talep_edilen_inis_saati inis_saati gecikme_suresi kalkis_saati\n");
    k_tDugum = k_ilkDugum;
    while(k_tDugum != NULL){
        fprintf(ou,"%d %d %d %d %d %d\n", k_tDugum->o_id, k_tDugum->u_id, k_tDugum->t_i_sa, k_tDugum->i_sa, k_tDugum->gecikme, k_tDugum->k_sa);
        k_tDugum = k_tDugum->sD;
    }
    fclose(ou);
    k_yazdir();
    printf("\nOutput.txt dosyasi guncellendi!\n\n");
}

int bosMu(){
    if (eS == 2)
        return 1;
    else
        return 0;
}

void ee(int o_id, int u_id, int i_sa, int gck, int sayac){
    tDugum = yDugum;
    int i = 1;
    gck++;
    for(;gck < 3; gck++){
        printf("%d ID'li %s, %d. kez, %d saatine ertelenmeye calisiliyor...\n", u_id, ucakKodu[o_id], i, i_sa + i);
        if(tDugum->i_sa > i_sa +  i){
            arayaEkle(o_id, u_id, i_sa + i, gck, sayac + i);
            printf("%d ID'li %s musait olan %d saatine ertelendi!\n", u_id, ucakKodu[o_id], i_sa + i);
            break;
        }
        else{
            if(tDugum->gecikme == 3){
                printf("%d ID'li %s, kuyruktaki %d ID'li ucagin azami gecikme suresine ulasmis olmasi sebebiyle erteleniyor...\n", u_id, ucakKodu[o_id], tDugum->u_id);
            }
            else{
                if(tDugum->o_id < o_id){
                    printf("%d ID'li %s, kuyruktaki %d ID'li oncelikli %s nedeniyle erteleniyor...\n", u_id, ucakKodu[o_id], tDugum->u_id, ucakKodu[tDugum->o_id]);
                }
                else if(tDugum->o_id > o_id){
                    printf("%d ID'li %sna %d saatinde inis izni verilmistir. Daha onceden izni verilmis %d ID'li %s erteleniyor...\n", u_id, ucakKodu[o_id], i_sa + i, tDugum->u_id, ucakKodu[tDugum->o_id]);
                    yDugum = tDugum->sD;
                    a = tDugum->o_id;
                    b = tDugum->u_id;
                    c = tDugum->i_sa;
                    d = tDugum->gecikme;
                    aradanSil(sayac + i);
                    arayaEkle(o_id, u_id, i_sa + i, gck, sayac + i);
                    ee(a, b, c, d, sayac + i);
                    break;
                }
                else{
                    if(tDugum->u_id > u_id){
                        printf("%d ID'li %sna %d saatinde inis izni verilmistir. Daha onceden izni verilmis %d ID'li %s erteleniyor...\n", u_id, ucakKodu[o_id], i_sa + i, tDugum->u_id, ucakKodu[tDugum->o_id]);
                        yDugum = tDugum->sD;
                        a = tDugum->o_id;
                        b = tDugum->u_id;
                        c = tDugum->i_sa;
                        d = tDugum->gecikme;
                        aradanSil(sayac + i);
                        arayaEkle(o_id, u_id, i_sa + i, gck, sayac + i);
                        ee(a, b, c, d, sayac + i);
                        break;
                    }
                    else{
                        printf("%d ID'li %s, kuyruktaki %d ID'li oncelikli %s nedeniyle erteleniyor...\n", u_id, ucakKodu[o_id], tDugum->u_id, ucakKodu[tDugum->o_id]);
                    }
                }
            }
        }
        tDugum = tDugum->sD;
        i++;
    }
    if(gck == 3){
        if(tDugum->i_sa > i_sa + i){
            arayaEkle(o_id, u_id, i_sa + i, gck, sayac + i);
            printf("%d ID'li %s azami gecikme suresine ulasmasi nedeni ile %d saatine ertelenmistir!\n", u_id, ucakKodu[o_id], i_sa + i);
        }
        else{
            if(tDugum->gecikme == 3){
                printf("%d ID'li %nin inis izni, azami gecikmeye ulasan ucaklardan dolayi IPTAL edilmistir. Sabiha Gokcen Havalimani'na yonlendiriliyor!\n", u_id, ucakKodu[o_id]);
            }
            else{
                yDugum = tDugum->sD;
                a = tDugum->o_id;
                b = tDugum->u_id;
                c = tDugum->i_sa;
                d = tDugum->gecikme;
                aradanSil(sayac + i);
                arayaEkle(o_id, u_id, i_sa + i, gck, sayac + i);
                printf("Azami gecikme saatine ulasmasi nedeniyle %d ID'li %sna inis izni verilmistir, %d ID'li %s erteleniyor...\n", u_id, ucakKodu[o_id], b, ucakKodu[a]);
                ee(a, b, c, d, sayac + i);
            }
        }
    }
}

void yui(int o_id, int u_id, int i_sa, int sayac){
    a = tDugum->o_id;
    b = tDugum->u_id;
    c = tDugum->i_sa;
    d = tDugum->gecikme;
    yDugum = tDugum->sD;
    aradanSil(sayac);
    arayaEkle(o_id, u_id, i_sa, 0, sayac);
    printf("%d ID'li %sna %d saati icin inis izni verilmistir, %d ID'li %s erteleniyor....\n", u_id, ucakKodu[o_id], i_sa, b, ucakKodu[a]);
    ee(a, b, c, d, sayac);
}

void yue(int o_id, int u_id, int i_sa, int sayac){
    int gck=0;
    tDugum = tDugum->sD;
    for(gck = 1;gck <= 3;gck++){
        printf("%d ID'li %s, %d saatine ertelenmeye calisiliyor...\n", u_id, ucakKodu[o_id], i_sa + gck);
        if(tDugum->i_sa > i_sa + gck){
            arayaEkle(o_id, u_id, i_sa + gck, gck, sayac + gck);
            printf("%d ID'li %sna, %d saati icin inis izni verilmistir!\n", u_id, ucakKodu[o_id], i_sa + gck);
            break;
        }
        else{
            if(tDugum->o_id < o_id){
                printf("%d ID'li %s kuyruktaki oncelikli %s nedeniyle tekrar erteleniyor...\n", u_id, ucakKodu[o_id], ucakKodu[tDugum->o_id]);
            }
            else if(tDugum->o_id > o_id){
                if(tDugum->gecikme == 3){
                    printf("%d ID'li %s azami gecikme suresine ulastigi icin ertelenemiyor, %d ID'li %s tekrar erteleniyor...\n", tDugum->u_id, ucakKodu[tDugum->o_id], u_id, ucakKodu[o_id]);
                }
                else{
                    printf("%d ID'li %s icin %d saatine inis izni verilmistir, %d ID'li %s erteleniyor...\n", u_id, ucakKodu[o_id], i_sa + gck, tDugum->u_id, ucakKodu[tDugum->o_id]);
                    a = tDugum->o_id;
                    b = tDugum->u_id;
                    c = tDugum->i_sa;
                    d = tDugum->gecikme;
                    yDugum = tDugum->sD;
                    aradanSil(sayac + gck);
                    arayaEkle(o_id, u_id, i_sa + gck, gck, sayac + gck);
                    ee(a, b, c, d, sayac + gck);
                    break;
                }
            }
            else{
                if(tDugum->u_id > u_id){
                    if(tDugum->gecikme == 3){
                        printf("%d ID'li %s azami gecikme suresine ulastigi icin ertelenemiyor, %d ID'li %s tekrar erteleniyor...\n", tDugum->u_id, ucakKodu[tDugum->o_id], u_id, ucakKodu[o_id]);
                    }
                    else{
                        printf("%d ID'li %s icin %d saatine inis izni verilmistir, %d ID'li %s erteleniyor...\n", u_id, ucakKodu[o_id], i_sa + gck, tDugum->u_id, ucakKodu[tDugum->o_id]);
                        a = tDugum->o_id;
                        b = tDugum->u_id;
                        c = tDugum->i_sa;
                        d = tDugum->gecikme;
                        yDugum = tDugum->sD;
                        aradanSil(sayac + gck);
                        arayaEkle(o_id, u_id, i_sa + gck, gck, sayac + gck);
                        ee(a, b, c, d, sayac + gck);
                        break;
                    }
                }
                else{
                    printf("%d ID'li %s tekrar erteleniyor...\n", u_id, ucakKodu[o_id]);
                }
            }
            tDugum = tDugum->sD;
        }
    }
    if(gck == 4){
        printf("%d ID'li %s, azami gecikme suresine ulasildigi icin inis izni verilemeden Sabiha Gokcen Havalimani'na yonlendiriliyorsunuz!\n", u_id, ucakKodu[o_id]);
    }
}

int main()
{
    sonaEkle(-100,-100,-100,-100);
    sonaEkle(100,100,100,100);
    FILE *in;
    int ft=0;
    int o_id=0;
    int u_id=0;
    int i_sa=0;
    int eGck=0;
    int sayac=0;
    int kontrol=2;
    int i=0;
    char abc[10];

    if((in=fopen("input.txt","r"))==NULL){
        printf("Hata: Input Dosyasi Okunamadi!\n");
        exit(1);
    }

    fscanf(in, "%s", abc);
    fscanf(in, "%s", abc);
    fscanf(in, "%s", abc);

    while(!feof(in)){
        ft=u_id;
        fscanf(in, "%d%d%d", &o_id, &u_id, &i_sa);
        if(u_id==ft){
            printf("\nDosya Sonu...");
            break;
        }
        printf("----------------------------Havalimani Ucus Yonetim Sistemi---------------------------\n\n");
        printf("Inis Izni Talep Eden Ucak Bilgileri:\nOncelik ID: %d (%s)\nUcak ID: %d\nTalep Edilen Inis Saati: %d\n\n", o_id, ucakKodu[o_id],u_id, i_sa);

        if(bosMu() == 1){
            arayaEkle(o_id, u_id, i_sa, 0, 1);
            printf("%d ID'li %sna %d saatine inis izni verilmistir!\n", u_id, ucakKodu[o_id], i_sa);
        }
        else if(eS == 26){
            int kontrol2=0;
            sayac = 0;
            tDugum = ilkDugum;
            while(tDugum != NULL){
                if((o_id < tDugum->o_id) && (i_sa <= tDugum->i_sa)){
                    int yisa = tDugum->i_sa;
                    aradanSil(sayac);
                    arayaEkle(o_id, u_id, yisa, (yisa-i_sa), sayac);
                    printf("%ID'li %s, acil inis yapmasi gereken %d ID'li %s nedeniyle inis izniniz iptal edilmistir. Inis icin Sabiha Gokcen Havalimani'na yonlendiriliyor!\n", tDugum->u_id, ucakKodu[tDugum->o_id], u_id, ucakKodu[tDugum->o_id]);
                    break;
                }
                else{
                    kontrol2=1;
                }
                tDugum = tDugum->sD;
                sayac++;
            }
            if(kontrol2 == 1)
                printf("%d ID'li %sna, inis pistinde uygun yer olmadigi icin inis izni verilememistir!\n", u_id, o_id);
        }
        else{
            sayac = 0;
            tDugum = ilkDugum;
            while(tDugum != NULL){
                if(tDugum->i_sa == i_sa){
                    kontrol=1;
                    break;
                }
                else{
                    kontrol=0;
                }
                tDugum = tDugum->sD;
                sayac++;
            }
            if(kontrol == 1){
                if(tDugum->o_id < o_id){
                    yue(o_id, u_id, i_sa, sayac);
                }
                else if(tDugum->o_id > o_id){
                    eGck = tDugum->gecikme;
                    if(eGck == 3){
                        printf("Ertelenmesi gereken %d ID'li %snin azami gecikme saatine ulasmasi nedeniyle, %d ID'li %s erteleniyor...\n", tDugum->u_id, ucakKodu[tDugum->o_id], u_id, ucakKodu[o_id]);
                        yue(o_id, u_id, i_sa, sayac);
                    }
                    else{
                        yui(o_id, u_id, i_sa, sayac);
                    }
                }
                else{
                    if(tDugum->u_id > u_id){
                        eGck = tDugum->gecikme;
                        if(eGck == 3){
                            printf("Ertelenmesi gereken %d ID'li %snin azami gecikme saatine ulasmasi nedeniyle, %d ID'li %s erteleniyor...\n", tDugum->u_id, ucakKodu[tDugum->o_id], u_id, ucakKodu[o_id]);
                            yue(o_id, u_id, i_sa, sayac);
                        }
                        else{
                            yui(o_id, u_id, i_sa, sayac);
                        }
                    }
                    else{
                        yue(o_id, u_id, i_sa, sayac);
                    }
                }
            }
            else{
                tDugum = ilkDugum;
                sayac = 0;
                while(tDugum != NULL){
                    if((tDugum->i_sa < i_sa) && (tDugum->sD->i_sa > i_sa)){
                        arayaEkle(o_id, u_id, i_sa, 0, sayac+1);
                        printf("%d ID'li %s icin %d saatine inis izni verilmistir!\n", u_id, ucakKodu[o_id], i_sa);
                        break;
                    }
                    tDugum = tDugum->sD;
                    sayac++;
                }
            }
        }
        guncel();
        system("pause");
        system("cls");
    }
    fclose(in);
    guncel();
    system("pause");
    return 0;
}
