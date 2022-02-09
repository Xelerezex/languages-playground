#include "tools.h"

struct Plate
{
    char C1;
    int Number;
    char C2;
    char C3;
    int Region;
};

bool operator< (const Plate& l, const Plate& r)
{
    return std::tie(l.C1, l.Number, l.C2, l.C3, l.Region)
         < std::tie(r.C1, r.Number, r.C2, r.C3, r.Region);
}

std::ostream& operator<< (std::ostream& out, const Plate& p)
{
    out << p.C1;
    out << std::setw(3) << std::setfill('0') << p.Number;
    out << p.C2;
    out << p.C3;
    out << std::setw(2) << std::setfill('0') << p.Region;
    return out;
}

bool operator == (const Plate& l, const Plate& r)
{
    return (l.C1 == r.C1)
        && (l.Number == r.Number)
        && (l.C2 == r.C2)
        && (l.C3 == r.C3)
        && (l.Region == r.Region);
}


class PlateGenerator
{
    public:
        Plate GetRandomPlate()
        {
            Plate p;
            p.C1     = Letters[LetterDist(RandEng)];
            p.Number = NumberDist(RandEng);
            p.C2     = Letters[LetterDist(RandEng)];
            p.C3     = Letters[LetterDist(RandEng)];
            p.Region = RegionDist(RandEng);

            return p;
        }
    public:
        const static int N = 12;
        const std::array<char, N> Letters =
        {
            'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y'
        };

        std::default_random_engine RandEng;
        std::uniform_int_distribution<int> LetterDist{0, N - 1};
        std::uniform_int_distribution<int> NumberDist{1, 999};
        std::uniform_int_distribution<int> RegionDist{1, 99};
};

struct PlaterHasher
{
    size_t operator() (const Plate& p) const
    {
        size_t result = p.Number;
        result *= 100;
        result *= p.Region;

        int s1 = p.C1 - 'A';
        int s2 = p.C2 - 'A';
        int s3 = p.C3 - 'A';
        int s  = (s1 * 100 + s2) * 100 + s3;

        result *= 1'000'000;
        result += s;
        return result;
    }
};

int main()
{
    PlateGenerator pg;
    std::set<Plate> s_plates;
    std::unordered_set<Plate, PlaterHasher> h_plates;
    const int N = 1'000'000;

    {
        LOG_DURATION("set");
        for (int i = 0; i < N; ++i)
        {
            s_plates.insert(pg.GetRandomPlate());
        }
        for (int i = 0; i < N; ++i)
        {
            s_plates.find(pg.GetRandomPlate());
        }
    }
    {
        LOG_DURATION("unordered_set");
        for (int i = 0; i < N; ++i)
        {
            h_plates.insert(pg.GetRandomPlate());
        }
        for (int i = 0; i < N; ++i)
        {
            h_plates.find(pg.GetRandomPlate());
        }
    }
}
