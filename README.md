# DISMAT

Laboratorijske vježbe iz predmeta: Diskretna matematika 1

Labos 1 - Računanje n-tog člana niza pomoću formule i pomoću same rekurzije zadane relacije.
U program se unosi 5 argumenata redom: prvi koeficijent rekurzivne relacije,
                                        drugi koeficijent rekurzivne relacije,
                                        vrijednost nultog člana niza,
                                        vrijednost prvog člana niza,
                                        redni broj traženog člana niza
Program ispisuje traženog člana izračutanog pomoću obje metode.

Labos 2 - Rješavanje problema trgovačkog putnika pomoću pohlepnog i iscrpnog algoritma na potpunom težinskom grafu s n vrhova za kojeg vrijedi da je težina između vrhova s indeksima k i l je,
da ako je k < l, težina brida iznosi (ak + bl)^2 + 1, gdje su a i b cijeli brojevi.
U program se redom unosi parametri: n, a, b.
Program ispisuje duljinu nađenog ciklusa prvo pohlepnim algoritmom pa iscrpnim algoritmom, te ispisuje da li je pohlepni algoritam našao optimalno rješenje.

Labos 3 - Traženje kromatskog broja grafa zadanog datotekom graf.txt u trenutnom direktoriju.
U datoteci graf.txt se nalaze tri retka: 1. redak sadrži broj vrhova grafa n, 2. redak sadrži broj elemenata skupa S, 3. redak sadrži elemente skupa S odvojenih razmakom.
Skup S predstavlja podskup svih cijelih brojeva počinjući od 1 pa do n - 1.
Za graf također vrijedi da su vrhovi susjedni ako je apsolutna vrijednost razlike indexa dva vrha sadržana u skupu S.
Program ispisuje kromatski broj zadanog grafa.
