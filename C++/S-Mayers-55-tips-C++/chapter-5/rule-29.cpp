// Rule #29
// Strive to make the program safe with respect to exceptions

#include "tools.h"

class Mutex {};

class Lock
{
    public:
        Lock(Mutex m) {}
};

void unlock(Mutex *m) {}

class Image
{
    public:
        Image(std::istream& imgSrc) {}
};

class PrettyMenu
{
    public:
        void changeBackground(std::istream& imgSrc);

    private:
        Mutex mutex;
        std::shared_ptr<Image> bgImage;
        int imageChanges;
};

void PrettyMenu::changeBackground(std::istream& imgSrc)
{
    Lock ml(mutex);

    bgImage.reset(new Image(imgSrc));

    ++imageChanges;
}

int main()
{

}
