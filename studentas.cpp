#include "studentas.h"
#include <algorithm>
#include <numeric>
#include <iostream>

Studentas::Studentas() : exam_(0), galutinis_vid_(0), galutinis_med_(0) {}

Studentas::Studentas(std::istream& is) {
    readStudent(is);
}

Studentas::~Studentas() {
    paz_.clear();
}

std::istream& Studentas::readStudent(std::istream& is) {
    paz_.clear();
    is >> vardas_ >> pavarde_;
    if (!is) return is;

    int pazymys;
    std::vector<int> visi_skaiciai;
    return is;
}

void Studentas::skaiciuotiGalutinius() {
    if (paz_.empty()) {
        galutinis_vid_ = 0.4 * 0 + 0.6 * exam_;
        galutinis_med_ = 0.4 * 0 + 0.6 * exam_;
        return;
    }

    float suma = 0;
    for (int p : paz_) {
        suma += p;
    }
    float vidurkis = suma / paz_.size();
    float mediana = Mediana(paz_);

    galutinis_vid_ = 0.4 * vidurkis + 0.6 * exam_;
    galutinis_med_ = 0.4 * mediana + 0.6 * exam_;
}

float Mediana(std::vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    size_t n = paz.size();
    if (n % 2 == 0) {
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    } else {
        return paz[n / 2];
    }
}
