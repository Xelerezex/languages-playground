// Rule 11
// In operator= check self - assignment

class Bitmap
{
};

class Widget
{
    private:
        Bitmap *pb;
};

Widget& Widget::operator+(const Widget& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    delete pb;
    pb = new Bitmap(*rhs.pb);

    return *this;
}

/*  Variant 2
* Widget& Widget::operator=(const Widget& rhs)
* {
*     Bitmap *pOrig = pb;
*     pb = new Bitmap(*rhs.pb);
*     delete pOrig;
*
*     return *this;
* }
*/

int main()
{

}
