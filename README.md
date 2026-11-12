# Programos veikimo spartos analizė (v1.1)

Ši programa skirta studentų namų darbų ir egzamino rezultatų apdorojimui, galutinio balo (pagal vidurkį arba medianą) skaičiavimui bei studentų rūšiavimui į dvi kategorijas („vargšiukai“ ir „kietiakai“). 

---

## v1.0 (`struct`) ir v1.1 (`class`) spartos palyginimas

Spartos tyrimas atliktas naudojant `std::vector` konteinerį ir 3-iąją dalijimo strategiją (`std::partition`) su skirtingos apimties duomenų failais.

| Įrašų kiekis | Versija | Nuskaitymas (s) | Rūšiavimas / Skaidymas (s) | Išvedimas (s) | Bendras laikas (s) |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **100 000** | **v1.0** (`struct`) | 0.543 | 0.280 | 0.247 | **1.070** |
| | **v1.1** (`class`) | 0.625 | 0.530 | 0.228 | **1.383** |
| **1 000 000** | **v1.0** (`struct`) | 5.195 | 3.656 | 2.251 | **11.102** |
| | **v1.1** (`class`) | 6.312 | 7.064 | 2.277 | **15.653** |

---

## Spartos analizė priklausomai nuo kompiliatoriaus optimizavimo lygio (v1.1)

Tyrimas atliktas su `Studentas` klase, naudojant `std::vector` ir 3-iąją strategiją (`std::partition`).

| Optimizavimo lygis | Įrašų kiekis | Nuskaitymas (s) | Rūšiavimas / Skaidymas (s) | Išvedimas (s) | Bendras laikas (s) | `.exe` failo dydis |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Be flag'ų** | **100 000** | 0.625 | 0.530 | 0.228 | **1.383** | 231 KB |
| | **1 000 000** | 6.312 | 7.064 | 2.277 | **15.653** | 231 KB |
| **`-O1`** | **100 000** | 0.334 | 0.143 | 0.246 | **0.723** | 231 KB |
| | **1 000 000** | 3.406 | 1.748 | 2.287 | **7.441** | 231 KB |
| **`-O2`** | **100 000** | 0.347 | 0.139 | 0.238 | **0.724** | 231 KB |
| | **1 000 000** | 3.494 | 1.715 | 2.342 | **7.551** | 231 KB |
| **`-O3`** | **100 000** | 0.335 | 0.143 | 0.241 | **0.719** | 231 KB |
| | **1 000 000** | 3.431 | 1.806 | 2.328 | **7.565** | 231 KB |

### Tyrimo išvados
1. **Optimizavimo įtaka:** Įjungus bet kurį optimizavimo lygį (`-O1`, `-O2` ar `-O3`), programos veikimo greitis padidėja beveik **du kartus** (pvz., su 1 000 000 įrašų bendras laikas nukrito nuo 15.65 s iki 7.4–7.5 s). Tai įrodo, kaip kompiliatorius pagreitina pasiektą objektinį kodą.
2. **Skirtumai tarp `-O1`, `-O2` ir `-O3`:** Šiame konkrečiame projekte skirtumai tarp skirtingų optimizavimo lygių yra minimalūs, nes pagrindinis pagreitėjimas pasiekiamas jau ties pirmuoju optimizavimo lygiu.
