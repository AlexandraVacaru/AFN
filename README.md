# AFN
Implementare AFN
Pentru a verifica un cuvant intr-un AFN, ne vom folosi de o functie recursivă.
Pentru inceput, avem nevoie de numărul tranzitiilor, starea initiala si starile finale pe care le vom retine intr-un vector.
Ne vom folosi de o structura "triplet",pentru a retine fiecare tranzitie, stare din care pleaca, cea in care ajunge si caracterul.
De asemenea, vom avea si o functie de tip bool ,stare_finala, care sa verifice daca o stare este si stare finala.
Functia recursiva are ca parametrii starea curenta, indicele literei la care am ajuns si cuvantul de intrare. Parcurgem tranzițiile si verificam daca avem tranziție de la starea curenta catre o alta stare, cu litera corespunzatoare indicelui(j). Asadar, vom verifica fiecare litera din cuvantul de intrare, pana cand ajungem la finalul cuvantului, intr-o stare finala. Pentru aceasta verificare ne folosim de variabila ok,care va ramane 0 in caz contrar. (starea in care se termina cuvantul nu este finala,sau nu avem nicio tranzitie pentru o litera din cuvant). 
Daca nu este indeplinita condiția de oprire, apelam aceesi functie cu starea gasita, indicele urmator si acelasi cuvant.

Astfel,in functia main vom citi cuvantul care trebuie verificat,tranzitiile,starea initiala si cele finale. 
Apelam functia recursiva pentru starea initiala, primul caracter si cuvantul pentru verificare. 
De asemenea, avem si un caz particular pentru cuvantul lambda. In acest caz, starea de intrare trebuie sa fie si  stare finala.
