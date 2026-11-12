# Studentų rezultatų skaičiavimo ir spartos analizės sistema (v1.1)

Ši programa skirta studentų namų darbų ir egzamino rezultatų apdorojimui, galutinio balo (pagal vidurkį arba medianą) skaičiavimui bei studentų rūšiavimui į dvi kategorijas („vargšiukai“ ir „kietiakai“). 

---

## v1.0 (`struct`) ir v1.1 (`class`) spartos palyginimas

Spartos tyrimas atliktas naudojant `std::vector` konteinerį ir 3-iąją dalijimo strategiją (`std::partition`) su skirtingos apimties duomenų failais.

| Įrašų kiekis | Versija ir Architektūra | Nuskaitymas (s) | Rūšiavimas / Skaidymas (s) | Išvedimas (s) | Bendras laikas (s) |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **100 000** | **v1.0** (`struct`) | 0.543 | 0.280 | 0.247 | **1.070** |
| | **v1.1** (`class`) | 0.625 | 0.530 | 0.228 | **1.383** |
| **1 000 000** | **v1.0** (`struct`) | 5.195 | 3.656 | 2.251 | **11.102** |
| | **v1.1** (`class`) | 6.312 | 7.064 | 2.277 | **15.653** |

### Tyrimo išvados
1. **Klasės ir struktūros greičio skirtumas:** Perėjus prie klasių (`class`) su privačiais laukais, geteriais ir seteriais, bendras programos vykdymo laikas šiek tiek padidėjo (pvz., su 1 000 000 įrašų laikas išaugo nuo 11.10 s iki 15.65 s). 
2. **Priežastis:** Metodų iškvietimai ir duomenų apsauga klasėse užima šiek tiek daugiau laiko nei tiesioginis duomenų pasiekimas struktūroje.

