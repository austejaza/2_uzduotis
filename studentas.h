#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;
    int exam_;
    double galutinis_vid_;
    double galutinis_med_;

public:
    // konstruktoriai ir desktruktorius
    Studentas();
    Studentas(std::istream& is);
    ~Studentas();

    // geteriai
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline std::vector<int> pazymiai() const { return paz_; }
    inline int egzaminas() const { return exam_; }
    inline double galutinisVidurkis() const { return galutinis_vid_; }
    inline double galutineMediana() const { return galutinis_med_; }

    //seteriai
    void nustatytiVarda(const std::string& v) { vardas_ = v; }
    void nustatytiPavarde(const std::string& p) { pavarde_ = p; }
    void pridetiPazymi(int p) { paz_.push_back(p); }
    void nustatytiEgzamina(int e) { exam_ = e; }
    void isvalytiPazymius() { paz_.clear(); }
    void nustatytiGalutinius(double vid, double med) {
    galutinis_vid_ = vid;
    galutinis_med_ = med;
}

    void skaiciuotiGalutinius();

    std::istream& readStudent(std::istream& is);
};

float Mediana(std::vector<int> paz);

#endif
